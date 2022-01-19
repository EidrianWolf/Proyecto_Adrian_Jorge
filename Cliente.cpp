//
// Created by jartu on 1/11/2022.
//

#include "Cliente.h"

Cliente::Cliente(string nombre, string id, bool nino, bool embarazada, bool adultoM, int cat):nombre(nombre),
id(id),nino(nino),embarazada(embarazada),adultoM(adultoM),categoria(cat){}

string Cliente::getNombre()const{return nombre;}
void Cliente::setNombre(string nombre){Cliente::nombre=nombre;}
string Cliente::getID()const{return id;}
void Cliente::setID(string id){Cliente::id=id;}
bool Cliente::entraConNino()const{return nino;}
bool Cliente::estaEmbarazada()const{return embarazada;}
bool Cliente::esAdultoMayor()const{return adultoM;}
int Cliente::getCategoria()const{return categoria;}
void Cliente::setCategoria(int cat){categoria=cat;}
string Cliente::toString(){
    stringstream s;
    s<<"Nombre: "<<nombre<<endl<<
    "Identificacion: "<<id<<endl<<
    "Ingresa con nino: "; nino?s<<"Si":s<<"No";
    s<<"\nEsta embarazada: "; embarazada?s<<"Si":s<<"No";
    s<<"\nEs adulto mayor: "; adultoM?s<<"Si":s<<"No";
    s<<"\nCategoria: "<<categoria<<endl;
    return s.str();
}
int Cliente::getPorcentajeInfluencia(){
    int porcentaje=0;
    nino?porcentaje+=20:porcentaje+=0;
    embarazada?porcentaje+=25:porcentaje+=0;
    adultoM?porcentaje+=35:porcentaje+=0;
    if(categoria==1) porcentaje+=20;
    else if(categoria==2) porcentaje+=10;
    return porcentaje;
}

bool Cliente::operator<(Cliente c) {
    return getPorcentajeInfluencia()<c.getPorcentajeInfluencia();
}

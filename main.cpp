#include <iostream>
//Aqui voy a hacer un prototipo del menu, luego hay que pasarlo a la clase de vista y control
using namespace std;
int main() {
    //vista::MenuPrincipal()
    int opc;
    do {
        cout << "Menu principal" << endl;
        cout << "1- Encolar todos los clientes" << endl;
        cout << "2- Encolar un cliente" << endl;
        cout << "3- Atender los siguientes 5 clientes" << endl;
        cout << "4- Mostrar el siguiente cliente a ser atendido" << endl;
        cout << "5- Simulacion de atencion de clientes" << endl;
        cout << "6- Agregar un cliente nuevo" << endl;
        cout << "7- Salir" << endl;
        cout << "Ingrese una opcion:";
        cin >> opc;
        //return opc <- En Vista::MenuPrincipal()

        //Control
        switch (opc) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                cout << "Hasta luego" << endl;
                break;
            default:
                cout << "Esta opcion no esta disponible" << endl;
                break;
        }
    }while(opc!=7);
    return 0;
}

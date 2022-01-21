//
// Created by jartu on 1/19/2022.
//

#ifndef HEAP_TEMPLATE_RUNTIMEEXCEPTION_H
#define HEAP_TEMPLATE_RUNTIMEEXCEPTION_H

#include <iostream>
using namespace std;
class RuntimeException{
private:
    string msg;
public:
    RuntimeException(const string& e);

    string getMessage()const;
};

class QueueException:public RuntimeException{
public:
    QueueException(const string& e);
};

class FileException:public RuntimeException{
public:
    FileException(const string& e);
};
#endif //HEAP_TEMPLATE_RUNTIMEEXCEPTION_H

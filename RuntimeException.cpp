//
// Created by jartu on 1/19/2022.
//

#include "RuntimeException.h"

RuntimeException::RuntimeException(const string& e): msg(e) {}

string RuntimeException::getMessage() const {
    return msg;}

QueueException::QueueException(const string &e) : RuntimeException(e) {}

FileException::FileException(const string &e) : RuntimeException(e) {}


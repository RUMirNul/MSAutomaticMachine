//
// Created by lexac on 22.03.2022.
//
#ifndef UNUQMPAUTOMAT_UTILS_H
#define UNUQMPAUTOMAT_UTILS_H

#include "string"
#include "vector"

using namespace std;

class utils {
public:
    //Разбивает строки на подстроки. Разделительный знак: ' '
    //Возвращает вектор подстрок
    vector<string> pars(string str);

};

#endif //UNUQMPAUTOMAT_UTILS_H
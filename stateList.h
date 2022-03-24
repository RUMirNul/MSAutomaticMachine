//
// Created by lexac on 22.03.2022.
//

#ifndef UNUQMPAUTOMAT_STATELIST_H
#define UNUQMPAUTOMAT_STATELIST_H

#include "state.h"
#include "utils.h"
#include "vector"
#include "string"
#include "iostream"

using namespace std;

class stateList {
private:
    vector<state> stateList;
public:

    //Запись полученных строк переходов в объекты
    //Возвращает bool удалось добавить или нет
    bool write(vector<string> *vs);

    //Поиск нужного перехода по символу строки(цепочки символов) и символу стека
    //Возвращает нужный переход, иначе возвращает переход с параметрами nullptr
    state research(string input, string stk);

private:
    //Добавление перехода в массив переходов
    //Возвращает bool удалось добавить или нет
    bool add(string str);
};

#endif //UNUQMPAUTOMAT_STATELIST_H

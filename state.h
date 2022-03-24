//
// Created by lexac on 22.03.2022.
//
#ifndef UNUQMPAUTOMAT_STATE_H
#define UNUQMPAUTOMAT_STATE_H

#include "string"

using namespace std;

class state {
public:
    state(void);

    //Установка значений объекту
    void set(string in, string stk, string del, string add);

    const string &getInputSymbol() const;


    const string &getStckSymbol() const;


    const string &getDelSymbol() const;


    const string &getAddSymbol() const;


private:
    string inputSymbol;
    string stckSymbol;
    string delSymbol;
    string addSymbol;

};

#endif //UNUQMPAUTOMAT_STATE_H

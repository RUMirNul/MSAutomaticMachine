//
// Created by lexac on 22.03.2022.
//

#include "state.h"

void state::set(string in, string stk, string del, string add) {
    inputSymbol = in;
    stckSymbol = stk;
    delSymbol = del;
    addSymbol = add;
}

const string &state::getInputSymbol() const {
    return inputSymbol;
}

const string &state::getStckSymbol() const {
    return stckSymbol;
}

const string &state::getDelSymbol() const {
    return delSymbol;
}

const string &state::getAddSymbol() const {
    return addSymbol;
}

state::state(void) {
    inputSymbol = "nullptr";
    stckSymbol = "nullptr";
    delSymbol = "nullptr";
    addSymbol = "nullptr";
}

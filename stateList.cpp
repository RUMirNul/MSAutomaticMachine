//
// Created by lexac on 22.03.2022.
//

#include "stateList.h"

void stateList::add(string str) {
    vector<string> temp = (new utils())->pars(str);
    if (temp.size() != 4) {
        cout << "Uncorrected input line of state!\n";
        for (int i = 0; i < temp.size(); ++i) {
            cout << i << ":" << temp.at(i) <<"\n";
        }

        exit(1);
    }
    state tempState;
    tempState.set(temp.at(0), temp.at(1), temp.at(2), temp.at(3));
    stateList.push_back(tempState);
}

void stateList::write(vector<string> *vs) {
    for (int i = 0; i < vs->size(); ++i) {
        add(vs->at(i));
    }
}

state stateList::research(string input, string stk) {
    for (int i = 0; i < stateList.size(); ++i) {
        if (stateList.at(i).getInputSymbol() == input && stateList.at(i).getStckSymbol() == stk) {
            return stateList.at(i);
        }
    }
    return state();
}

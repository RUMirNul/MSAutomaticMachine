//
// Created by lexac on 22.03.2022.
//

#include "stateList.h"

bool stateList::add(string str) {
    //Разбиваем строку на подстроки для получения параметров перехода
    vector<string> temp = (new utils())->pars(str);
    //Проверка, что подстрок 4, как и количество параметров перехода
    if (temp.size() != 4) {
        cout << "Uncorrected input line of state!\n";
        for (int i = 0; i < temp.size(); ++i) {
            cout << i << ":" << temp.at(i) << "\n";
        }
        return false;
    }
    state tempState;
    tempState.set(temp.at(0), temp.at(1), temp.at(2), temp.at(3));
    stateList.push_back(tempState);
    return true;
}

bool stateList::write(vector<string> *vs) {
    for (int i = 0; i < vs->size(); ++i) {
        if (!add(vs->at(i))) {
            cout << "Failed to add a state to the states array!";
            return false;
        }
    }
}

state stateList::research(string input, string stk) {
    for (int i = 0; i < stateList.size(); ++i) {
        if (stateList.at(i).getInputSymbol() == input && stateList.at(i).getStckSymbol() == stk) {
            return stateList.at(i);
        }
    }
    //Если не нашлось нужного перехода, то возвращается переход с параметрами "nullptr"
    return state();
}

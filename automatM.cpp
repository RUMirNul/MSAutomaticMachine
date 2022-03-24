//
// Created by lexac on 22.03.2022.
//

#include "automatM.h"

void automatM::init() {
    stack.push("#");
}

bool automatM::start(vector<string> *str) {
    string inputStr;
    stateList.write(str);
    init();
    cout << "Enter analyse text: ";
    cin >> inputStr;
    cout << "\n";
    setStr(inputStr);
    return analysis();
}

void automatM::setStr(const string &str) {
    automatM::str = str;
}

bool automatM::analysis() {
    for (int i = 0; i < str.size(); ++i) {
        state tempState = stateList.research(str.substr(i, 1), stackGet());
        if (str.at(i) == '|') {
            if (stackGet() == "#") {
                //cout << "Correct!\n";
                return true;
            } else {
                cout << "Uncorrected character chain\n";
                return false;
                exit(2);
            }
        }
        if (tempState.getDelSymbol() != "?") {
            if (stackGet() != "#") {
                stackDel();
            } else {
                cout << "Uncorrected character chain\n";
                return false;
                exit(3);
            }
        }
        if (tempState.getAddSymbol() != "?") {
            stackAdd(tempState.getAddSymbol());
        }

    }
    return true;
}

string automatM::stackGet() {
    return stack.top();
}

void automatM::stackDel() {
    if (stack.top() != "#") {
        stack.pop();
    } else {
        cout << "Uncorrected character chain\n";
        exit(4);
    }

}

void automatM::stackReplace(string str) {
    if (stack.top() != "#") {
        stack.top() = str;
    } else {
        cout << "Uncorrected character chain\n";
        exit(5);
    }
}

void automatM::stackAdd(string str) {
    stack.push(str);
}

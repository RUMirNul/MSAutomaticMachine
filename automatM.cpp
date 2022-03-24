//
// Created by lexac on 22.03.2022.
//

#include "automatM.h"

void automatM::init() {
    stack.push("#");
}

bool automatM::start(vector<string> *str, string inputStr) {
    stateList.write(str);
    init();
    setStr(inputStr);
    return analysis();
}

void automatM::setStr(const string &str) {
    automatM::str = str;
}

bool automatM::analysis() {
    string analyzedString = getStr();

    //Проходим по каждому символу строки(цепочки символов)
    for (int i = 0; i < analyzedString.size(); ++i) {
        //Находим нужный нам переход
        state tempState = stateList.research(analyzedString.substr(i, 1), stackGet());
        //Проверка, что нашли нужный переход
        if (tempState.getAddSymbol() == "nullptr") {
            cout << "The desired state was not found!\n";
            return false;
        }
        //Если увидели конечный символ строки(цепочки). То прекращается работа анализатора.
        //Итог ависит от содержимого стека.
        //P.S. Конечный символ '|' не обязателен
        if (analyzedString.at(i) == '|') {
            //Верно - если в стеке остался только символ дна
            if (stackGet() == "#") {
                return true;
            } else {
                return false;
            }
        }
        //Смотрим на найденый переход и какой символ нам надо удалить из стека.
        //Если это '?', то никакой символ удалять не надо
        if (tempState.getDelSymbol() != "?") {
            //Проверка, удалось удалить или нет
            if (!stackDel()) {
                return false;
            }
        }
        //Смотрим на найденый переход и какой символ нам надо добавить в стек.
        //Если это '?', то никакой символ добавлять не надо
        if (tempState.getAddSymbol() != "?") {
            stackAdd(tempState.getAddSymbol());
            continue;
        }

    }
    //После конца проверки строки проверяем, что стек пустой
    return stackGet() == "#";
}

string automatM::stackGet() {
    return stack.top();
}

bool automatM::stackDel() {
    if (stack.top() != "#") {
        stack.pop();
        return true;
    } else {
        cout << "Stack is empty\n";
        return false;
    }

}

bool automatM::stackReplace(string str) {
    if (stack.top() != "#") {
        stack.top() = str;
        return true;
    } else {
        cout << "Stack is empty\n";
        return false;
    }
}

void automatM::stackAdd(string str) {
    stack.push(str);
}

const string &automatM::getStr() const {
    return str;
}

//
// Created by lexac on 22.03.2022.
//
#ifndef UNUQMPAUTOMAT_AUTOMATM_H
#define UNUQMPAUTOMAT_AUTOMATM_H

#include "stack"
#include "stateList.h"
#include "stateList.h"

class automatM {
public:
    //Хранилище переходов
    stateList stateList;

    //Заупск работы автомата
    bool start(vector<string> *str, string inputStr);

private:
    stack<string> stack;
    string str;

    //Инициалиурем стек. Добавялем символ дна '#'
    void init();

    //Анализ строки(цепочки символов) по таблице переходов
    bool analysis();

    //Получение верхнего символа стека
    string stackGet();

    //Удаление верхнего символа стека
    //Возвращает bool удалось удалить или нет
    bool stackDel();

    //Замена верхнего символа стека
    //Возвращает bool удалось заменить или нет
    bool stackReplace(string str);

    //Добавление в стек нового элемента
    void stackAdd(string str);

    const string &getStr() const;

    void setStr(const string &str);
};

#endif //UNUQMPAUTOMAT_AUTOMATM_H


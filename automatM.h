//
// Created by lexac on 22.03.2022.
//

#include "stack"
#include "stateList.h"
#include "stateList.h"

class automatM {
public:
    stateList stateList;

    bool start(vector<string> *str);

    const string &getStr() const;

    void setStr(const string &str);

    bool analysis();

    string stackGet();

    void stackDel();

    void stackReplace(string str);

    void stackAdd(string str);

private:
    stack<string> stack;
    string str;

    void init();

};


//
// Created by lexac on 22.03.2022.
//

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
    void add (string str);
    void write(vector<string> *vs);
    state research(string input, string stk);

};

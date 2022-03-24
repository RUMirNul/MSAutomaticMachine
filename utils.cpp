//
// Created by lexac on 22.03.2022.
//

#include "utils.h"

vector<string> utils::pars(string str) {
    vector<string> answer;
    string temp = "";
    for (int i = 0; i < str.length(); ++i) {
        if (str.at(i) == '\n') return answer;
        if (str.at(i) == ' ') {
            answer.push_back(temp);
            temp = "";
            continue;
        }
        temp += str.at(i);
    }
    if (temp != "") {
        answer.push_back(temp);
    }
    return answer;
}
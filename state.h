//
// Created by lexac on 22.03.2022.
//

#include "string"

using namespace std;

class state {
public:
    state(void);

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



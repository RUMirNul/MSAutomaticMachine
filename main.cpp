#include <iostream>
#include "automatM.h"

using namespace std;

int main() {
    automatM am;
    string temp;
    vector<string> input;

    cout << "Select an input option:\n";
    cout << "0 - manual input || 1 - prepared version\n";
    int i = 0;
    cout << "Enter: ";
    cin >> i;
    cout << "\n";

    if (i == 0) {
        cout << "Enter the states line by line.\n";
        cout << "In the form of \"Visible_character_chains Visible_character_stack Delete_character_is_stack Add_character_in_stack\"\n";
        cout << "If you do not need to remove the symbol from the stack, put \'?\'\n";
        cout << "If you do not need to add a symbol to the stack, put \'?\'";
        cout << "Optional end marker: \'|\'\n";
        cout << "To complete, enter \'#\'\n";
        cout << "Enter states line:\n";
        while (temp != "#") {
            getline(cin, temp);
            if (temp == "#") break;
            input.push_back(temp);
        }
    } else {
        if (i == 1) {
            input = {"( A ? A", "( # ? A", ") A # ?", ") # # ?"};
            cout << "The entered chain:\n";
            for (int j = 0; j < input.size(); j++) {
                cout << input.at(j) << "\n";
            }
        } else {
            cout << "Incorrect input option!\n";
            exit(10);
        }
    }

    if (am.start(&input)) {
        cout << "Correct!";
    }
    return 3228;
}


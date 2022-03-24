#include <iostream>
#include "automatM.h"

using namespace std;

int main() {
    //Создаём объект автомата и переменные, которые передадим в метод для дальнейшей работы
    automatM am;
    string temp;
    vector<string> input;
    //Выбираем способ работы прогруммы 0 - пользовательский ввод || 1 - заготовленный ввод состояний анализа скобок
    cout << "Select an input option:\n";
    cout << "0 - manual entry || 1 - prepared version\n";
    int i = 0;
    cout << "Enter: ";
    cin >> i;
    cout << "\n";

    if (i == 0) {
        cout << "Enter the states line by line.\n";
        cout << "In the form of \"Visible_character_chains Visible_character_stack Delete_character_in_stack Add_character_in_stack\"\n";
        cout << "If you do not need to remove the symbol from the stack, put \'?\'\n";
        cout << "If you do not need to add a symbol to the stack, put \'?\'\n";
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
    //Получаем от пользователя строку(цепочку символов) для анализа
    string inputStr;
    cout << "Enter analyse text: ";
    cin >> inputStr;
    cout << "\n";
    //Передаём в метод вектор переходов и строку(цепочку символов) для аналиа от пользователя
    if (am.start(&input, inputStr)) {
        cout << "Correct!";
    } else {
        cout << "Uncorrected character chain!";
    }
    return 0;
}


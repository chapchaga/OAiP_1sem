#include <iostream>
using namespace std;

void menu() {
    cout << "--------------------------------------------------------" << endl;
    cout << "-            Лабораторная работа №7                    -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-            Выполнил : Стецко Я.Ю.                    -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-                  Задание №1                          -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-  Суть задания : перевести числа из дополнительного   -" << endl;
    cout << "-  кода в обратный                                     -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-                 Вариант 7(22)                        -" << endl;
    cout << "--------------------------------------------------------" << endl;
}

string minusOne(string s) {
    for (int i = s.size() - 1; i >= 1; i--) {
        if (s[i] == '1') {
            s[i] = '0';
            return s;
        } else {
            s[i] = '1'; 
        }
    }
    return s;
}

string reverse(string s) {
    if (s[0] == '0') { 
    return s;
    } else {    
        return minusOne(s);
    }
}

bool isBinary(const string& s) {
    for (char c : s) {
        if (c != '0' && c != '1')
            return false;
    }
    return true;
}

int main() {
    menu();
    while (true) {
        cout << "\n1 - начало программы, 0 - завершение программы: ";
        int choice;
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка ввода, попробуйте ещё раз: ";
        }

        switch (choice) {
            case 1: {
                string s;
                cout << "Введите дополнительный код: ";
                cin >> s;
                if (!isBinary(s)) {
                    cout << "Ошибка! Используйте для ввода только 0 и 1!\n";
                    break; 
                }

                string rev = reverse(s);
                cout << "Обратный код равен: " << rev << endl;
                break;
            }
            case 0:
                cout << "Завершение программы" << endl;
                return 0;
            default:
                cout << "Неверный выбор, введите снова\n";
        }
    }
}
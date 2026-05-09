#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void menu() {
    cout << "--------------------------------------------------------" << endl;
    cout << "-            Лабораторная работа №7                    -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-            Выполнил : Стецко Я.Ю.                    -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-                  Задание №2                          -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-  Суть задания : найти сумму двоичных чисел, заданных -" << endl;
    cout << "-  в естественной форме                                -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-                 Вариант 7(22)                        -" << endl;
    cout << "--------------------------------------------------------" << endl;
}

bool isBinary(const string& s) {
    for (char c : s) {
        if (c != '0' && c != '1') return false;
    }
    return true;
}

string sumReverse(string a, string b) {    
    int n = max(a.size(), b.size());
    a = string(n - a.size(), '0') + a;
    b = string(n - b.size(), '0') + b;

    string result(n, '0');
    int carry = 0;

    for (int i = n - 1; i >= 0; --i) {
        int sum = (a[i]-'0') + (b[i]-'0') + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }

    if (carry) result = '1' + result;
    return result;
}

string straightToReverse(string s) { 
    if (s[0] == '0') return s;
    for (int i = 1; i < s.size(); ++i) s[i] = (s[i] == '0') ? '1' : '0';
    return s;
}

string reverseToStraight(string s) {  
    if (s[0] == '0') return s;
    for (int i = 1; i < s.size(); ++i) s[i] = (s[i] == '0') ? '1' : '0';
    return s;
}

void runProgram() {
    string a, b;

    cout << "Введите первое двоичное число: ";
    cin >> a;
    if (!isBinary(a)) {
        cout << "Ошибка: это не двоичное число!" << endl;
        return;
    }

    cout << "Введите второе двоичное число: ";
    cin >> b;
    if (!isBinary(b)) {
        cout << "Ошибка: это не двоичное число!" << endl;
        return;
    }

    string sum = sumReverse(a, b);
    cout << "Сумма двоичных чисел: " << sum << endl;
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
            case 1:
                runProgram();
                break;
            case 0:
                cout << "Завершение программы" << endl;
                return 0;
            default:
                cout << "Неверный выбор, введите снова\n";
        }
    }
}
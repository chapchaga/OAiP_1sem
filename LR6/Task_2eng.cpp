#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void menu() {
    cout << "\n--------------------------------------------------------\n";
    cout << "-                                                        -\n";
    cout << "-               Лабораторная работа №6                   -\n";
    cout << "-                                                        -\n";
    cout << "-               Выполнил: Стецко Я.Ю.                    -\n";
    cout << "-                                                        -\n";
    cout << "-                    Задание №2                          -\n";
    cout << "-                                                        -\n";
    cout << "- Суть задания: Из текста удалить все символы, не        -\n";
    cout << "- являющиеся буквами, кроме пробелов.                    -\n";
    cout << "-                                                        -\n";
    cout << "----------------------------------------------------------\n";
}

void task() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    string output;

    for (char c : input) {
    if (isalpha(c) || c == ' ') {
            output += c;
        }
    }

    cout << "Результат: " << output << endl;
}

int main() {
    menu();

    while (true) {
        cout << "1 - начало программы, 0 - завершение программы: ";
        int choice;

        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка ввода, попробуйте ещё раз: ";
        }

        cin.ignore(10000, '\n'); 

        switch (choice) {
        case 1:
            task();
            break;
        case 0:
            cout << "Завершение программы" << endl;
            return 0;
        default:
            cout << "Неверный выбор, попробуйте снова." << endl;
        }
    }
}

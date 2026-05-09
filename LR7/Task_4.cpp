#include <iostream>
using namespace std;

void menu() 
{
    cout << "--------------------------------------------------------" << endl;
    cout << "-            Лабораторная работа №7                    -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-            Выполнил : Стецко Я.Ю.                    -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-                  Задание №4                          -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-  Суть задания : делится ли введенное пользователем   -" << endl;
    cout << "-  число на заданное простое.                          -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-                 Вариант 7(22)                        -" << endl;
    cout << "--------------------------------------------------------" << endl;
}   

bool divisibleBy(int n, int k) 
{
    if (n < 0) n = -n;

    int sum = 0;

    while (sum < n) {
        int temp = k;

        while ((sum + (temp << 1)) <= n) {
            temp <<= 1;
        }

        sum += temp;
    }

    return sum == n;
}

void task() 
{
    int number;
    cout << "Введите число: ";
    while (!(cin >> number)) 
{
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Ошибка ввода, попробуйте ещё раз: ";
}

    cout << "\n Результат:\n";
    cout << "3:   " << (divisibleBy(number, 3)   ? "Делится" : "Не делится") << endl;
    cout << "79:  " << (divisibleBy(number, 79)  ? "Делится" : "Не делится") << endl;
    cout << "151: " << (divisibleBy(number, 151) ? "Делится" : "Не делится") << endl;
}

int main() 
{
    menu();
    while (true) {
        cout << "\n1 - начать, 0 - выход: ";
        int choice;

        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка ввода, попробуйте ещё раз: ";
        }

        switch (choice) {
            case 1:
                task();
                break;
            case 0:
                return 0;
            default:
                cout << "Неверный ввод\n";
        }
    }
}
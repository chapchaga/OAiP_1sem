#include <iostream>
using namespace std;

void menu() 
{
    cout << "--------------------------------------------------------" << endl;
    cout << "-            Лабораторная работа №7                    -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-            Выполнил : Стецко Я.Ю.                    -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-                  Задание №5                          -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-  Суть задания : задача с рабами                      -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-                 Вариант 7(22)                        -" << endl;
    cout << "--------------------------------------------------------" << endl;
}

char readYesNo()
{
    char c;
    while (true) {
        cin >> c;
        if (c == 'y' || c == 'Y' || c == 'n' || c == 'N')
            return c;
        cout << "Введите только y или n: ";
    }
}

void task() 
{
    const int numBarrels = 240;
    const int numSlaves = 5;

    cout << "Есть " << numBarrels << " бочек и " << numSlaves << " рабов.\n";
    cout << "Каждая бочка получает уникальный троичный код (0 = не пить, 1 = день 1, 2 = день 2).\n\n";

    int barrel;
    cout << "Введите номер бочки с ядом (1 - " << numBarrels << "): ";
    cin >> barrel;

    if (barrel < 1 || barrel > numBarrels) {
        cout << "Некорректный номер бочки\n";
        return;
    }

    int digits[numSlaves] = {0};
    int temp = barrel;

    for (int i = 0; i < numSlaves; i++) {
        digits[i] = temp % 3;
        temp /= 3;
    }

    cout << "\nПлан для рабов:\n";
    for (int i = 0; i < numSlaves; i++) {
        cout << "Раб " << i + 1 << ": ";
        if (digits[i] == 0) cout << "не пить\n";
        else if (digits[i] == 1) cout << "пить в первый день\n";
        else cout << "пить во второй день\n";
    }

    bool died1[numSlaves] = {false};
    bool died2[numSlaves] = {false};

    cout << "\nВведите результаты эксперимента:\n";
    for (int i = 0; i < numSlaves; i++) {
        cout << "Раб " << i + 1 << " умер в первый день? (y/n): ";
        char resp = readYesNo();
        died1[i] = (resp == 'y' || resp == 'Y');

        if (!died1[i]) {
            cout << "Раб " << i + 1 << " умер во второй день? (y/n): ";
            resp = readYesNo();
            died2[i] = (resp == 'y' || resp == 'Y');
        }
    }

    int poisoned = 0;
    int power = 1;

    for (int i = 0; i < numSlaves; i++) {
        int digit = 0;
        if (died1[i]) digit = 1;
        else if (died2[i]) digit = 2;
        poisoned += digit * power;
        power *= 3;
    }

    cout << "\nРезультаты эксперимента:\n";
    for (int i = 0; i < numSlaves; i++) {
        cout << "Раб " << i + 1 << ": ";
        if (died1[i]) cout << "умер в первый день\n";
        else if (died2[i]) cout << "умер во второй день\n";
        else cout << "выжил\n";
    }

    cout << "\nОтравленная бочка: " << poisoned << endl;
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

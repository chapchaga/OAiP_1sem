#include <iostream>
#include <string>
#include <locale>


using namespace std;

void menu() {
    wcout << L"\n--------------------------------------------------------\n";
    wcout << L"-                                                        -\n";
    wcout << L"-               Лабораторная работа №6                   -\n";
    wcout << L"-                                                        -\n";
    wcout << L"-               Выполнил: Стецко Я.Ю.                    -\n";
    wcout << L"-                                                        -\n";
    wcout << L"-                    Задание №2                          -\n";
    wcout << L"-                                                        -\n";
    wcout << L"- Суть задания: Из текста удалить все символы, не        -\n";
    wcout << L"- являющиеся буквами, кроме пробелов.                    -\n";
    wcout << L"-                                                        -\n";
    wcout << L"-                  Вариант: 7(22)                        -\n";
    wcout << L"----------------------------------------------------------\n";
}

void task() {
    wstring input;
    wcout << L"Введите строку: ";
    getline(wcin, input);

    wstring output;
    for (wchar_t c : input) {
        if (iswalpha(c) || c == L' ') { //оставляю буквы и пробелы
            output += c;
        }
    }

    wcout << L"Результат: " << output << endl;
}

int main() {
    setlocale(LC_ALL, ""); 
    menu();

    while (true) {
        wcout << L"1 - начало программы, 0 - завершение программы: ";
        int choice;
        while (!(wcin >> choice)) {
            wcin.clear();
            wcin.ignore(10000, L'\n');
            wcout << L"Ошибка ввода, попробуйте ещё раз: ";
        }
        wcin.ignore(10000, L'\n');

        switch (choice) {
        case 1:
            task();
            break;
        case 0:
            wcout << L"Завершение программы" << endl;
            return 0;
        default:
            wcout << L"Неверный выбор, введите снова" << endl;
        }
    }
}


#include <iostream>
using namespace std;

bool isDigit(char c) //цифра ли это
{
    return c >= '0' && c <= '9';
}

void readText(char* text, int size) //чтение строки
{
    int i = 0, c;
    while (i < size - 1 && (c = getchar()) != '\n')
        text[i++] = c;
    text[i] = '\0';
}

void getFloat(const char* text, char* result, int size) //поиск числа
{
    int i = 0;   
    int len = 0;  
    result[0] = '\0';

    while (text[i])
    {
        int start = i;
        int digitsBefore = 0;    
        int digitsAfter = 0;

        if (text[i] == '+' || text[i] == '-')
            i++;

        while (isDigit(text[i])) { i++; digitsBefore++; }

        if (digitsBefore > 0 && text[i] == '.')
        {
            i++; // пропускаем точку
            while (isDigit(text[i])) { i++; digitsAfter++; }

            if (digitsAfter > 0)
            {
                len = i - start;
                if (len > size - 1) len = size - 1;
                for (int j = 0; j < len; j++)
                    result[j] = text[start + j];
                result[len] = '\0';
                return;
            }
        }

        if (text[i] != '\0') i++;
    }
}

void task()
{
    const int SIZE = 80;
    char text[SIZE];
    char num[SIZE];

    cout << "Введите строку (до 80 символов):\n";
    readText(text, SIZE);

    if (text[0] == '\0')
    {
        cout << "Ввод пустой.\n";
        return;
    }

    getFloat(text, num, SIZE);

    cout << "Исходная строка: " << text << "\n";
    if (num[0] != '\0')
        cout << "Выделенное число: " << num << "\n";
    else
        cout << "Число с фиксированной точкой не найдено\n";
}

void menu()
{
    std::cout<<" "<<std::endl;
    std::cout <<"------------------------------------------------------------"<<std::endl;
    std::cout <<"-               Лабораторная работа №6                     -"<<std::endl;
    std::cout <<"-                                                          -"<<std::endl;
    std::cout <<"-               Выполнил : Стецко Я.Ю.                     -"<<std::endl;
    std::cout <<"-                                                          -"<<std::endl;
    std::cout <<"-                    Задание №1                            -"<<std::endl;
    std::cout <<"-                                                          -"<<std::endl;
    std::cout <<"- Суть задания : выделить вещественное число из строки     -"<<std::endl;
    std::cout <<"-                                                          -"<<std::endl;
    std::cout <<"-                                                          -"<<std::endl;
    std::cout <<"-                  Вариант: 7(22)                          -"<<std::endl;
    std::cout <<"-                                                          -"<<std::endl;
    std::cout <<"------------------------------------------------------------"<<std::endl;
}

int main()
{
    menu();
    while (true)
    {
        cout << "1-начало программы, 0-завершение программы: ";
        int choice;

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка ввода, попробуйте ещё раз: ";
        }

        cin.ignore(10000, '\n');

        if (choice == 1)
            task();
        else if (choice == 0)
            return 0;
        else
            cout << "Неверный выбор, введите снова\n";
    }
}

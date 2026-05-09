#include <iostream>
#include <cstring>

const size_t BUF = 128;

long my_strlen(const char* s) {  //считает длину строки
    if (!s) return -1;
    const char* p = s;
    long len = 0;
    while (*p) { ++len; ++p; }
    return len;
}

int my_strcmp(const char* s1, const char* s2) {     //сравнение
    if (!s1 || !s2) return 1;
    while (*s1 && *s2) {
        if (*s1 != *s2) return (unsigned char)(*s1) - (unsigned char)(*s2);
        ++s1; ++s2;
    }
    return (unsigned char)(*s1) - (unsigned char)(*s2);
}

bool my_strcpy(char* dest, size_t dest_size, const char* src) {      //копирование
    if (!dest || !src || dest_size == 0) return false;
    size_t i = 0;
    while (src[i] && i + 1 < dest_size) {
        dest[i] = src[i];
        ++i;
    }
    if (i >= dest_size) return false;
    dest[i] = '\0';
    return true;
}

bool my_strcat(char* dest, size_t dest_size, const char* src) {             //объеденеие
    if (!dest || !src || dest_size == 0) return false;
    size_t len = my_strlen(dest);
    size_t i = 0;
    while (src[i] && len + 1 < dest_size) {
        dest[len++] = src[i++];
    }
    if (len >= dest_size) return false;
    dest[len] = '\0';
    return true;
}

void task() {
    char buf1[BUF] = {0};
    char buf2[BUF] = {0};
    char merged[BUF] = {0};

    std::cout << "Введите строку 1: ";
    std::cin.getline(buf1, BUF);

    std::cout << "Введите строку 2: ";
    std::cin.getline(buf2, BUF);

    std::cout << "\nДлина строки 1 = " << my_strlen(buf1) << "\n";
    std::cout << "Длина строки 2 = " << my_strlen(buf2) << "\n";

    int cmp = my_strcmp(buf1, buf2);
    if (cmp == 0) std::cout << "Строки равны\n";
    else if (cmp < 0) std::cout << "Строка 1 < Строка 2\n";
    else std::cout << "Строка 1 > Строка 2\n";

    my_strcpy(merged, BUF, buf1);
    my_strcat(merged, BUF, " ");
    my_strcat(merged, BUF, buf2);

    std::cout << "Результат объединения: \"" << merged << "\"\n";
}

void menu() {
    std::cout<<" "<<std::endl;
    std::cout <<"------------------------------------------------------------"<<std::endl;
    std::cout <<"-               Лабораторная работа №6                     -"<<std::endl;
    std::cout <<"-                                                          -"<<std::endl;
    std::cout <<"-               Выполнил : Стецко Я.Ю.                     -"<<std::endl;
    std::cout <<"-                                                          -"<<std::endl;
    std::cout <<"-                    Задание №3                            -"<<std::endl;
    std::cout <<"-                                                          -"<<std::endl;
    std::cout <<"- Суть задания :сделать сравнение,объединение,копирование  -"<<std::endl;
    std::cout <<"-                                                          -"<<std::endl;
    std::cout <<"-                  Вариант: 7(22)                          -"<<std::endl;
    std::cout <<"-                                                          -"<<std::endl;
    std::cout <<"------------------------------------------------------------"<<std::endl;
}

int main() {
    menu();

    while (true) {
        std::cout << "1-начало программы, 0-завершение программы: ";
        int choice;

        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода, попробуйте ещё раз: ";
        }

        std::cin.ignore(10000, '\n'); 

        if (choice == 1) task();
        else if (choice == 0) break;
        else std::cout << "Неверный выбор, введите снова\n";
    }
}

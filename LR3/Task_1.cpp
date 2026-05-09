#include <iostream>

void Menu() {
    std::cout <<"-----------------------------------------"<<std::endl;
    std::cout <<"-                                       -"<<std::endl;
    std::cout <<"-                                       -"<<std::endl;
    std::cout <<"-       Выполнил : Стецко Я.Ю.          -"<<std::endl;
    std::cout <<"-                                       -"<<std::endl;
    std::cout <<"-   Суть задания : вычислить выражение  -"<<std::endl;
    std::cout <<"-                                       -"<<std::endl;
    std::cout <<"-                                       -"<<std::endl;
    std::cout <<"-----------------------------------------"<<std::endl;
}

void task() {
    int i = 1;
    int answer = 0;

    while (i <= 30) {
        int a = 0;
        int b = 0;

        if (i % 2 == 1) {    
            a = i;
            b = i * i;
        } else {             
            a = i / 2;
            b = i * i * i;
        }

        answer += (a - b) * (a - b);
        std::cout << "Ответ после i = " << i << " : " << answer << std::endl;
        i++;
    }

    std::cout << "\n Итоговый ответ: " << answer << std::endl;
}

int main() {
    Menu();

    while (true) {
        std::cout << "\n1 — начало программы, 0 — завершение программы: " << std::endl;
        int choice;

        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода, попробуйте ещё раз : ";
        }

        switch (choice) {
            case 1:
                task();
                break;

            case 0:
                std::cout << "Завершение программы." << std::endl;
                return 0;

            default:
                std::cout << "Неверный выбор, введите снова. " << std::endl;
        }
    }
}

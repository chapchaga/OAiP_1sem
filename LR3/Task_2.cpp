#include <iostream>
#include <cmath>

void Menu() {
std::cout <<"-----------------------------------------"<<std::endl;
std::cout <<"-                                       -"<<std::endl;
std::cout <<"-                                       -"<<std::endl;
std::cout <<"-       Выполнил : Стецко Я.Ю.          -"<<std::endl;
std::cout <<"-                                       -"<<std::endl;
std::cout <<"-   Суть задания : найти сумму ряда     -"<<std::endl;
std::cout <<"-                                       -"<<std::endl;
std::cout <<"-                                       -"<<std::endl;
std::cout <<"-----------------------------------------"<<std::endl;
}

void Task() {
double d;
int n = 1;
double sum = 0;
double e = pow ( 10, -3);
do {
    d = ( 1 / pow ( 2, n ) ) + ( 1 / pow ( 3, n ) );
    sum += d;
    n++;

} 
while ( d >= e );
    std::cout << "Сумма ряда равна : " << sum;

}

int main() {
    Menu();

    while (true) {
        std::cout << "\n1 — начало программы, 0 — завершение программы: " << std::endl;
        
        int choice;
        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода, попробуйте ещё раз: ";
        }

        switch (choice) {
            case 1:
                Task();
                break;

            case 0:
                std::cout << "Завершение программы." << std::endl;
                return 0;

            default:
                std::cout << "Неверный выбор, введите снова. " << std::endl;
        }
    }
}
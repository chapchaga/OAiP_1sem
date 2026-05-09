#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    long long result = 0;
    long long current = 1;

    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;

        result += static_cast<long long>(a) * current;

        if (i < n - 1) {
            current *= -2;
        }
    }

    std::cout << "Результат: " << result << std::endl;
}

void Menu() {
    std::cout << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "-                                                  -" << std::endl;
    std::cout << "-                                                  -" << std::endl;
    std::cout << "-            Выполнил : Стецко Я.Ю.                -" << std::endl;
    std::cout << "-                                                  -" << std::endl;
    std::cout << "-       Суть задания : вычислить выражение         -" << std::endl;
    std::cout << "-                                                  -" << std::endl;
    std::cout << "-                                                  -" << std::endl;
    std::cout << "-                                                  -" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
}

void task() {
    std::cout << "Введите колво n, затем n целых чисел: " << std::endl;
    solve();
}

int main() {
    Menu();

    while (true) {
        std::cout << "\n1 - начало программы, 0 - завершение программы: " << std::endl;
        int choice;

        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода, попробуйте ещё раз: ";
        }

        switch (choice) {
            case 1:
                task();
                break;

            case 0:
                std::cout << "Завершение программы." << std::endl;
                return 0;

            default:
                std::cout << "Неверный выбор, введите снова: " << std::endl;
        }
    }

    return 0;
}

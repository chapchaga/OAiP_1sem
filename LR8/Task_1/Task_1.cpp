#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Player {
    string country;
    string team;
    string surname;
    string name;
    string patronymic;
    int number;
    int age;
    int height;
    int weight;
};

void menu() {
    cout << "--------------------------------------------------------" << endl;
    cout << "-            Лабораторная работа №8                    -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-            Выполнил : Стецко Я.Ю.                    -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-                  Задание №1                          -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-  Суть задания : информация об участниках спортивных  -" << endl;
    cout << "-  соревнований содержит название страны, название     -" << endl;
    cout << "-  команды, ФИО игрока, игровой номер, возраст, рост и -" << endl;
    cout << "-  вес. Вывести фамилии спортсменов, возраст которых   -" << endl;
    cout << "-  больше 20 лет (сортировка Шелла по убыванию).       -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-                 Вариант 7(22)                        -" << endl;
    cout << "--------------------------------------------------------" << endl;
}

void inputPlayers(Player*& players, int& n) {
    cout << "Введите количество участников: ";
    cin >> n;
    cin.ignore(100000, '\n');

    players = new Player[n];

    for (int i = 0; i < n; i++) {
        cout << "\nИгрок " << i + 1 << ":\n";

        cout << "Страна: ";
        getline(cin, players[i].country);
        cout << "Команда: ";
        getline(cin, players[i].team);
        cout << "Фамилия: ";
        getline(cin, players[i].surname);
        cout << "Имя: ";
        getline(cin, players[i].name);
        cout << "Отчество: ";
        getline(cin, players[i].patronymic);
        cout << "Игровой номер: ";
        cin >> players[i].number;
        cout << "Возраст: ";
        cin >> players[i].age;
        cout << "Рост: ";
        cin >> players[i].height;
        cout << "Вес: ";
        cin >> players[i].weight;
        cin.ignore(100000, '\n');
    }
}

void printPlayers(Player* players, int n) {
    for (int i = 0; i < n; i++) {
        cout << players[i].surname << " "
             << players[i].name << " "
             << players[i].patronymic
             << ", возраст: " << players[i].age
             << ", команда: " << players[i].team << endl;
    }
}

void shellSort(Player* players, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Player temp = players[i];
            int j;
            for (j = i; j >= gap && players[j - gap].age < temp.age; j -= gap) {
                players[j] = players[j - gap];
            }
            players[j] = temp;
        }
    }
}

void saveToFile(Player* players, int n, string filename = "players.txt") {
    ofstream file(filename);

    if (!file) {
        cout << "Ошибка открытия файла" << endl;
        return;
    }

    file << n << endl;

    for (int i = 0; i < n; i++) {
        file << players[i].country << endl;
        file << players[i].team << endl;
        file << players[i].surname << endl;
        file << players[i].name << endl;
        file << players[i].patronymic << endl;
        file << players[i].number << endl;
        file << players[i].age << endl;
        file << players[i].height << endl;
        file << players[i].weight << endl;
    }

    file.close();
}

void loadFromFile(Player*& players, int& n, string filename = "players.txt") {
    ifstream file(filename);

    if (!file) {
        cout << "Файл не найден" << endl;
        return;
    }

    delete[] players;
    players = nullptr;

    file >> n;
    file.ignore(100000, '\n');

    players = new Player[n];

    for (int i = 0; i < n; i++) {
        getline(file, players[i].country);
        getline(file, players[i].team);
        getline(file, players[i].surname);
        getline(file, players[i].name);
        getline(file, players[i].patronymic);

        file >> players[i].number;
        file >> players[i].age;
        file >> players[i].height;
        file >> players[i].weight;
        file.ignore(100000, '\n');
    }

    file.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    menu();

    Player* players = nullptr;
    int n = 0;
    int choice;

    while (true) {
        cout << "\n1 - Ввод данных";
        cout << "\n2 - Показать данные";
        cout << "\n3 - Сортировка";
        cout << "\n4 - Сохранить в файл";
        cout << "\n5 - Загрузить из файла";
        cout << "\n0 - Выход\n";
        cout << "Выбор: ";

        cin >> choice;
        cin.ignore(100000, '\n');

        switch (choice) {
        case 1:
            delete[] players;
            inputPlayers(players, n);
            break;

        case 2:
            if (players)
                printPlayers(players, n);
            else
                cout << "Нет данных" << endl;
            break;

        case 3:
            if (players) {
                shellSort(players, n);
                for (int i = 0; i < n; i++) {
                    if (players[i].age > 20) {
                        cout << players[i].surname << " (" << players[i].age << ")" << endl;
                    }
                }
            } else {
                cout << "Нет данных" << endl;
            }
            break;

        case 4:
            if (players)
                saveToFile(players, n);
            else
                cout << "Нет данных" << endl;
            break;

        case 5:
            loadFromFile(players, n);
            break;

        case 0:
            delete[] players;
            return 0;

        default:
            cout << "Неверный выбор" << endl;
        }
    }
}
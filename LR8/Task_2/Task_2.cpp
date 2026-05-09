#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

void menu() {
    cout << "--------------------------------------------------------" << endl;
    cout << "-                                                      -" << endl;
    cout << "-            Лабораторная работа №8                    -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-            Выполнил : Стецко Я.Ю.                    -" << endl;
    cout << "-                                                      -" << endl;
    cout << "-                  Задание №2                          -" << endl;
    cout << "-                                                      -" << endl;
    cout << "- Суть задания : информация о сотрудниках предприятия  -" << endl;
    cout << "- содержит: Ф.И.О., номер отдела, должность, дату      -" << endl;
    cout << "- начала работы. Вывести списки сотрудников по отделам -" << endl;
    cout << "- в порядке убывания стажа.                            -" << endl;
    cout << "-                                                      -" << endl;
    cout << "--------------------------------------------------------" << endl;
}

union ExtraInfo {
    double salary;
    char phone[20];
};

struct Sotrudnik {
    string name;
    int department;
    string position;
    string startDate;
    ExtraInfo extra;
    bool isSalary;
};

void saveToFile(Sotrudnik* arr, int size, const string& filename) {
    ofstream fout(filename, ios::binary);
    if (!fout) return;

    fout.write((char*)&size, sizeof(size));
    for (int i = 0; i < size; i++) {
        size_t len;

        len = arr[i].name.size();
        fout.write((char*)&len, sizeof(len));
        fout.write(arr[i].name.c_str(), len);

        fout.write((char*)&arr[i].department, sizeof(arr[i].department));

        len = arr[i].position.size();
        fout.write((char*)&len, sizeof(len));
        fout.write(arr[i].position.c_str(), len);

        len = arr[i].startDate.size();
        fout.write((char*)&len, sizeof(len));
        fout.write(arr[i].startDate.c_str(), len);

        fout.write((char*)&arr[i].isSalary, sizeof(arr[i].isSalary));

        if (arr[i].isSalary)
            fout.write((char*)&arr[i].extra.salary, sizeof(double));
        else
            fout.write(arr[i].extra.phone, sizeof(arr[i].extra.phone));
    }
    fout.close();
}

void loadFromFile(Sotrudnik*& arr, int& size, const string& filename) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        arr = nullptr;
        size = 0;
        return;
    }

    fin.read((char*)&size, sizeof(size));
    arr = new Sotrudnik[size];

    for (int i = 0; i < size; i++) {
        size_t len;
        char buffer[256];

        fin.read((char*)&len, sizeof(len));
        fin.read(buffer, len);
        buffer[len] = '\0';
        arr[i].name = buffer;

        fin.read((char*)&arr[i].department, sizeof(arr[i].department));

        fin.read((char*)&len, sizeof(len));
        fin.read(buffer, len);
        buffer[len] = '\0';
        arr[i].position = buffer;

        fin.read((char*)&len, sizeof(len));
        fin.read(buffer, len);
        buffer[len] = '\0';
        arr[i].startDate = buffer;

        fin.read((char*)&arr[i].isSalary, sizeof(arr[i].isSalary));

        if (arr[i].isSalary)
            fin.read((char*)&arr[i].extra.salary, sizeof(double));
        else
            fin.read(arr[i].extra.phone, sizeof(arr[i].extra.phone));
    }
    fin.close();
}

void addSotrudnik(Sotrudnik*& arr, int& size) {
    Sotrudnik e;
    cin.ignore();
    cout << "Введите Ф.И.О.: ";
    getline(cin, e.name);
    cout << "Введите номер отдела: ";
    cin >> e.department;
    cin.ignore();
    cout << "Введите должность: ";
    getline(cin, e.position);
    cout << "Введите дату начала работы (ДД.ММ.ГГГГ): ";
    getline(cin, e.startDate);
    cout << "Выберите тип доп. информации (1 - зарплата, 2 - телефон): ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        e.isSalary = true;
        cout << "Введите зарплату: ";
        cin >> e.extra.salary;
        cin.ignore();
    } else {
        e.isSalary = false;
        cout << "Введите телефон: ";
        cin.getline(e.extra.phone, 20);
    }

    Sotrudnik* newArr = new Sotrudnik[size + 1];
    for (int i = 0; i < size; i++) newArr[i] = arr[i];
    newArr[size++] = e;
    delete[] arr;
    arr = newArr;
}

void viewSotrudniki(Sotrudnik* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << arr[i].name << ", Отдел: " << arr[i].department
             << ", Должность: " << arr[i].position
             << ", Дата начала: " << arr[i].startDate;
        if (arr[i].isSalary) cout << ", Зарплата: " << arr[i].extra.salary;
        else cout << ", Телефон: " << arr[i].extra.phone;
        cout << endl;
    }
}

void deleteSotrudnik(Sotrudnik*& arr, int& size) {
    int index;
    cout << "Введите номер сотрудника для удаления: ";
    cin >> index;
    if (index < 1 || index > size) return;

    Sotrudnik* newArr = new Sotrudnik[size - 1];
    for (int i = 0, j = 0; i < size; i++)
        if (i != index - 1) newArr[j++] = arr[i];
    delete[] arr;
    arr = newArr;
    size--;
}

void editSotrudnik(Sotrudnik* arr, int size) {
    int index;
    cout << "Введите номер сотрудника для редактирования: ";
    cin >> index;
    cin.ignore();
    if (index < 1 || index > size) return;

    cout << "Введите Ф.И.О.: ";
    getline(cin, arr[index - 1].name);
    cout << "Введите номер отдела: ";
    cin >> arr[index - 1].department;
    cin.ignore();
    cout << "Введите должность: ";
    getline(cin, arr[index - 1].position);
    cout << "Введите дату начала работы: ";
    getline(cin, arr[index - 1].startDate);
}

bool cmp(const Sotrudnik& a, const Sotrudnik& b) {
    if (a.department != b.department) return a.department < b.department;
    return a.startDate < b.startDate;
}

void sortByDep(Sotrudnik* arr, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (!cmp(arr[j], arr[j + 1]))
                swap(arr[j], arr[j + 1]);
}

void printByDepartment(Sotrudnik* arr, int size) {
    sortByDep(arr, size);
    for (int i = 0; i < size; i++)
        cout << "Отдел " << arr[i].department << ": " << arr[i].name
             << ", Стаж с " << arr[i].startDate << endl;
}

void task() {
    Sotrudnik* arr = nullptr;
    int size = 0;
    string filename = "sotrudniki.dat";

    loadFromFile(arr, size, filename);
    int choice;
    do {
        cout << "\n1 - Добавить сотрудника\n2 - Просмотр сотрудников\n3 - Удалить сотрудника\n4 - Редактировать сотрудника\n5 - Вывести списки по отделам\n0 - Выход\nВыберите действие: ";
        cin >> choice;
        switch (choice) {
            case 1: addSotrudnik(arr, size); saveToFile(arr, size, filename); break;
            case 2: viewSotrudniki(arr, size); break;
            case 3: deleteSotrudnik(arr, size); saveToFile(arr, size, filename); break;
            case 4: editSotrudnik(arr, size); saveToFile(arr, size, filename); break;
            case 5: printByDepartment(arr, size); break;
        }
    } while (choice != 0);

    delete[] arr;
}

int main() {
    menu();
    while (true) {
        cout << "\n1 - начало программы, 0 - завершение программы: ";
        int choice;
        cin >> choice;
        if (choice == 1) task();
        else if (choice == 0) {
            cout << "Завершение программы\n";
            break;
        }
    }
    return 0;
}
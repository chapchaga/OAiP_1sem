#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void menu() {
    cout << "-------------------------------------------------------------" << endl;
    cout << "-                                                           -" << endl;
    cout << "-               Лабораторная работа №7                      -" << endl;
    cout << "-                                                           -" << endl;
    cout << "-               Выполнил : Стецко Я.Ю.                      -" << endl;
    cout << "-                                                           -" << endl;
    cout << "-                     Задание №3                            -" << endl;
    cout << "-                                                           -" << endl;
    cout << "-    Сложение и вычитание в разных системах счисления       -" << endl;
    cout << "-                                                           -" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

int symbolToNumber(char c) {
    if (isdigit(c)) return c - '0';
    if (isalpha(c)) return toupper(c) - 'A' + 10;
    return -1;
}

char numberToSymbol(int v) {
    if (v < 10) return '0' + v;
    return 'A' + (v - 10);
}

bool absLess(const string &a, const string &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

bool isValidNumber(const string &num, int base) {
    int start = (num[0] == '-') ? 1 : 0;
    if (start == num.size()) return false;

    for (int i = start; i < num.size(); i++) {
        char c = num[i];

        if (!isdigit(c) && !isalpha(c)) return false;

        int val = symbolToNumber(c);
        if (val < 0 || val >= base) return false;

        if (isalpha(c) && base <= 10) return false;
    }
    return true;
}

string addPlusNumber(const string &a, const string &b, int base) {
    string r;
    int carry = 0;
    int n1 = a.size(), n2 = b.size();

    for (int i = 0; i < max(n1, n2); i++) {
        int da = i < n1 ? symbolToNumber(a[n1 - 1 - i]) : 0;
        int db = i < n2 ? symbolToNumber(b[n2 - 1 - i]) : 0;
        int s = da + db + carry;
        carry = s / base;
        r.push_back(numberToSymbol(s % base));
    }
    if (carry) r.push_back(numberToSymbol(carry));
    reverse(r.begin(), r.end());
    return r;
}

string subtractPlusNumber(const string &a, const string &b, int base) {
    string r;
    int borrow = 0;
    int n1 = a.size(), n2 = b.size();

    for (int i = 0; i < n1; i++) {
        int da = symbolToNumber(a[n1 - 1 - i]) - borrow;
        int db = i < n2 ? symbolToNumber(b[n2 - 1 - i]) : 0;
        if (da < db) {
            da += base;
            borrow = 1;
        } else borrow = 0;
        r.push_back(numberToSymbol(da - db));
    }
    while (r.size() > 1 && r.back() == '0') r.pop_back();
    reverse(r.begin(), r.end());
    return r;
}

string addNumbers(const string &n1, const string &n2, int base) {
    bool neg1 = n1[0] == '-';
    bool neg2 = n2[0] == '-';
    string a = neg1 ? n1.substr(1) : n1;
    string b = neg2 ? n2.substr(1) : n2;

    if (!neg1 && !neg2) return addPlusNumber(a, b, base);
    if (neg1 && neg2) return "-" + addPlusNumber(a, b, base);
    if (neg1 && !neg2) {
        if (absLess(a, b)) return subtractPlusNumber(b, a, base);
        return "-" + subtractPlusNumber(a, b, base);
    } else {
        if (absLess(a, b)) return "-" + subtractPlusNumber(b, a, base);
        return subtractPlusNumber(a, b, base);
    }
}

string subtractNumbers(const string &n1, const string &n2, int base) {
    bool neg1 = n1[0] == '-';
    bool neg2 = n2[0] == '-';
    string a = neg1 ? n1.substr(1) : n1;
    string b = neg2 ? n2.substr(1) : n2;

    if (!neg1 && !neg2) {
        if (absLess(a, b)) return "-" + subtractPlusNumber(b, a, base);
        return subtractPlusNumber(a, b, base);
    }
    if (neg1 && neg2) return subtractNumbers(b, a, base);
    if (neg1 && !neg2) return "-" + addPlusNumber(a, b, base);
    return addPlusNumber(a, b, base);
}

int task() {
    int base;
    string n1, n2;

    cout << "Введите основание (2-36): ";
    cin >> base;
    if (base < 2 || base > 36) {
        cout << "Неверное основание\n";
        return 1;
    }

    cout << "Введите первое число: ";
    cin >> n1;
    cout << "Введите второе число: ";
    cin >> n2;

    if (!isValidNumber(n1, base) || !isValidNumber(n2, base)) {
        cout << "Ошибка: недопустимые символы или буквы для данного основания\n";
        return 1;
    }

    cout << "Сумма: " << addNumbers(n1, n2, base) << endl;
    cout << "Разность: " << subtractNumbers(n1, n2, base) << endl;
    return 0;
}

int main() {
    menu();
    while (true) {
        cout << "\n1 - начать, 0 - выход: ";
        int c;
        cin >> c;
        if (c == 1) task();
        else if (c == 0) return 0;
        else cout << "Неверный ввод\n";
    }
}

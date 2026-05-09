#include <iostream>

void contex(){
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                        Menu                                  |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                       Task_4                                 |" << std::endl;
    std::cout << "|                                 Вариант 16 - 15 = 1                          |" << std::endl;
    std::cout << "|                                     Выполнил:                                |" << std::endl;
    std::cout << "|                              Стецко Ярослав Юрьевич                          |" << std::endl;
    std::cout << "|                                   Суть задания:                              |" << std::endl;
    std::cout << "|          Необходимо определить диагональ с наибольшей суммой чисел           |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}

void buf_clear(){ //очистка ввода
    std::cin.clear(); 
    std::cin.ignore(32767,'\n');
}

int main(){
    contex();
    char ret;
    do{
        int n;
        std::cout << "Введите n: ";
        do{
            std::cin >> n;
            if (!n){
                buf_clear();
                std::cout << "Некорректный ввод, введите ещё раз: ";
            }
        }
        while(!n);  
    
        int*** arr = new int**[n]; //создание динамического массива n x n х n (куб)
        for (int i = 0; i < n; ++i) {
            arr[i] = new int*[n];
            for (int j = 0; j < n; ++j) {
                arr[i][j] = new int[n];
            }
        }

        for (int i = 0; i < n; ++i) //заполняем массив рандомными числами
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    arr[i][j][k] = rand() % 10;

        std::cout << std::endl << "Элементы массива:" << std::endl; // вывод всей матрицы
        for (int i = 0; i < n; ++i) {
        std::cout << "Слой " << i << std::endl;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k)
                std::cout << arr[i][j][k] << " ";
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        int s1 = 0, s2 = 0, s3 = 0, s4 = 0; //переменные сумм диагоналей куба

        for (int i = 0; i < n; ++i) { //подсчет сумм переменных в диагоналях куба
            s1 += arr[i][i][i];
            s2 += arr[i][i][n - 1 - i];
            s3 += arr[i][n - 1 - i][i];
            s4 += arr[i][n - 1 - i][n - 1 - i];
        }

        
        int maxS = s1;
        int diagNum = 1;

        if (s2 > maxS) { maxS = s2; diagNum = 2; } //поиск максимальной суммы и номера этой диагонали
        if (s3 > maxS) { maxS = s3; diagNum = 3; }
        if (s4 > maxS) { maxS = s4; diagNum = 4; }

        std::cout << "Суммы диагоналей:" << std::endl; 
        std::cout << "Диагональ 1: " << s1 << std::endl;
        std::cout << "Диагональ 2: " << s2 << std::endl;
        std::cout << "Диагональ 3: " << s3 << std::endl;
        std::cout << "Диагональ 4: " << s4 << std::endl;

        std::cout << std::endl << "Наибольшая сумма у диагонали " << diagNum << ": " << maxS << std::endl;

        for (int i = 0; i < n; ++i) { //очистка динамической памяти
            for (int j = 0; j < n; ++j)
                delete[] arr[i][j];
            delete[] arr[i];
        }
        delete[] arr;

        std::cout << std::endl;
        std::cout << "Желаете продолжить?(y/n):";
        do{
            std::cin >> ret;
            if (ret != 'y' && ret != 'n'){
                buf_clear();
                std::cout << "Некорректный ввод, желаете продолжить?(y/n): ";
            }
        }
        while(ret != 'y' && ret != 'n');    
        if(ret == 'y') system("cls");
    }
    while(ret == 'y');
    return 0;
}
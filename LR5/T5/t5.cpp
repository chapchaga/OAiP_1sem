#include "t5.h"

int** t5(int** arr, int a, int b){
    int* arr2 = new int [a / 2 * b];
    int len = 0, sum = 0;

    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if(((j + 1) % 2 == 0) && (arr[i][j] % 2 == 1)){
                arr2[len] = arr[i][j];
                len++;
                sum = sum + arr[i][j];
            }
        }
    }

    for(int i = 0; i < len; i++) std::cout <<"Нечетные элементы массива в четных столбцах: "<< arr2[i] <<"\n";
    std::cout <<"Среднее арифметическое элементвов массива: "<< double(sum) / len;

    for(int i = 0; i < a; i++) delete[] arr[i];
    delete[] arr;
    delete[] arr2;
    return 0;
}

int** cinMAT(int** arr, int n, int k){ //Ввод матрицы
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            while(!(std::cin >> arr[i][j]) && arr[i][j] != 0) buf_clear();
        }
    }
    return(arr);
}

void contex(){ //Контекстное меню
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                        Menu                                  |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                       Task_5                                 |" << std::endl;
    std::cout << "|                                     Выполнил:                                |" << std::endl;
    std::cout << "|                              Мусский Захар Андреевич                         |" << std::endl;
    std::cout << "|                                   Суть задания:                              |" << std::endl;
    std::cout << "|   Создать динамический массив из элементов, расположенных в четных столбцах  |" << std::endl;
    std::cout << "| данного массива и имеющих нечетное значение. Вычислить среднее арифметическое|" << std::endl; 
    std::cout << "|                         элементов динамического массива.                     |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}

void buf_clear(){ //Очистка ввода
    std::cin.clear(); 
    std::cin.ignore(32767,'\n');
    std::cout << "Некорректный ввод, введите ещё раз: \n";
}
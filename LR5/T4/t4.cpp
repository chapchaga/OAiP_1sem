#include "t4.h"

double** t4(double** arr, int a, int b){
    int c = 0;
    double** arr2 = new double* [a];
    for(int i = 0; i < a; i++){
        arr2[i] = new double[b];
    }


    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if(arr[i][j] == 0){
                std::cout << c+1 <<". Индекс 0: "<< i <<" " <<j <<"\n";
                c++;
            }
            arr2[a - i - 1][b - j - 1] = arr[i][j];
        }
    }
    std::cout << "Количество нулей в массиве: " << c <<"\n";


    std::cout << "Измененный массив:\n";
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            std::cout << arr2[i][j] <<" ";
        }
        std::cout<<"\n";
    }


     for(int i = 0; i < a; i++){
        delete[] arr2[i];
        delete[] arr[i];
    }
    delete[] arr2;
    delete[] arr;
    return 0;
}

double** cinMAT(double** arr, int n, int k){ //Ввод матрицы
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
    std::cout << "|                                       Task_4                                 |" << std::endl;
    std::cout << "|                                     Выполнил:                                |" << std::endl;
    std::cout << "|                              Мусский Захар Андреевич                         |" << std::endl;
    std::cout << "|                                   Суть задания:                              |" << std::endl;
    std::cout << "|    Создать двумерный динамический массив вещественных чисел. Определить,     |" << std::endl;
    std::cout << "|встречаются ли среди них элементы с нулевым значением. Если встречаются такие |" << std::endl;
    std::cout << "|             элементы, то определить их индексы и общее количество.           |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}

void buf_clear(){ //Очистка ввода
    std::cin.clear(); 
    std::cin.ignore(32767,'\n');
    std::cout << "Некорректный ввод, введите ещё раз: \n";
}

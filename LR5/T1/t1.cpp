#include "t1.h"

double* cinARR(double* arr, int n){ //Ввод массива
    for(int i = 0; i < n; i++){
        while(!(std::cin >> arr[i])) buf_clear();
    }
    return(arr);
}

double* t1(double* A, double* B, int N){ //Алгоритм для решения задачи 1
    std::cout << "\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i] == 0 || B[j] == 0) std::cout <<A[i] << "x + " << B[j] << " = 0, x = 0" << "\n";
            else std::cout <<A[i] << "x + " << B[j] << " = 0, x = "<< B[j] / ((-1) * A[i]) << "\n";
        }
    }
    return(A, B);
}

void contex(){ //Контекстное меню
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                        Menu                                  |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                       Task_1                                 |" << std::endl;
    std::cout << "|                                 Вариант 16 - 15 = 1                          |" << std::endl;
    std::cout << "|                                     Выполнил:                                |" << std::endl;
    std::cout << "|                              Стецко Ярослав Юрьевич                          |" << std::endl;
    std::cout << "|                                   Суть задания:                              |" << std::endl;
    std::cout << "|        Составить программу для решения уравнения A[i]x + B[j] = 0            |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}

void buf_clear(){ //Очистка ввода
    std::cin.clear(); 
    std::cin.ignore(32767,'\n');
    std::cout << "Некорректный ввод, введите ещё раз: \n";
}

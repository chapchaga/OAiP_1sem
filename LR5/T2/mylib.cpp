#define BUILD_DLL
#include"mylib.h"
#include <cmath> 

double* rec1(double* A, int N, int num){
    if(sin(A[num]) > 0){
        std::cout << sin(A[num]) << "\n";
    }
    if(num == N / 2 - 1) return 0;
    else return(rec1(A, N, num++));
}

double* rec2(double* A, int N, int num){
    if(sin(A[num]) > 0){
        std::cout << sin(A[num]) << "\n";
    }
    num++;
    if(num == N) return 0;
    else return(rec2(A, N, num));
}

void contex(){ //Контекстное меню
    std::cout << "----------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                         Menu                                   |" << std::endl;
    std::cout << "----------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                        Task_2                                  |" << std::endl;
    std::cout << "|                                 Вариант: 16 - 15 = 1                           |" << std::endl;
    std::cout << "|                                      Выполнил:                                 |" << std::endl;
    std::cout << "|                               Стецко Ярослав Юрьевич                           |" << std::endl;
    std::cout << "|                                    Суть задания:                               |" << std::endl;
    std::cout << "|  Для заданного одномерного массива A из N элементов проверить, что существует, |" << std::endl;
    std::cout << "|по крайней мере, один элемент A[i], для которого выполняется условие sin(A[i])>0|" << std::endl;
    std::cout << "----------------------------------------------------------------------------------" << std::endl;
}

void buf_clear(){ //Очистка ввода
    std::cin.clear(); 
    std::cin.ignore(32767,'\n');
    std::cout << "Некорректный ввод, введите ещё раз: \n";
}

double* cinARR(double* arr, int n){ //Ввод массива
    for(int i = 0; i < n; i++){
        while(!(std::cin >> arr[i]) && arr[i] != 0) buf_clear();
    }
    return(arr);
}
#include <iostream>
#include "t4.h"

int main(){
    char ret;
    contex();
    do{
        int a,b;
        std::cout << "Введите размер матрицы: \n"; 
        while(!(std::cin >> a >> b)) buf_clear();

        double** arr = new double* [a];
        for(int i = 0; i < a; i++){
            arr[i] = new double[b];
        }

        std::cout << "Введите мтрицу " << a << "x" << b <<": \n"; 
        arr = cinMAT(arr, a, b);
        t4(arr, a, b);
        
        std::cout << "\nЖелаете продолжить?(y/n): \n";
        std::cin >> ret;
        while (ret != 'y' && ret != 'n'){
            buf_clear();
            std::cin >> ret;
        }
    }
    while(ret != 'n');
    system("cls");
    return 0;
}
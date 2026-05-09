#include <iostream>
#include "t3.h"

int main(){
    char ret;
    contex();
    do{
        int n, k;

        std::cout << "Введите n, k: \n";
        while(!(std::cin >> n >> k)) buf_clear();

        int** arr = new int* [n];
        for(int i = 0; i < n; i++){
            arr[i] = new int [k];
        }

        std::cout << "Введите матрицу n x k: \n";
        arr = cinMAT(arr, n, k);
        t3(arr, n, k);

        std::cout << "\nЖелаете продолжить?(y/n): \n";
        std::cin >> ret;
        while (ret != 'y' && ret != 'n'){
            buf_clear();
            std::cin >> ret;
        }
    }
    while (ret != 'n');
    system("cls");
    return 0;
}
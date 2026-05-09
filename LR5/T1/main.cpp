#include <iostream>
#include "t1.h"

int main(){
    contex();
    char ret;
    do{
        int N;
        std::cout << "Введите длину массивов: \n";
        while(!(std::cin >> N)) buf_clear();
        double* A = new double [N];
        double* B = new double [N];

        std::cout << "Введите массив A: \n";
        A = cinARR(A, N);
        std::cout << "Введите массив B: \n";
        B = cinARR(B, N);
        t1(A, B, N);

        delete[] A;
        delete[] B;
        
        std::cout << "\nЖелаете продолжить?(y/n): \n";
        std::cin >> ret;
        while(ret != 'y' && ret != 'n'){ 
            buf_clear();
            std::cin >> ret;
        }
    }
    while(ret != 'n');
    system("cls");
    return 0;
}
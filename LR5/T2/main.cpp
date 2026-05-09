#include <iostream>
#include <cmath>
#include"mylib.h"

int main(){
    contex();
    char ret;
    do{
        int N, num = 0;

        std::cout <<"Введите N: \n";
        while(!(std::cin >> N) || N < 1) buf_clear();

        double* A = new double[N];

        std::cout <<"Введите массив: \n";
        A = cinARR(A, N);

        if(N == 1 && sin(A[0]) > 0){
            std::cout << sin(A[num]);
        }
        else{
            rec1(A, N, num);
            rec2(A, N, N / 2);
        }
        
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
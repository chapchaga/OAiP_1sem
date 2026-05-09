#include <iostream>

void contex(){
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                        Menu                                  |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                       Task_2                                 |" << std::endl;
    std::cout << "|                                 Вариант 16 - 15 = 1                          |" << std::endl;
    std::cout << "|                                     Выполнил:                                |" << std::endl;
    std::cout << "|                              Стецко Ярослав Юрьевич                         |" << std::endl;
    std::cout << "|                                   Суть задания:                              |" << std::endl;
    std::cout << "|    Определить количество положительных элементов, расположенных ниже         |" << std::endl;
    std::cout << "|                           побочной диагонали матрицы                         |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}

void buf_clear(){ //очистка ввода
    std::cin.clear(); 
    std::cin.ignore(32767,'\n');
}

int main(){
    contex();
    char ret;
    const int M = 5, N = 5; //размеры матрицы
    do{
        int arr[M][N];

        std::cout << "Введите матрицу 5x5: " << std::endl; //ввод матрицы 5х5
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                do{
                    std::cin >> arr[i][j];
                    if(!arr[i][j] && arr[i][j] != 0){
                        buf_clear();
                        std::cout << "Некорректный ввод, введите ещё раз клетку["<<i+1<<", "<<j+1<<"]: ";
                    }
                }
                while(!arr[i][j] && arr[i][j] != 0);
            }
        }

        int c = 0; //счетчик положительных чисел под побочной диагональю
        
        for(int i = 0; i < M; i++){ //проходимся по всем элементам ниже побочной диагонали
            for(int j = 0; j < N; j++){
                if(j > (N - i - 1)){
                    if(arr[i][j] > 0) c++;
                }
            }
        }
        std::cout << c << " положительных чисел.";

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
#include <iostream>

void contex(){
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                        Menu                                  |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                       Task_5                                 |" << std::endl;
    std::cout << "|                                 Вариант 16 - 15 = 1                          |" << std::endl;
    std::cout << "|                                     Выполнил:                                |" << std::endl;
    std::cout << "|                              Стецко Ярослав Юрьевич                          |" << std::endl;
    std::cout << "|                                   Суть задания:                              |" << std::endl;
    std::cout << "|  Требуется дополнить поле для игры 'Сапёр' числами, как в оригинальной игре  |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}

void buf_clear(){ //очистка ввода
    std::cin.clear(); 
    std::cin.ignore(32767,'\n');
}

int alg(char** arr, int i, int j, int m, int n){
    int c = 0; //счетчик бомб аокруг точки i j 
    bool h = false,d = false,r = false,l = false; // переменные, которые будут определять верхний, нижний и тд. край
    if(i - 1 < 0){}
    else{
        if(arr[i-1][j] == '*') c++;
            h = true;
    }
    if(i + 1 >= m){}
    else{
        if(arr[i+1][j] == '*') c++;
        d = true;
    }
    if(j - 1 < 0){}
    else{
        if(arr[i][j-1] == '*') c++;
        l = true;
    }
    if(j + 1 >= n){}
    else{
        if(arr[i][j+1] == '*') c++;
        r = true;
    }
    if(l && h) if(arr[i-1][j-1] == '*') c++;
    if(r && h) if(arr[i-1][j+1] == '*') c++;
    if(l && d) if(arr[i+1][j-1] == '*') c++;
    if(r && d) if(arr[i+1][j+1] == '*') c++;
    return c;
}

int main(){
    contex();
    char ret;
    int N;
    do{
        int n, m;
        std::cout << "Введите размеры поля M x N: " << std::endl;
         do{
            std::cin >> m >> n;
            if (!m || !n){
                buf_clear();
                std::cout << "Некорректный ввод, введите ещё раз: ";
                }
            }
        while(!m || !n);

        char** arr = new char*[m]; //создание массива m x n(поля)
        for (int i = 0; i < m; i++) {
            arr[i] = new char[n];
        }

        std::cout << "Введите поле M x N, где * - мины, а . - пустая клетка:" << std::endl;
        for (int i = 0; i < m; i++) { //ввод массива
            for(int j = 0; j < n; j++){
                do{
                    std::cin >> arr[i][j];
                    if (arr[i][j] != '.' && arr[i][j] != '*'){
                        buf_clear();
                        std::cout << "Некорректный ввод, введите ещё раз клетку["<<i+1<<", "<<j+1<<"]: ";
                    }
                }
                while(arr[i][j] != '.' && arr[i][j] != '*');
            }
        }
    
        std::cout << std::endl << "Переделанное поле:" << std::endl; //вывод переделанного поля 
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                if(arr[i][j] == '*') std::cout << "* ";
                else std::cout << alg(arr, i, j, m, n) <<" ";
            }
            std::cout<<std::endl;
        }

        for (int i = 0; i < n; ++i) { //очистка динамической памяти
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
#include <iostream>

void contex(){
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                        Menu                                  |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                       Task_3                                 |" << std::endl;
    std::cout << "|                                 Вариант 16 - 15 = 1                          |" << std::endl;
    std::cout << "|                                     Выполнил:                                |" << std::endl;
    std::cout << "|                              Стецко Ярослав Юрьевич                         |" << std::endl;
    std::cout << "|                                   Суть задания:                              |" << std::endl;
    std::cout << "|В вещественной матрице размером NxN найти максимальный и минимальный элементы |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}

int main(){
    contex();
    char ret;
    int N;
    do{
        std::cout << "Введите N: ";
        std::cin >> N;

        double** arr{new double*[N]{}}; //создаем динамический массив (нашу матрицу)
        for(int i = 0; i < N; i++){
            arr[i] = new double[N]{};
        }

        std::cout<< std::endl << "Введите матрицу N x N: "<< std::endl; //ввод матрицы
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                    std::cin >> arr[i][j];
            }
        }

        double max = arr[0][0], min = arr[0][0];
        int i1 = 0, i2 = 0;
        for(int i = 0; i < N; i++){ //обход всей матрицы
            for(int j = 0; j < N; j++){
                if(arr[i][j] > max){ //поиск максимального числа с сохранением индекса его строки
                    max = arr[i][j];
                    i1 = i;
                }
                if(arr[i][j] < min){ //поиск минимального числа с сохранением индекса его строки
                    min = arr[i][j];
                    i2 = i;
                }
            }
        }
        std::cout << std::endl << "min элемент: " << min << ", max элемент: " << max << std::endl;
        if(i1 == i2) std::cout << "min и max элементы матрицы находятся в одной строке!" << std::endl;
        else{
            for(int j = 0; j < N; j++){ //меняем строки местами
                double lll = arr[i2][j];
                arr[i2][j] = arr[i1][j];
                arr[i1][j] = lll;
            }
        }

        for(int i = 0; i < N; i++){ //вывод матрицы
            for(int j = 0; j < N; j++){
                std::cout<< arr[i][j] <<" ";
            }
            std::cout<<std::endl;
        }

        for (int i = 0; i < N; i++)  delete[] arr[i];  //очистка динамической памяти
        delete[] arr;


        std::cout << std::endl;
        std::cout << "Желаете продолжить?(y/n):";
        do{
            std::cin >> ret;
            if (ret != 'y' && ret != 'n'){
                std::cin.clear(); 
                std::cin.ignore(32767,'\n');
                std::cout << "Некорректный ввод, желаете продолжить?(y/n): ";
            }
        }
        while(ret != 'y' && ret != 'n');    
        if(ret == 'y') system("cls");
    }
    while(ret == 'y');
    return 0;
}
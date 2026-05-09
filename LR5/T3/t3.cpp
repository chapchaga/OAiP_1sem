#include "t3.h"

int** t3(int** arr, int n, int k){
    int proiz = 1, len = 0;
    int min = n;

    if(k < min) min = k;

    int* arr2 = new int [min];

    for(int i = 0; i < min; i++){
        if(arr[i][i] % 2 == 0 && arr[i][i] != 0){
            arr2[len] = arr[i][i];
            len++;
            proiz = proiz * arr[i][i];
        }
    }

    std::cout <<"Массив: \n";
    for(int i = 0; i < len; i++){
        std::cout << arr2[i] << " ";
    }
    std::cout <<"\nПроизведение: \n";
    std::cout << proiz;

    for (int i = 0; i < n; i++) { //очистка динамической памяти
                delete[] arr[i];
        }
    delete[] arr;
    delete[] arr2;
    return 0;
}

int** cinMAT(int** arr, int n, int k){ //Ввод матрицы
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            while(!(std::cin >> arr[i][j])) buf_clear();
        }
    }
    return(arr);
}

void contex(){ //Контекстное меню
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                        Menu                                  |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                       Task_3                                 |" << std::endl;
    std::cout << "|                                     Выполнил:                                |" << std::endl;
    std::cout << "|                              Мусский Захар Андреевич                         |" << std::endl;
    std::cout << "|                                   Суть задания:                              |" << std::endl;
    std::cout << "| Создать динамический массив из элементов, расположенных на главной диагонали |" << std::endl;
    std::cout << "|   матрицы и имеющих четное значение. Вычислить произведение этих элементов   |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}

void buf_clear(){ //Очистка ввода
    std::cin.clear(); 
    std::cin.ignore(32767,'\n');
    std::cout << "Некорректный ввод, введите ещё раз: \n";
}

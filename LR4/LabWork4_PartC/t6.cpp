#include<iostream>
#include<iomanip>

void buf_clear(){ //очистка ввода
    std::cin.clear(); 
    std::cin.ignore(32767,'\n');
}

void mg(int** arr, int n) { // вывод итогого маgic квадрата
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout<<" "<<arr[i][j]<<" ";
        }
        std::cout << '\n';
    }
    
    int s = n * (n * n + 1) / 2;
    std::cout << "Магическая сумма: " << s << '\n';
}



void mg_nechet(int** arr, int n) { // сиамский метод

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    // начинаем с верха и середины 
    int i = 0;
    int j = n / 2;
    
    for (int num = 1; num <= n * n; num++) {
        arr[i][j] = num;
        
        int new_i = (i - 1 + n) % n; // идем сначала вверх и вправо 
        int new_j = (j + 1) % n;
        
        if (arr[new_i][new_j] != 0) { //но если вверху занято, идем вниз
            i = (i + 1) % n;
        } else {
            i = new_i;
            j = new_j;
        }
    }
    mg(arr, n);
}


void mg_chetchet(int** arr, int n) { // метод четного-четного
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = num++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 4 == j % 4 || (i + j) % 4 == 3) {        
                arr[i][j] = n * n + 1 - arr[i][j];
            }
        }
    }
    mg(arr, n);
}


void mg_chetnechet(int** arr, int n) { // метод четных-нечетных перестановок
    int k = n / 2;

    int** A = new int*[k];
    for (int i = 0; i < k; i++) A[i] = new int[k];
    mg_nechet(A, k);
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            arr[i][j] = A[i][j];
            arr[i][j + k] = A[i][j] + 2*k*k;
            arr[i + k][j] = A[i][j] + 3*k*k;
            arr[i + k][j + k] = A[i][j] + k*k;
        }
    }

    for (int j = 0; j < k; j++) {
        if (j != k/2) {
            std::swap(arr[0][j], arr[k][j]); // первые k столбцов A и C
        }
    }
    std::swap(arr[0][k/2], arr[k][k/2]);   // Меняем средний столбец (A и C)
    
    for (int j = k + k/2 + 1; j < n; j++) {
        std::swap(arr[0][j], arr[k][j]); // Меняем последние (k-1) столбцов между B и D
    }
    mg(arr, n);

    for (int i = 0; i < k; i++) {
        delete[] A[i];
    }
    delete[] A;
}


void contex(){
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                        Menu                                  |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "|                                       Task_6                                 |" << std::endl;
    std::cout << "|                                 Вариант 16 - 15 = 1                          |" << std::endl;
    std::cout << "|                                     Выполнил:                                |" << std::endl;
    std::cout << "|                              Стецко Ярослав Юрьевич                          |" << std::endl;
    std::cout << "|                                   Суть задания:                              |" << std::endl;
    std::cout << "|                           Построить магический квадрат.                      |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}


int main(){
    contex();
    char ret;
    do {        
        std::cout<<"Введите порядок магического квадарата(<32): ";
        int n;
         do{
            std::cin >> n;
            if (!n || n > 32){
                buf_clear();
                std::cout << "Некорректный ввод, введите n: ";
            }
        }
        while(!n || n > 32);
        
        int** arr = new int*[n];
        for (int i = 0; i < n; i++){
            arr[i] = new int[n];
        }

        if (n % 2 == 1) {
        std::cout<<"Магический квадрат "<<n<<" порядка построенный сиамским методом: \n";
        mg_nechet(arr, n);
        }
        else if (n % 4 == 0){
        std::cout<<"Магический квадрат "<<n<<" порядка построенный методом 'четного-четного': \n"; 
        mg_chetchet(arr, n); 
        }
        else{
        std::cout<<"Магический квадрат "<<n<<" порядка построенный методом 'четного-нечетного': \n"; 
        mg_chetnechet(arr, n);
        }

        

        //очистка памяти
        for (int i = 0; i < n; i++) {
            delete[] arr[i];
        }

        delete[] arr;
        
        std::cout << "Желаете продолжить?(y/n):";
        do{
            std::cin >> ret;
            if (ret != 'y' && ret != 'n'){
                buf_clear();
                std::cout << "Некорректный ввод, желаете продолжить?(y/n): ";
            }
        }
        while(!ret);
    }while(ret == 'y');
    return 0;
}
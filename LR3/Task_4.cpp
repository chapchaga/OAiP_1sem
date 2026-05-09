#include <iostream>
#include <cmath>

void Menu(){
    std::cout<<" "<<std::endl;
    std::cout <<"----------------------------------------------------"<<std::endl;
    std::cout <<"-                                                  -"<<std::endl;
    std::cout <<"-                                                  -"<<std::endl;
    std::cout <<"-            Выполнил : Стецко Я.Ю.                -"<<std::endl;
    std::cout <<"-                                                  -"<<std::endl;
    std::cout <<"- Суть задания : вычислить функцию двумя способами -"<<std::endl;
    std::cout <<"-                                                  -"<<std::endl;
    std::cout <<"-                Вариант: 7(22)                    -"<<std::endl;
    std::cout <<"-                                                  -"<<std::endl;
    std::cout <<"----------------------------------------------------"<<std::endl;
}

void task(){
    int n,m;
    std::cout<<" Количество членов ряда n : ";
    std::cin>>n;
    std::cout<<" Количество чисел, от которых вы хотите посчитать функцию ";
    std::cin>>m;

    for(int i=0; i<m; i++){
        double x;
        std::cout<<"\n Введите x в диапазоне от 0,1 до 1 : ";
        std::cin>>x;

        double S=0.0;

        for(int k=0; k<=n; k++){
            double first=pow(-1,k+1);
            double second=pow(x,2*k+1);
            double third=4*k*k-1;
            S+=first*second/third;
        }

        double Y=(((1+x*x)/2)*atan(x))-x/2;

        std::cout<<"\nРезультат через ряд : "<<S<<"\n";
        std::cout<<"Результат через Y : "<<Y;
    }
}

int main () {
    Menu();
    while (true) {
        std::cout<<"/n1-начало программы, 0-завершение программы: "<<std::endl;
        int choice;
        while (!(std::cin>>choice)) {
            std::cin.clear ();
            std::cin.ignore(10000, '\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз: ";
        }
        switch (choice)
        {
            case 1:
                task();
                break;

            case 0:
                std::cout<<"Завершение программы";
                return 0;
                break;

            default:
                std::cout<<"Неверный выбор, введите снова : ";
        }
    }
}

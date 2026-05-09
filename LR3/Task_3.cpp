#include <iostream>
#include <cmath>

void Menu(){
std::cout<<" "<<std::endl;    
std::cout <<"---------------------------------------------"<<std::endl;
std::cout <<"-                                           -"<<std::endl;
std::cout <<"-                                           -"<<std::endl;
std::cout <<"-        Выполнил : Стецко Я.Ю.             -"<<std::endl;
std::cout <<"-                                           -"<<std::endl;
std::cout <<"- Суть задания : вычислить значения функций -"<<std::endl;
std::cout <<"-                                           -"<<std::endl;
std::cout <<"-                                           -"<<std::endl;
std::cout <<"---------------------------------------------"<<std::endl;
}

void task(){
    int M=20;
    double B=3.14159/2.0,A=0.0,H=(B-A)/M,x;

    for(int i=0;i<=M;i++){
        double X=A+i*H;
        double Y=sin(x)-cos(x);
        std::cout << i << "\t" << X << "\t" << Y <<std::endl;
    }
}

int main () {
     Menu(); 
     while (true) {
        std::cout<<"1-начало программы, 0-завершение программы: "<<std::endl;
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
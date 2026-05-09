#include <iostream>
#include <cmath>

void Menu(){
std::cout <<" "<<std::endl;    
std::cout <<"----------------------------------------------------"<<std::endl;
std::cout <<"-                                                  -"<<std::endl;
std::cout <<"-                                                  -"<<std::endl;
std::cout <<"-            Выполнил : Стецко Я.Ю.                -"<<std::endl;
std::cout <<"-                                                  -"<<std::endl;
std::cout <<"-   Суть задания : вывести числа Армстронга        -"<<std::endl;
std::cout <<"-                                                  -"<<std::endl;
std::cout <<"-                                                  -"<<std::endl;
std::cout <<"-                                                  -"<<std::endl;
std::cout <<"----------------------------------------------------"<<std::endl;
}

void task(){
int max;
std::cout << " Введите число : ";
std::cin >> max;

std::cout << " Числа Армстронга меньше " << max << ":\n";

for ( int i=0; i<max; i++ ) {
int num = i;
int digits = 0;  //колво цифр

int temp = num;
while ( temp > 0 ){
    temp /= 10;
    digits++;    
}
if ( digits == 0 ) digits = 1;

temp = num;
int sum = 0;
while ( temp > 0 ) {
    int digit = temp % 10;
    sum += std::pow ( digit,digits );
    temp /= 10;
}

if ( i == sum )
std::cout<< i << std::endl;
} 
}

int main () {
     Menu(); 
     while (true) {
        std::cout<<"\n1-начало программы, 0-завершение программы: "<<std::endl;
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

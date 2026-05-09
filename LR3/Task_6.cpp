#include <iostream>

double sin_custom(double x){
    double sum=0;
    double term=x;
    int n=1;
    while( term>1e-6 || term<-1e-6){
        sum+=term;
        term *=-x*x/((2*n)*(2*n+1));
        n++;
    }
    return sum;
}

double cos_custom(double x){
    double sum = 0;
    double term = 1;
    int n = 1;
    while (term>1e-6 || term<-1e-6){
        sum +=term;
        term *=-x*x/((2*n-1)*(2*n));
        n++;
    }
    return sum;
}

double ln_custom(double x){
    if (x <= 0) {
        std::cout << "ln(|x|) не может быть больше 0 !\n";
        return 0;
    }
    double y =(x-1)/x;
    double sum =0;
    double term =y;
    int n = 1;
    while (term>1e-6||term<-1e-6) {
        sum += term/n;
        term *=y;
        n++;
    }
    return sum;
}

void Menu(){
std::cout<<" "<<std::endl;    
std::cout <<"-----------------------------------------------------------------------------"<<std::endl;
std::cout <<"-                                                                           -"<<std::endl;
std::cout <<"-                                                                           -"<<std::endl;
std::cout <<"-                          Выполнил : Стецко Я.Ю.                           -"<<std::endl;
std::cout <<"-                                                                           -"<<std::endl;
std::cout <<"- Суть задания : определить и вывести на экран дисплея минимальное значение -"<<std::endl;
std::cout <<"-                                                                           -"<<std::endl;
std::cout <<"-                                                                           -"<<std::endl;
std::cout <<"-                                                                           -"<<std::endl;
std::cout <<"-----------------------------------------------------------------------------"<<std::endl;
}


void task(){
    double x;
    std::cout<<"Введите x :";
    std::cin>>x;

    double a=sin_custom(x);
    double b=cos_custom(x);
    double c=ln_custom(x>0 ? x:-x);

    double min=a;
    if(b<min) min=b;
    if(c<min) min=c;

    std::cout<<"\n Минимальное значение :  "<<min;
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

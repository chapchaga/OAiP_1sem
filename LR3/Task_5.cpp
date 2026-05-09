#include <iostream>
#include <cmath>
#include <limits>

            double f(double x){
                double s=sin(2.0*x);
                if(fabs(s)<1e-14){
              return std::numeric_limits<double>::quiet_NaN();
                }
                double cot2x=cos(2.0*x)/s;
                double second=1/(1+x*x);
                return cot2x-second;
            }




void Menu(){
std::cout<<" "<<std::endl;    
std::cout <<"----------------------------------------------------"<<std::endl;
std::cout <<"-                                                  -"<<std::endl;
std::cout <<"-                                                  -"<<std::endl;
std::cout <<"-            Выполнил : Стецко Я.Ю.                -"<<std::endl;
std::cout <<"-                                                  -"<<std::endl;
std::cout <<"-    Суть задания : найти корень уравнения         -"<<std::endl;
std::cout <<"-                                                  -"<<std::endl;
std::cout <<"-                Вариант: 7(22)                    -"<<std::endl;
std::cout <<"-                                                  -"<<std::endl;
std::cout <<"----------------------------------------------------"<<std::endl;
}

void task(){
double a=2.0,b=3.0;
int n;
std::cout<<"Введите на сколько частей разделить интервал от 2 до 3 : ";
std::cin>>n;

if(n<=0){
    std::cout<<"Недопустимое значение\n";
}

double h=(b-a)/n;
double best_x=a;
double best_abs=std::numeric_limits<double>::infinity();
bool found=false;

for(int i=0; i<=n; i++){
    double x=a+i*h;
    double fx=f(x);

    if(std::isnan(fx)){
        std::cout<<"Проgуск точки x = "<<x<<"знаменатель близок к нулю\n";
        continue;
    }

double abs_fx = fabs(fx);
if(!found || abs_fx<best_abs){
    best_abs=abs_fx;
    best_x=x;
    found=true;
}
}

if(!found){
    std::cout<<"Не удалсось найти подходящую точку\n"; 
} else{
    std::cout<<"Корень x = "<<best_x;
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
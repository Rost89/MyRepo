/*
Карпенко Р.

Задача 2.
Создать класс Car (автомобиль) с полями company (компания) и model (модель). Классы-наследники: PassengerCar (легковой автомобиль)
и Bus (автобус). От этих классов наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы они выводили
данные о классах. Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
Обратить внимание на проблему «алмаз смерти».
*/

#include <iostream>
#include <locale>


using namespace std;

class Car{
protected:
    string company;
    int model;
public:
   Car(string c = "Какой-то колхоз", int m = 2019)
        : company(c), model(m) {
    }
   virtual ~Car() {}
    void getInfo(){
        cout << "Компания: " << company << endl << "Модель: "<< model << endl;
   }
};

class PassengerCar: virtual public Car {
private:
    string length;
    int numberOfPassengers;
public:
    PassengerCar(string l = "маленькие", int n = 4)
        : length(l), numberOfPassengers(n){
        cout << "Легковой автомобиль\nГабаритные размеры: " << length << endl
             <<"Количество пассажиров: " << numberOfPassengers << endl;
        getInfo();
    }
    ~PassengerCar() { }


};
class Bus: virtual public Car{
private:
    string length;
    int numberOfPassengers;
public:
    Bus(string l = "большие", int n = 150)
        :length(l), numberOfPassengers(n){
        cout << "Автобус\nГабаритные размеры: " << length << endl
             <<"Количество пассажиров: " << numberOfPassengers << endl;
        getInfo();
    }
    ~Bus() { }
};

class Minivan: public PassengerCar, public Bus {
private:
    string mixed;
    int numberOfdors;
public:
    Minivan(string m = "что-то среднее между легковым автомобилем и автобусом\n", int n = 4)
        :mixed(m), numberOfdors(n)
    {
        cout <<"Минивен\nэто "<< mixed << "Количество дверей: "<< numberOfdors << endl;;
    }
    ~Minivan() { }
};

int main()
{   setlocale(LC_ALL, "rus");

   // Car c1;
   // PassengerCar pc1;
   // Bus b1;
    Minivan m1;
    m1.getInfo();


    char sym;
    cin >> sym;
    return 0;
}

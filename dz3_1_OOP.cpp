/*
Карпенко Р

Задача 1.
Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб).
Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь).
Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

*/

#include <iostream>
#include <locale>

using namespace std;

class Figure {
public:
    Figure () { }
    virtual ~Figure () { }
    virtual void area() {
        cout << "Area of ";
    }
};
class Parallelogram: public Figure{
private:
    int baseP;
    int heightP;
public:
    Parallelogram (int b = 10, int h = 20)
        : baseP(b), heightP(h) { }
    virtual ~Parallelogram() override { }
    void area() override {
        Figure::area();
        cout << "Parallelogram is "<<baseP*heightP << endl;
    }
};
class Circle: public Figure {
private:
    int radius;
public:
    Circle (int r = 25)
        : radius(r){ }
    virtual ~Circle() override { }
    void area() override {
        Figure::area();
        cout << " Circle is "<< radius*radius*3.14 << endl;
    }
};

class Rectangle: public Parallelogram{
private:
    int baseR;
    int heightR;
public:
    Rectangle (int b = 120, int h = 50)
        : baseR(b), heightR(h){ }
    virtual ~Rectangle() override { }
    void area() override {
        Figure::area();
        cout << " Rectangle is "<< baseR*heightR << endl;
    }
};
class Square: public Parallelogram{
private:
    int baseS;
public:
    Square (int b = 100)
        : baseS(b){ }
    virtual ~Square() override { }
    void area() override {
        Figure::area();
        cout << " Square is "<< baseS*baseS << endl;
    }
};
class Rhombus: public Parallelogram{
private:
    int diagonal1;
    int diagonal2;
public:
    Rhombus (int d1 = 50, int d2 = 20)
        : diagonal1(d1), diagonal2(d2) { }
    virtual ~Rhombus() override { }
    void area() override {
        Figure::area();
        cout << " Rhombus is "<< ((diagonal1*diagonal2)/2) << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Figure figure1;
    Parallelogram parallelogram1;
    Circle circle1;
    Rectangle rectangle1;
    Square square1;
    Rhombus rhombus1;

    Figure* par = &parallelogram1;
    par->area();
    Figure* cir = &circle1;
    cir->area();
    Figure* rec = &rectangle1;
    rec->area();
    Figure* squ = &square1;
    squ->area();
    Figure* rho = &rhombus1;
    rho->area();

    char sym;
    cin >> sym;
    return 0;
}

/* Задача 1.
Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две переменные-члена для хранения
этих вещественных чисел. Еще создать два метода: один с именем set, который позволит присваивать значения переменным,
второй — calculate, который будет выводить результат возведения первого числа в степень второго числа.
Задать значения этих двух чисел по умолчанию.

2.Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha
(#include cstdint для доступа к этому типу). Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue,
m_green и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов.

3.Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
private-массив целых чисел длиной 10;
private целочисленное значение для отслеживания длины стека;
public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
public-метод с именем print(), который будет выводить все значения стека.
*/


#include <iostream>
#include <locale>
#include <math.h>
#include <cstdint>
using namespace std;

class Power{
public:
    float a = 2;
    float b = 2;

    void set(float valueA, float valueB){
        a = valueA;
        b = valueB;
    }
    float calculate (){ return pow(a,b);
    }
};
class RGBA{
private:
    int m_red = 0;
    int m_blue = 0;
    int m_green = 0;
    int m_alpha = 255;

public:
    RGBA (int red, int blue, int green, int alpha)
        : m_red(red), m_blue(blue), m_green(green), m_alpha(alpha)
    {

    }
    void print (){
        cout << m_red << " " << m_blue << " " << m_green << " " << m_alpha << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    char repeat;
m0:

    puts("Задача 1.");
    Power p1;
    float valueA;
    float valueB;
    cout << "Значения переменных - членов класса Power по умолчанию:\n";
    cout << "a = " << p1.a << endl << "b = " << p1.b << endl <<"a^b = " << p1.calculate() << endl;
    cout << "Введите новые значения a и b: ";
    cin >> valueA >> valueB;
    p1.set(valueA, valueB);
    cout << "a = " << p1.a << endl << "b = " << p1.b << endl <<"a^b = " << p1.calculate() << endl;

    puts("Задача 2.");
    cout << "Введите значения от 0 до 255 для m_red, m_blue, m_green, m_alpha:\n";

    int red;
    int blue;
    int green;
    int alpha;

    cin >> red >> blue >> green >> alpha;
    RGBA rgba1(red,blue,green,alpha);
    rgba1.print();

    puts("Задача 3.");


    cout << "Repeat the programm? (y/n): ";
    cin >> repeat;
    if (repeat == 'y' || repeat == 'Y') goto m0;
    return 0;
}

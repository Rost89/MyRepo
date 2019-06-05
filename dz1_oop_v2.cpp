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
#include <stdint.h>

using namespace std;

class Power{
public:
    float a = 2;
    float b = 2;

    void set(float &valueA, float &valueB){
        a = valueA;
        b = valueB;
    }
    float calculate (Power &power){ return pow(power.a, power.b);}
    void powerPrint(Power &power){
        cout << "Значения переменных - членов класса Power:\n";
        cout << "a = " << power.a << endl << "b = " << power.b << endl
        << "calculate (a^b) = " << power.calculate(power) << endl;
    }
};

class RGBA{
private:
    uint16_t m_red;
    uint16_t m_blue;
    uint16_t m_green;
    uint16_t m_alpha;
public:
    RGBA (uint16_t red = 0, uint16_t blue = 0, uint16_t green = 0, uint16_t alpha = 255)
        : m_red(red), m_blue(blue), m_green(green), m_alpha(alpha)
    {
    }
    void rgbaPrint (RGBA &rgba){
        cout << "RGBA print: "<< endl << "m_red = "<< rgba.m_red << "  " << "m_blue = " << rgba.m_blue
        << "  " << "m_green = " << rgba.m_green << "  "  << "m_alpha = " << rgba.m_alpha << endl;
    }
};

class Stack {
private:
    int arr[10];
    int length = 0;
public:
    void reset(Stack &stack){
        for(int i = 0; i <10; i++) stack.arr[i] = 0;
        stack.length = 0;
    }

    bool push(Stack &stack, int valueI){
        if(stack.length >=0 && stack.length < 10) {
        stack.arr[stack.length] = valueI;
        stack.length++;
        return true;
        }
        else {
            return false;
        }

    }
    int pop(Stack &stack){
        int result;
        result = stack.arr[stack.length-1];
        arr[stack.length-1] = 0;
        stack.length--;
        if (stack.length == 0) cout << "POP: В стеке нет значений!\n";
        return result;
    }
    void stackPrint(Stack &stack){
        if (stack.length != 0) {
            cout << "( ";
            for (int i = 0; i < stack.length; i++) cout << stack.arr[i] << " ";
            cout <<")"<< endl;
        }
        else{
        cout << "( )" << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    char repeat;
m0:
    puts("Задача 1.");
    Power power1;
    float valueA, valueB;
    power1.powerPrint(power1);
    cout << "Введите новые значения a и b: ";
    cin >> valueA >> valueB;
    power1.set(valueA, valueB);
    power1.powerPrint(power1);
    puts(" ");

    puts("Задача 2.");
    uint16_t red, blue, green, alpha;
    cout << "Введите значения от 0 до 255 для m_red, m_blue, m_green, m_alpha:\n";
    cin >> red >> blue >> green >> alpha;
    RGBA rgba1(red, blue, green, alpha);
    rgba1.rgbaPrint(rgba1);
    puts(" ");

    puts("Задача 3.");
    Stack stack1;
    stack1.reset(stack1);
    stack1.stackPrint(stack1);
    stack1.push(stack1, 3);
    stack1.push(stack1, 7);
    stack1.push(stack1, 5);
    stack1.stackPrint(stack1);
    stack1.pop(stack1);
    stack1.stackPrint(stack1);
    stack1.pop(stack1);
    stack1.pop(stack1);
    stack1.stackPrint(stack1);

    cout << "Repeat the programm? (y/n): ";
    cin >> repeat;
    if (repeat == 'y' || repeat == 'Y') goto m0;
    return 0;
}

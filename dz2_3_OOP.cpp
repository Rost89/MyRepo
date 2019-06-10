/*Карпенко Р.
Задача 3.
Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
У Fruit есть две переменные-члена: name (имя) и color (цвет). Добавить новый класс GrannySmith,
который наследует класс Apple.

    int main()
    {
    Apple a("red");
    Banana b;
    GrannySmith c;

std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

return 0;
}

Код, приведенный выше, должен давать следующий результат:
My apple is red.
My banana is yellow.
My Granny Smith apple is green.*/

#include <iostream>
#include <locale>

using namespace std;

class Fruit {
private:
    string name;
    string color;
public:
    Fruit(string n = "", string c = "")
    :name(n), color(c)
    {
    }
    string getName() {
        return name;
    }
    string getColor() {
        return color;
    }
};

class Apple : public Fruit {
public:
    Apple(string n = "apple", string c = "red")
    :Fruit(n,c)
    {

    }

};
class Banana : public Fruit {
public:
    Banana(string n = "banana", string c = "yellow")
    :Fruit(n, c)
    {

    }

};
class GrannySmith : public Apple {
public:
    GrannySmith(string n = "granny smith", string c = "green")
        :Apple(n, c)
    {

    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    char sym;
    Apple a;
    Banana b;
    GrannySmith c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    cin >> sym;
    return 0;
}

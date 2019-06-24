/*Карпенко Р

Задача 2.

Создайте контейнерный класс, реализующий модель очереди. В нем должны быть методы:
void push(int x); // добавить элемент х в конец очереди
int size(); // узнать количество элементов в очереди
int front(); // вернуть первый элемент в очереди
int back(); // вернуть последний элемент в очереди
void pop(); // удалить первый элемент в очереди
*/

#include <iostream>
#include <locale>
#include <queue>

using namespace std;

class QueueInt {
private:
    queue <int> q;
public:
    QueueInt(){}
    void push(int x){q.push(x);}
    int size(){return q.size();}
    int front (){return q.front();}
    int back(){return q.back();}
    void pop(){q.pop();}
};

int main()
{

    setlocale(LC_ALL,"rus");
    QueueInt myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    cout << "Количество элементов в очереди: " << myQueue.size() << endl;
    cout << "Вот первый: " << myQueue.front() << endl;
    cout << "Вот последний: " << myQueue.back() << endl;
    myQueue.pop();
    cout << "Количество элементов в очереди: " << myQueue.size() << endl;
    cout << "Вот первый: " << myQueue.front() << endl;
    cout << "Вот последний: " << myQueue.back() << endl;

    char sym;
    cin >> sym;
    return 0;
}

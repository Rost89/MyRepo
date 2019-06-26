/*
Карпенко Р.

Задача 1.
Реализовать шаблон класса Pair1, который позволяет пользователю
передавать данные одного типа парами.
Следующий код:
*/

#include <iostream>
#include <locale>

using namespace std;

template<typename T>
class Pair {
private:
	T first;
	T second;
public:
	Pair() : first(0), second(0) { }
	Pair(T f, T s) : first(f), second(s){ }
	T getFirst() { return first; }
	T getSecond() { return second; }
};

int main() {
	setlocale(LC_ALL, "rus");

	Pair<int> p1(6,9);
	cout << "Pair: " << p1.getFirst() << " " << p1.getSecond() << endl;
	Pair<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.getFirst() << " " << p2.getSecond() << endl;
	char sym;
	cin >> sym;
	return 0;
}
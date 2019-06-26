/*
Карпенко Р.

Задача 2.
Реализовать класс Pair, который позволяет использовать разные типы данных в
передаваемых парах.
*/

#include <iostream>
#include <locale>

using namespace std;

template<typename T, typename U>
class Pair {
private:
	T first;
	U second;
public:
	Pair() : first(0), second(0) { }
	Pair(T f, U s) : first(f), second(s) { }
	T getFirst() { return first; }
	U getSecond() { return second; }
};

int main() {
	setlocale(LC_ALL, "rus");

	Pair<int, double> p1(6, 7.8);
	cout << "Pair: " << p1.getFirst() << " " << p1.getSecond() << endl;
	Pair<double, int > p2(3.4, 5);
	cout << "Pair: " << p2.getFirst() << " " << p2.getSecond() << endl;

	char sym;
	cin >> sym;
	return 0;
}
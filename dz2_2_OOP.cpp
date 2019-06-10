/*Карпенко Р.
Задача 2.
Создать класс Person (человек) с полями: имя, возраст, пол и вес.
Определить методы переназначения имени, изменения возраста и веса. Создать производный класс Student (студент), 
имеющий поле года обучения. Определить методы переназначения и увеличения этого значения.*/

#include <iostream>
#include <locale>

using namespace std;

class Person {
private:
	string name;
	int age;
	int weight;
public:
	Person(string n = "", int a = 0, int w = 0)
		: name(n), age(a), weight(w)
	{
	}
	void setName(string n) {
		name = n;
	}
	void setAge(int a) {
		age = a;
	}
	void setWeight(int w) {
		weight = w;
	}
	void PrintInfo() {
		cout << "Имя: " << name << endl;
		cout << "Возраст: " << age << endl;
		cout << "Вес: " << weight << endl;
	}
};

class Student : public Person {
private:
	int yearOfTraining;

public:
	Student(int y = 0, string n = "", int a = 0, int w = 0) 
		: yearOfTraining(y), Person(n, a, w)
	{
	}
	void setYearOfTraining(int y) {
		yearOfTraining = y;
	}
	void printYearOfTraining() {
		cout << "Год обучения: " << yearOfTraining << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	char sym = 'n';
	do {

		Person human1;
		cout << "Укажите имя, возраст и вес для класса Person: " << endl;
		string n;
		int a;
		int w;
		cin >> n >> a >> w;
		human1.setName(n);
		human1.setAge(a);
		human1.setWeight(w);
		human1.PrintInfo();
		Student student1;
		cout << "Укажите имя, возраст, вес и год обучения для класса Student: " << endl;
		int y;
		cin >> n >> a >> w >> y;
		student1.setName(n);
		student1.setAge(a);
		student1.setWeight(w);
		student1.setYearOfTraining(y);
		student1.PrintInfo();
		student1.printYearOfTraining();
		cout << "Начать заново?" << endl;
		cin >> sym;
	} while (sym == 'y' || sym == 'Y');
	return 0;
}


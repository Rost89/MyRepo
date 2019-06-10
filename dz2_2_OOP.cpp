/*�������� �.
������ 2.
������� ����� Person (�������) � ������: ���, �������, ��� � ���.
���������� ������ �������������� �����, ��������� �������� � ����. ������� ����������� ����� Student (�������), 
������� ���� ���� ��������. ���������� ������ �������������� � ���������� ����� ��������.*/

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
		cout << "���: " << name << endl;
		cout << "�������: " << age << endl;
		cout << "���: " << weight << endl;
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
		cout << "��� ��������: " << yearOfTraining << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	char sym = 'n';
	do {

		Person human1;
		cout << "������� ���, ������� � ��� ��� ������ Person: " << endl;
		string n;
		int a;
		int w;
		cin >> n >> a >> w;
		human1.setName(n);
		human1.setAge(a);
		human1.setWeight(w);
		human1.PrintInfo();
		Student student1;
		cout << "������� ���, �������, ��� � ��� �������� ��� ������ Student: " << endl;
		int y;
		cin >> n >> a >> w >> y;
		student1.setName(n);
		student1.setAge(a);
		student1.setWeight(w);
		student1.setYearOfTraining(y);
		student1.PrintInfo();
		student1.printYearOfTraining();
		cout << "������ ������?" << endl;
		cin >> sym;
	} while (sym == 'y' || sym == 'Y');
	return 0;
}


/*Карпенко Р.
Создайте класс, который будет генерировать рандомные числа. У этого класса должны быть обязательно два константных метода:
один из них (Current) должен возвращать текущее сгенерированное число, второй (Next) - следующее случайное число.
Если самым первым методом вызвать Current, то выдать предупреждение, что число не сгенерировано еще. 
В классе должен быть конструктор по умолчанию, с параметрами, а также копирующий конструктор. Создать кэширование 
текущего случайного числа. (Подсказка: чтобы константный метод мог все - таки изменять кэшируемое значение,
переменную необходимо объявить с помощью ключевого слова mutable).*/

#include <iostream>
#include <time.h>

using namespace std;
class genRand {
private:
	int rand;
	mutable bool flag1;
	mutable bool flag2;
public:
	genRand(int r = 0, bool f1 = false, bool f2 = false) :
		rand(r), flag1(f1), flag2(f2) {
		//конструктор копирования
	}
	void setRand(int a) {
		rand = a;
		flag1 = true;
		flag2 = true;
	}
	int current() const{
		if (flag2 == 0) {
			cout << "Число не сгенерировано!" << endl;
		}
		else {
			return rand;
		}
	}
	int next() const{
		return rand;
	}
	void result() {
		if (flag1 == 0) {
			cout << current() << endl;
		}
		else {
			cout << next() << endl;
			flag1 = false;
		}
	}
};

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	char sym = 'n';
	
	genRand rand1;
	rand1.current();

	do {
		rand1.setRand(rand());
		rand1.result();
		cout << "Repeat rand()? (y/n)";
		cin >> sym;
	} while (sym == 'y'|| sym == 'Y');
	return 0;
}
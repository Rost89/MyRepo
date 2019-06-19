/*
Карпенко Р.

Задача 3.

Создать абстрактный класс Fraction (дробь). От него наследуют два класса: SimpleFraction (обыкновенная дробь)
и MixedFraction (смешанная дробь). Обыкновенная дробь имеет только числитель и знаменатель (например, 3/7 или 9/2),
а смешанная — еще и целую часть (например, 312 ). Предусмотреть, чтобы знаменатель не был равен 0.
Перегрузить математические бинарные операторы (+, -, *, /) для выполнения действий с дробями, а также унарный оператор (-).
Перегрузить логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.

*/
#include <iostream>
#include <locale>

using namespace std;

class Fraction{
protected:
public:
    Fraction (){ }
    virtual void getResult() = 0;
};

class SimpleFraction: public Fraction{
private:
    int numerator;
    int denominator;
public:
    SimpleFraction (int n = 1, int d = 1)
        :numerator(n), denominator(d){ }
    void setFraction() {
    cout << "Введите числитель и знаменатель простой дроби: ";
    cin >> numerator >> denominator;
    while (denominator == 0) {
        cout << "Знаменатель должен быть НЕ ноль! Повторите ввод знаменателя: ";
        cin >> denominator;
    }

    }
    void getFraction(){
        cout << numerator << "/" << denominator << "  ";
    }
    void getResult(){
        if (numerator/denominator >= 1){
        cout << "Результат: Cмешанная дробь вида: " << numerator/denominator <<" "<< numerator%denominator<< "/" << denominator << endl;
        }
        else{
         cout << "Простая дробь вида: " << " " << numerator <<"/" << denominator << endl;
       }
  }
SimpleFraction operator+ (SimpleFraction);
bool operator>= (SimpleFraction);
};
SimpleFraction SimpleFraction::operator+ (SimpleFraction sfr2){
    int n = ((numerator * sfr2.denominator) + (sfr2.numerator * denominator));
    int d = denominator * sfr2.denominator;
    return SimpleFraction (n,d);
}
bool SimpleFraction::operator>=(SimpleFraction sfr2){
    if ((numerator * sfr2.denominator)>=(sfr2.numerator * denominator)) {
        return 1;
    }
    else {
        return 0;
    }
}

class MixedFraction: public Fraction {
private:
    int number;
    int numerator;
    int denominator;
public:
    MixedFraction(int num=1, int n=1, int d=1)
        :number(num), numerator(n), denominator(d)
    { }
    void setFraction() {
    cout << "Введите целую часть, числитель и знаменатель простой дроби: ";
    cin >> number >> numerator >> denominator;
    while (denominator == 0) {
        cout << "Знаменатель должен быть НЕ ноль! Повторите ввод знаменателя: ";
        cin >> denominator;
    }
    }
    void getFraction() {
    cout << number << " " << numerator <<"/" << denominator << endl;
    }
    void getResult(){
        if (number >= 1 || number <= (-1)){
        cout << "Результат: Cмешанная дробь вида: " << number <<" "<< numerator%denominator<< "/" << denominator << endl;
        }
        else{
         cout << "Простая дробь вида: " << " " << numerator <<"/" << denominator << endl;
       }
  }
MixedFraction operator- (MixedFraction);
};
MixedFraction MixedFraction:: operator-(MixedFraction mfr2){
    int n = ((number*denominator+numerator)*mfr2.denominator) - (mfr2.number*mfr2.denominator+mfr2.numerator)*denominator;
    int d = denominator * mfr2.denominator;
    int num = n/d;
    if (num < 0){
        n = n*(-1);
    }
    return MixedFraction(num,n,d);
}

int main()
{
    setlocale(LC_ALL, "rus");
    SimpleFraction sfr1,sfr2,sfr3(5,8),sfr4(5,10);
    sfr1.setFraction();
    sfr2.setFraction();
    cout << "Исходные данные для SimpleFraction:\n";
    sfr1.getFraction();
    sfr2.getFraction();
    sfr3.getFraction();
    sfr4 = sfr3+sfr1+sfr2;
    Fraction *s = &sfr4;
    s->getResult();

    cout << "Сравним простые дроби:\n";
    if(sfr1>=sfr2){
        sfr1.getFraction(); cout << "больше либо равна дроби "; sfr2.getFraction();
    }
    else {
        sfr1.getFraction();
        cout << "меньше чем дробь "; sfr2.getFraction();
    }

    cout << "\nИсходные данные для MixedFraction:\n";
    MixedFraction mfr1(3,1,4), mfr2(1,1,3), mfr3(2,1,5);
    mfr1.getFraction();
    mfr2.getFraction();
    mfr3.getFraction();
    mfr3 = mfr2 - mfr1;
    Fraction *m = &mfr3;
    m->getResult();


    char sym;
    cin >> sym;
    return 0;
}

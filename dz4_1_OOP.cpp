/*
Карпенко Р.

Задача 1.

Добавить методы в контейнер из лекции к 4 уроку.

*/

#include <iostream>
#include <locale>
#include <cassert>

using namespace std;

class ArrayInt {
private:
    int length;
    int *data;
public:
    ArrayInt(): length(0), data(nullptr){
    }
    ArrayInt(int l) : length(l){
        assert(length > 0);
        if (length > 0){
            data = new int(length);
        }
        else{
            data = nullptr;
        }
    }
    ~ArrayInt(){
        delete[] data;
    }
    void erase(){
        delete[] data;
        data = nullptr;
        length = 0;
    }
    int& operator[] (int index){
        assert(index > 0 && index < length);
        return data[index];

    }
    int getLength(){
        return length;
    }
    void resize(int newLength){                     //меняет размер массива
        if (newLength == length) return;
        if (newLength <= 0){
            erase();
            return;
        }
        int *newData = new int [newLength];
        if (length > 0) {
            int elements = (newLength > length) ? length : newLength;
            for (int index = 0; index < elements; index++){
                newData[index] = data[index];
            }
        }
        delete[] data;
        data = newData;
        length = newLength;
    }
    void insertBefore(int value, int index){  //вставка элемента по индексу
        assert(index >= 0 && index < length);
        int *newData = new int [length+1];

        for(int i = 0; i < index; i++){
            newData[i] = data[i];
        }
        newData[index] = value;
        for (int i = index+1; i < length; i++){
            newData[i] = data[i];
        }
        newData[length] = 0;
        delete[] data;
        data = newData;
        length++;
    }
    void push_back(int value){                     //вставка в конец массива
        int *newData = new int [length+1];
        for(int i = 0; i < length+1; i++){
            newData[i] = data[i];
        }
        newData[length] = value;
        delete[] data;
        data = newData;
        length++;
    }
    void deleteValue (int index){        //удаляет элемент с куском массива
        int *newData = new int [length-1];

        for(int i = 0; i < index; i++){
            newData[i] = data[i];
        }
        for (int i = index; i < length-1; i++){
            newData[i] = data[i+1];
        }
        delete[] data;
        data = newData;
        length--;
    }
    void pop_back(){                       //удаляет последний элемент массива
        int *newData = new int [length-1];
        for (int i = 0; i < length-1; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        length--;
    }
    void printArray(){
        for(int i = 0; i < length; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
    void nullArray() {
        for (int i = 0; i < length; i++){
            data[i] = 0;
        }
    }


};

int main()
{
    setlocale(LC_ALL, "rus");
/*
    ArrayInt array1(10);
    cout << array1.getLength();
    array1.printArray();
    array1.insertBefore(111, 5);
    array1.printArray();
    array1.insertBefore(111, 0);
    array1.push_back(555);
    array1.printArray();
    array1.deleteValue(5);
    array1.deleteValue(0);
    array1.printArray();
    array1.pop_back();
    array1.pop_back();
    array1.pop_back();
    array1.pop_back();
    array1.pop_back();
    array1.printArray();*/

    ArrayInt arr1;
    arr1.resize(5);
    cout << "Создали массив длинной " << arr1.getLength() << endl;

    cout << "Добавили в него 5 элементов по индексу: " << endl;
    arr1.insertBefore(11,0);
    arr1.insertBefore(22,1);
    arr1.insertBefore(33,2);
    arr1.insertBefore(44,3);
    arr1.insertBefore(55,4);
    arr1.printArray();

    cout << "Добавили в него 2 элементa в конец: " << endl;
    arr1.push_back(55);
    arr1.push_back(66);
    arr1.printArray();

    cout << "Удалили из него 3 элементa с индексами 2, 5, 11: " << endl;
    arr1.deleteValue(2);
    arr1.deleteValue(5);
    arr1.deleteValue(11);
    arr1.printArray();

    cout << "Удалили из него 3 элементa с конца: " << endl;
    arr1.pop_back();
    arr1.pop_back();
    arr1.pop_back();
    arr1.printArray();

    char sym;
    cin >> sym;
    return 0;
}

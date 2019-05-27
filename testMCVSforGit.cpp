#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

    cout << "Тест русской локализации.\n"; 
	system("pause");
}

#include <iostream>
#include <locale>

using namespace std;

int main()
{	
	setlocale(LC_ALL, "rus");
	char repeat;
m0:
	
	cout << "Repeat the programm? (y/n): ";
	cin >> repeat;
	if (repeat == 'y' || repeat == 'Y') goto m0;
	return 0;
}

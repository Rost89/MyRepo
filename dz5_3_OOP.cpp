/*
�������� �.

������ 3.
�������� ������ ������ StringValuePair , � ������� ������ �������� ������ ���� string, �
������ � ������ ����. ���� ������ ������ ������ ����������� ��������
������������������ ����� Pair, � ������� ������ �������� � string , � ������ � ������
���� ������.
*/

#include <iostream>
#include <string>
using namespace std;

template <class T, class S>
class Pair
{
private:
	T first;
	S second;
public:
	Pair(const T& f, const S& s)
		: first(f), second(s){ }
	const T& getFirst() { return first; }
	const S& getSecond() { return second; }
};
template <class S>
class StringValuePair : public Pair<string, S> {
public:
	StringValuePair(const string& f1, const S& s1)
		: Pair<string, S>(f1, s1) { }
};
int main()
{
	StringValuePair<int> svp("Amazing", 7);
	cout << "Pair: " << svp.getFirst() << " " << svp.getSecond() << endl;

	char sym;
	cin >> sym;
	return 0;
}
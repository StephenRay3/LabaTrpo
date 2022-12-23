#include <iostream>
using namespace std;

int main() {
	

setlocale(LC_ALL, "Rus");
	int A, B;
	cout << "A:";
	cin >> A;
	cout << "B:";
	cin >> B;
	if (A * 2 == 0 && B % 2 == 0 || A % 2 != 0 && B % 2 != 0) {
		cout << "Истинно";
	}
	else
	{
		cout << "Ложь";
	}

	

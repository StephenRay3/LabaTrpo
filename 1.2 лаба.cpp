/*#include <iostream>
using namespace   std;  
int main()
{
	int R;
	bool A = 1;	
	bool B = 0;
	bool C = 1;
		R = (A || !(A && B) || C);
		setlocale(LC_ALL, "RUS");
		cout << "Верно или Неверно:" << R;
		return 0;

}*/

/*#include <iostream>
using namespace std;
int main()
{
	int R;
	bool A = 1;
	bool B = 0;
	bool C = 1;
	R = (A || C && !(B || C));
	setlocale(LC_ALL, "RUS");
	cout << "Верно или Неверно:" << R;
	return 0;

}*/
 
#include <iostream>
using namespace std;
int main()
{
	int R;
	bool A = 0;
	bool B = 0;
	bool C = 1;
	R = ((A || B && !C) || A);
	setlocale(LC_ALL, "RUS");
	cout << "Верно или Неверно:" << R;
	return 0;

}

#include <iostream>
using namespace std;

int main() {
	int i = 2;
	int *p = &i;
	int **q = &p;
	int *&r = p;

	cout << "i:" << i << endl;
	cout << "*p:" << *p << endl;
	cout << "p:" << p << endl;
	cout << "&p:" << &p << endl;
	cout << "*q:" << *q << endl;
	cout << "**q:" << **q << endl;
	cout << "&*q:" <<  &*q << endl;
	cout << "*r:" << *r << endl;
	cout << "r:" << r << endl;
	cout << "&r:" << &r << endl;
	cout << "xy is using ConEmu VIM !" << endl;

	return 0;
}

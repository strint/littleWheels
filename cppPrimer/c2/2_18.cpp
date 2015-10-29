#include <iostream>
using namespace std;

int main() {
	int i = 1;
	int j = 2;
	int *p = 0;

	p = &i;
	cout << p << endl;
	cout << *p << endl;
	p = &j;
	cout << p << endl;
	*p += 1;
	cout << j << endl;

	return 0;
}

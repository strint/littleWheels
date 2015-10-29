#include <iostream>
using namespace std;

int main() {
	//2_15
	int ival;
	int &rval = ival;
	rval = 1;
	cout << rval << " " << ival << endl;
	
	//2_16
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;
	r2 = 3.14159;
	cout << r2 << endl; //3.14159
	r2 = r1;
	cout << r2 << endl; //0
	i = r2;
	cout << i << endl;//0
	r1 = d;
	cout << r1 << endl;//0
	
	//2_17
	int j, &rj = j;
	j = 5;
	rj = 10;
	cout << j << " " << rj << endl;


	return 0;
}

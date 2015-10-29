#include <iostream>
#include <math.h>
using namespace std;

int main() {
	//2_3
	unsigned u = 10, u2 = 42;
	cout << u2 - u << endl;//32
	cout << u - u2 << endl;//4294967264
	long long _2e32 = pow(2, 32);
	cout << _2e32 - 32 << endl; //4294967264

	int i = 10, i2 = u2;
	cout << i2 - i << endl;//32
	cout << i - i2 << endl;//-32
	cout << i - u << endl;//0
	cout << u - i << endl;//0
	
	//2_6
	int month = 011;
	int day = 07;
	cout << month << " " << day << endl;//9;7
	
	//2_7_a
	cout << "\145" << " " << "\012";//e; /n
	
	//2_7_b
	cout << 3.14e1L << endl;//31.4; long double
	cout << 1024.0F << endl;//1024; float
	cout << 3.14L << endl;//3.14; long double

	//2_8
	cout << "2\115\12";
	cout << "2\t\x4d\12";	

	//2_9
	//cin >> int input_value;//error
	int j = { 3.14 };	
	cout << j << endl;//3

	//double salary = wage = 9999.99;//[Error] 'wage' was not declared in this scope

	int k = 3.14;





	return 0;
}

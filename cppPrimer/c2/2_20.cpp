#include <iostream>
using namespace std;

int main() {
	int i = 42;
	int *p = &i;
	*p = *p * *p;//1764
	//double *dp = &i;
	//int *ip = i;
	
	cout << i << endl;
	
	if(-1) cout << "-1, true" << endl;
	if(3) cout << "3, true" << endl;
	if(0) cout << "0, true" << endl;
	
	return 0;
}

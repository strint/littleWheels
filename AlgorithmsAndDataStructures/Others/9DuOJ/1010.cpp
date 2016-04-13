#include <iostream>
using namespace std;

int trans(string); 

int main() {
	string s;
	int a,b,c,d;
	int flag = 1;
	while(flag) {
		a = 0;
		b = 0;
		c = 0;
		d = 0;

		cin >> s;
		b = trans(s);
		cin >> s;
		if(trans(s) != -1) {
			a = b;
			b = trans(s);
			
			cin >> s;
			cin >> s;
			d = trans(s);
			cin >> s;
			if(trans(s) != -2) {
				c = d;
				d = trans(s);
				
				cin >> s;
				cout << a*10 + b + c*10 + d << endl;
			} else {
				cout << a*10 + b + d << endl;
			}
		} else {
			cin >> s;
			d = trans(s);
			cin >> s;
			if(trans(s) != -2) {
				c = d;
				d = trans(s);
				
				cin >> s;
				cout << b + c*10 + d << endl;
			} else {
				int sum = b + d;
				if (sum == 0) {
				       flag = 0;
				} else {
					cout << sum << endl;
				}
			}

		}	

	}	
	return 0;
}

int trans(string s) {
	if(s == "zero")	return 0;
	else if(s == "one") return 1;
	else if(s == "two") return 2;
	else if(s == "three") return 3;
	else if(s == "four") return 4;
	else if(s == "five") return 5;
	else if(s == "six") return 6;
	else if(s == "seven") return 7;
	else if(s == "eight") return 8;
	else if(s == "nine") return 9;
	else if(s == "+") return -1;
	else if(s == "=") return -2;
	else return -3;
}	

#include <iostream>
using namespace std;

int main() {
	string str1, str2;
	int a[9] = {0};
	int s2;
	while(cin >> str1 >> str2) {
		for(int i=0; i<str1.length(); i++) {
			cout << str1[i] - '0' << endl;
			a[str1[i] - '0' - 1]++;
		}	
		if(str2.length() < 5) {
			s2 = str2[0] - '0';
			int count = 0;
			for(int i=s2; i<9; i++) {
				if(a[i] >= str2.length()) {
					cout << "YES" << endl;
					count++;
					break;
				}
			}
			if(count == 0) cout << "NO" << endl;
		} else {
			s2 = str2[0] - '0';	
			if(s2 == 5) {
				cout << "NO" << endl;
			} else {

			}
		}
	}
	return 0;	
}

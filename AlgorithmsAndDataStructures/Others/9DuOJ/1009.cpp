#include <iostream>
using namespace std;
int a[1024];
int b[1024];

void create_tree(string s, int c[]) {
	int len = s.length();
	for(int i=0; i < len; i++) {
		int temp = s[i] - '0';
		for(int j=1; j<1024;) {
			if(c[j] == -1) {
				c[j] = temp;
			} else {
				if(c[j] > temp) {
					j = 2 * j;
				} else {
					j = 2 * j + 1;
				}
			}
		}
	}
}

int main() {
	int n, count;
	string s, t;
	while(cin >> n && n) {
		cin >> s;
		for(int m=0; m<1024; m++) a[m] = -1;
		create_tree(s, a);
		for(int i=0; i<n; i++) {
			cin >> t; 
			for(int l=0; l<1024; l++) b[l] = -1;
			create_tree(t, b);
			count = 0;
			for(int j=0; j<1024; j++) {
				if(a[j] == b[j]) {
					count++;
				} else break;
			}
			if(count == 1024) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}


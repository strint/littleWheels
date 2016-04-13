#include <iostream>
using namespace std;

int main() {
	int a[10000] = {0};
	int k;
	int max = 0;
	int max_head = 0;
	int max_end = 0;
	int max_i = 0;
	int max_i_head = 0; 

	while(cin >> k && k) {
		max = 0;
		max_head = 0;
		max_end = 0;
		max_i = 0;
		max_i_head = 0; 
		for(int i=0; i<k; i++) {
			cin >> a[i];
			if(max_i >= 0) {
				max_i += a[i];
				if(max_i > max) {
					max = max_i;
					max_head = max_i_head;
					max_end = i;
				}
			} else {
				max_i = a[i];
				max_i_head = i;	
			}	
		}
		if(max > 0) {
			cout << max << " " << a[max_head] << " " << a[max_end] << endl;
		} else if(max == 0) {
			cout << 0 << " " << 0 << " " << 0 << endl;
		} else {
			cout << 0 << a[0] << " " << a[k-1] << " " << endl;
		}
	}
	return 0;
}

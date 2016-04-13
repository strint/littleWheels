#include <iostream>
using namespace std;
  
int main() {
    int n, k;
    int a[1000];
    while(cin >> n && n) {
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        cin >> k;
        int flag = 1;
        int count = 0;
        while(count < k) {
            for(int i=n-1; i>=flag; i--) {
                if(a[i] < a[i-1]) {
                    int temp = a[i-1];
                    a[i-1] = a[i];  
                    a[i] = temp;
                }
            }
            if(flag == 1) count++;
            if(flag > 1 && a[flag-1] != a[flag-2]) {
                count++;
            }
            flag++; 
        }
        cout << a[flag-2] << endl; 
    }
    return 0;
}

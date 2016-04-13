#include <iostream>
using namespace std;
 
int main() {
    int n;
    int a[2000];
    int small = 0;
    while(cin >> n && n) {
        small = 0;
        for(int i=0; i<n; i++) {
            cin >> a[2*i];
            cin >> a[2*i + 1];
            if(i > 0) {
                if(a[2*i] < a[2*small]) {
                    small = i;
                } else if(a[2*i] == a[2*small]) {
                    if(a[2*i+1] < a[2*small+1]) {
                        small = i;
                    }
                }
            }
        }   
        cout << a[2*small] << " " << a[2*small+1] << endl;
    }
    return 0;
}

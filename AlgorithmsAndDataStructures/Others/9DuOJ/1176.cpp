#include <iostream>
#include <math.h>
using namespace std;
 
int main() {
    int n, d;
    int tree[1000];
    while(cin >> n && n){
        for(int i=0; i<n; i++) {
            cin >> tree[i];
        }
        cin >> d;
        int start = pow(2.0, d - 1.0) - 1;
        int end = start + pow(2.0, d - 1.0) - 1;        
        if(n-1 < start) {
            cout << "EMPTY" << endl;
        } else if(n-1 >= end) {
            for(int i=start; i<=end; i++) {
                cout << tree[i];
                if(i < end) cout << " ";
            }
        } else {
            for(int i=start; i<=n-1; i++) { 
                cout << tree[i];
                if(i < n-1) cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

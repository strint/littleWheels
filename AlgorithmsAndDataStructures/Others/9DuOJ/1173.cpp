#include <iostream>
using namespace std;
 
int main() {
    int a[100];
    int b[100]; 
    int n, m, count;
    while(cin >> n && n) {
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        cin >> m;
        for(int j=0; j<m; j++) {
            cin >> b[j];
        }   
        for(int j=0; j<m; j++) {
            count = 0;
            for(int i=0; i<n; i++) {
                if(a[i] == b[j]) count++;
            }
            if(count > 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}

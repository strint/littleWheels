/*
USER_ID: bupt#100134111310397
PROBLEM: 277
SUBMISSION_TIME: 2014-04-04 14:49:56
*/
#include <iostream>
using namespace std;
 
int main() {
    int t, n, m, dis;
    int N[100], M[100], NS[100]={0};
    int got = 0;
    int sm = 0;
    int po = 0;
     
    cin >> t;
    for(int i=0; i<t; i++) {
            dis = 0;
            for(int p=0; p<100; p++) NS[p] = 0;
             
            cin >> n;
            for(int j=0; j<n; j++) {
                    cin >> N[j];
                    }
            cin >> m;
            for(int k=0; k<m; k++) {
                    cin >> M[k];
                    }
                     
            for(int k=0; k<m; k++) {
                    got = 0;
                    sm = 0;
                    po = 0;
                     
                    for(int l=0; l<n; l++){
                            if(NS[l] == 0 && N[l] >= M[k]){
                                     dis = N[l] - M[k];
                                     if(got == 0){
                                            sm = dis;
                                            po = l;
                                            }
                                     got = 1;
                                     if(dis < sm) {
                                            sm = dis;
                                            po = l;
                                            }
                                      
                                      
                                     }
                             
                            }
                     
                    if(got == 0) {
                           cout << "NULL";
                           if(k < m-1) cout << " ";
                           //else cout << endl;
                           }
                    else {
                         cout << N[po];
                         if(k < m-1) cout << " ";
                         //else cout << endl;
                         }
                         }
             
            }
     
    return 0;  
}

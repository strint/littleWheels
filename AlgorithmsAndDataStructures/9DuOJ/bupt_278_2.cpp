/*
USER_ID: bupt#100134111310397
PROBLEM: 278
SUBMISSION_TIME: 2014-04-04 15:58:03
*/
/*²¢²é¼¯*/
#include <iostream>
using namespace std;
int a[10000] = {0};
int f[10000] = {0};
int area;
int Father(int p3){
     if(p3 != f[p3]) {
           f[p3] = Father(f[p3]);
           }
     return f[p3];
      
}
 
void Union(int p1, int p2){
     int x = Father(p1);
     int y = Father(p1);
     if(x != y) {
          if(x < y) f[y] = x;
          else f[x] = y;
           
          area--;
          }        
}
 
int main() {
    int t, n, m ,d;
    cin >> t;
    for(int i=0; i<t; i++){
            cin >> n;
            cin >> m;
            area = n*m;
            cin >> d;
            for(int j=0; j<n; j++) {
                    for(int k=0; k<m; k++) {
                            cin >> a[k + 100*j];
                            }
                    }
            for(int j=0; j<n; j++) {
                    for(int k=0; k<m; k++) {
                            f[k + 100*j] = k + 100*j;
                            }
                    }
            for(int j=0; j<n; j++) {
                    for(int k=0; k<m; k++) {
                            int po = k+100*j;
                            if((po-100 >= 0) && (po % 100 > 0 )&& ( ((a[po] - a[po-101]) <= d ) &&((a[po] - a[po-101]) >= -d ))){
                                      Union(po, po-101);
                                      }
                            if((po-100 >= 0) && ( ((a[po] - a[po-100]) <= d ) &&((a[po] - a[po-100]) >= -d ))){
                                      Union(po, po-100);
                                      }
                            if((po-100 >= 0) && (po % 100 < 99 )&& ( ((a[po] - a[po-99]) <= d ) &&((a[po] - a[po-99]) >= -d ))){
                                      Union(po, po-99);
                                      }
                            if((po % 100 > 0 )&& ( ((a[po] - a[po-1]) <= d ) &&((a[po] - a[po-1]) >= -d ))){
                                      Union(po, po-1);
                                      }
                            if((po % 100 < 99 )&& ( ((a[po] - a[po+1]) <= d ) &&((a[po] - a[po+1]) >= -d ))){
                                      Union(po, po+1);
                                      }
                            if((po+100 < 100*n) && (po % 100 > 0 )&& ( ((a[po] - a[po+99]) <= d ) &&((a[po] - a[po+99]) >= -d ))){
                                      Union(po, po+99);
                                      }
                            if((po+100 < 100*n) && ( ((a[po] - a[po+100]) <= d ) &&((a[po] - a[po+100]) >= -d ))){
                                      Union(po, po+100);
                                      }
                            if((po+100 < 100*n) && (po % 100 < 99 )&& ( ((a[po] - a[po+101]) <= d ) &&((a[po] - a[po+101]) >= -d ))){
                                      Union(po, po+101);
                                      }
                            }                                                                                                                                                                                                                        
                    }
            cout << area;
    }
 
    return 0;
}

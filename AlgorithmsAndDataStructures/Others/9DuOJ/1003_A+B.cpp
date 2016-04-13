#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
	string A;
	string B;
	//循环输入的方法
	while(cin >> A >> B){	

		for(int i = A.size() - 1; i >= 0; i--){
			if(A[i] == ','){
				A.erase(i, 1);	//去掉","			
			}
		}

		for(int i = B.size() - 1; i >= 0; i--){
			if(B[i] == ','){
				B.erase(i, 1);
			}
		}
		
		int a_int = atoi(A.c_str()); //将string转换为c string，再转为int
		int b_int = atoi(B.c_str());
		cout << a_int + b_int << endl;
	}

	return 0;
}

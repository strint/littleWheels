#include <iostream>
using namespace std;

int main() {
	int m, n;
	int A[10][10] = {0};
	int B[10][10] = {0};
	int S[10][10] = {0};
	
	cin >> m;
	while(m > 0) {
		cin >> n;
		
		int zero_count = 0;
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> A[i][j];
			}
		}
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> B[i][j];
				S[i][j] = A[i][j] + B[i][j];
			}
		}
		for(int i = 0; i < m; i++){
			int row_sum = 0;
			for(int j = 0; j < n; j++){
				row_sum += S[i][j];
			}
			if(row_sum == 0){
				zero_count++;
			}
		}
		for(int i = 0; i < n; i++){
			int column_sum = 0;
			for(int j = 0; j < m; j++){
				column_sum += S[j][i];
			}
			if(column_sum == 0){
				zero_count++;
			}
		}
		cout << zero_count << endl;
		
		cin >>  m;
	}
	
}

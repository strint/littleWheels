#include <iostream>
using namespace std;

int n, m;
int father[1001];

void iniSet(int n) {
	for(int i=0; i<=n; i++){
		father[i] = i;
	}
}

int findSet(int x) {
	if(x != father[x]) {
		father[x] = findSet(father[x]);
	}
	return father[x];
}

int unionSet(int a, int b, int &n) {
	int A = findSet(a);
	int B = findSet(b);
	if(A != B) {
		father[b] = A;
		n--;
	}
}

int main() {
	while(cin >> n && n) {
		cin >> m;
		iniSet(n);
		int a, b;
		for(int i=0; i < m; i++) {
			cin >> a >> b;
			unionSet(a, b, n);		
		}
		cout << n -1 << endl;
	}
	return 0;
}

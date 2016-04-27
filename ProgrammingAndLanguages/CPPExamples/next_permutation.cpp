#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> p;
	for(int i = 0; i < n; ++i) {
		p.push_back(i);
	}

	vector<vector<int> > ps;
	//生成全排列
	ps.push_back(p); //先保存当前的一种排列方式 
	while(next_permutation(p.begin(), p.end())) {//得到新的排列方式并保存下来
		ps.push_back(p);
	}
	system("pause");
	return 0;
}

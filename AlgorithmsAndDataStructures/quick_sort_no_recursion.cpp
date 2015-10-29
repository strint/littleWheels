#include <iostream>
#include <stack>
using namespace std;

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int *array, int left, int right) {
	int index = left - 1;
	int pivot = array[right];
	for(int i=left; i<right; i++) {
		if(array[i] <= pivot) {
			index++;
			swap(&array[index], &array[i]);//跟比pivot大的块中的第一个数字交换;
			for(int j=left; j<=right; j++)
				cout << array[j] << " ";
	        cout << endl;
		}
	}
	swap(&array[index + 1], &array[right]);
	for(int j=left; j<=right; j++)
		cout << array[j] << " ";
	cout << "$" << endl;
	return index + 1;
}
//partition做实际的排序，栈用来记录排序的起点、终点，使用栈完成了深度优先的排序。
void quick_sort(int *array, int start, int end) {
	stack<int> st;
	if(start < end) {
		int pivot = partition(array, start, end);
		if(start < pivot - 1) {
			st.push(start);
			st.push(pivot - 1);
		}
		if(end > pivot + 1) {
			st.push(pivot + 1);
			st.push(end);
		}
		while(!st.empty()) {
			int e = st.top();
			st.pop();
			int s = st.top();
			st.pop();
			if(s < e) {
				pivot = partition(array, s, e);
				if(s < pivot - 1) {
					st.push(s);
					st.push(pivot - 1);
				}
				if(e > pivot + 1) {
					st.push(pivot + 1);
					st.push(e);
				}
			}	
		}
	}
}

int main() {
	int n;
	cin >> n;

	int array[1000];
	
	for(int i=0; i<n; i++) {
		cin >> array[i];
	}

	quick_sort(array, 0, n-1);
	
	for(int i=0; i<n; i++) cout << array[i];

	return 0;
}

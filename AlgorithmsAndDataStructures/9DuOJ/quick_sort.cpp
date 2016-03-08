//算法导论版
#include <iostream>
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

void quick_sort(int *array, int start, int end) {
	if(start < end) {
		int pivot = partition(array, start, end);
		quick_sort(array, start, pivot - 1);
		quick_sort(array, pivot + 1, end);
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

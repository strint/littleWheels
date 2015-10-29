#include <iostream>
#include <vector>
#include <string>
#include "grid.h"
using namespace std;

int main() {
	grid<int> g(3, 3);
	cout << g.getAt(2, 2) << endl;
	g.getAt(2, 2) = 3;
	cout << g.getAt(2, 2) << endl;
	cout << "row:" << g.numRows() << "; col:" << g.numCols() << endl;
	cout << "empty?:" << g.empty() << endl;
	cout << "size:" << g.size() << endl;
	g.getAt(0, 0) = 1;
	cout << "*begin:" << *(g.begin()) << endl;
	cout << "*--end:" << *(--g.end()) << endl;
	g[1][2] = 2;
	cout << "g[1][2]: " << g[1][2] << endl;
	for(grid<int>::iterator it = g.begin(); it != g.end(); ++it) {
		cout << *it << ", ";
	}
	cout << endl;
	for(grid<int>::iterator it = g.begin(); it != g.end(); ++it) {
		*it = 5;
	}
	for(grid<int>::iterator it = g.begin(); it != g.end(); ++it) {
		cout << *it << ", ";
	}
	cout << endl;

	grid<int> g1(3,3);

	for(grid<int>::iterator it = g1.begin(); it != g1.end(); ++it) {
		cout << *it << ", ";
	}
	cout << endl;

	cout << (g1 < g) << endl;

	grid<int> g2(2, 3);
	
	cout << "g2 < g: " << (g2 < g) << endl;

	cout << "g2 != g: " << (g2 != g) << endl;

	system("pause");
	return 0;
}
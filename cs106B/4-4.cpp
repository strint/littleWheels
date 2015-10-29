#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream infile;
    cout << "Input filename: (you can input: file.cpp) " << endl;
	string path = "h:\\\\cs106bcodes\\4-4\\4-4\\";
    string filename;
    getline(cin, filename);
	filename = path + filename;
    infile.open(filename.c_str());
    cout << filename;
    char ch;
    while(infile.get(ch)) {
        cout.put(ch);
    }
	infile.unget();
	infile.get(ch);
	cout << "endl" << ch;
	cout << "endl" << ch;
	infile.close();
	cout << "----------------------" << endl;

	infile.open(filename.c_str());
	string line;
	while(getline(infile, line)){
		cout << line << endl;
	}
    infile.close();

	system("pause");
    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int stringToInteger(string str);

int main()
{
    ifstream infile;
    cout << "Input filename: (you can input: num.txt) " << endl;
	string path = "h:\\\\cs106bcodes\\4-3-2\\4-3-2\\";
    string filename;
    getline(cin, filename);
	filename = path + filename;
    infile.open(filename.c_str());

	if(infile){
		cout << "file open success" << endl;
	}
    
	int total = 0;
	string line;
	while(getline(infile, line)) {
		total += stringToInteger(line);
	}
	if(!infile.eof()) {
		cout << "Data erroe in the file." << endl;
	}
    infile.close();
	cout << "The sum is: " << total << endl;

	system("pause");
    return 0;
}

int stringToInteger(string str) {
	istringstream stream(str);
	int value;
	stream >> value >> ws;
	cout << value;
	if(stream.fail() || !stream.eof()) {
		cout << "Illegal integer format!" << endl;
	}
	return value;
}



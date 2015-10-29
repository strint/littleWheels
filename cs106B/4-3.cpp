#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream infile;
    cout << "Input filename: ";
    string filename;
    getline(cin, filename);
    infile.open(filename.c_str());
    cout << filename;
    char ch;
    while(infile.get(ch)) {
        cout.put(ch);
    }
    infile.close();

    return 0;
}


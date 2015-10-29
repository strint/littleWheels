#include <iostream>
#include <fstream>

const int NUM_LINES = 2;
const int NUM_COLUMNS = 3;
const int COLUMN_WIDTH = 20;

using namespace std;

int main() {
//    cout << "I'm sorry Dava." << endl;
//    cout << 137 << endl;
//    cout << 2.71828 << endl;
//    cout << "Here is a text followed by a number." << 31415 << endl;
//
//    cout << "Please enter an integer and a string:";
//    
//    int myInteger;
//    string myString;
//    cin >> myInteger >> myString;
//    cout << myInteger << myString << endl;
//
//    ifstream myStream("myFile.txt");
//    if(!myStream.is_open())
//        cerr << "Could not open the file: myFile.txt" << endl;
//
//    ofstream myStream2("myFileOut.txt");
//
//    myStream2 << myStream;
    PrintTableHeader();
    PrintTableBody();

    return 0;
}

void PrintTableBody() {
    ifstream input("myFile.txt");

    for(int k = 0; k < NUM_LINES; ++k) {
    }

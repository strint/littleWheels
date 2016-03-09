#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

void OpenUserFile(ifstream& fileStream);

string GetFileContents(ifstream& file);

map<string, size_t> GenerateKeywordReport(string contents);

int main() {
    ifstream input;
    OpenUserFile(input);

    map<string, size_t> report = GenerateKeywordReport(GetFileContents(input));

    for (map<string, size_t>::iterator itr = report.begin(); itr != report.end(); ++itr)
        cout << "Keyword " << itr->first << "occurred " << itr->second << " times." << endl;
}

void OpenUserFile(ifstream& input) {
    while(true) {
        cout << "Enter filename: ";
        string filename = GetLine();

        input.open(filename.c_str());
        if(input.is_open()) return;

        cout << "Sorry, I can't find the file" << filename << endl;
        input.clear();
    }
}

string GetLine () {
    string line;
    getline(input, line);
    return line;
}

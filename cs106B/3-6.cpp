#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string lineToPigLatin(string line);
string wordToPigLatin(string word);
int findFirstVowel(string word);
bool isVowel(char ch);

int main(){
	cout << "This program translate words into Pig Latin." << endl;
	string line;
	cout << "Enter the line to translate: ";
	getline(cin, line);
	string trans = lineToPigLatin(line);
	cout << trans << endl;

	system("pause");
	return 0;
}

string lineToPigLatin(string line) {
	string result;
	int start = -1;
	for( int i = 0 ; i < line.length(); i++){
		char ch = line[i];
		if( isalpha(ch) ) {
			if( start == -1 ) start = i; //如果是单词的开头，记录下来，否则往前扫描
		} else {
			if( start >= 0 ) {
			result += wordToPigLatin( line.substr(start, i - start) );
			start = -1;
			}
			result += ch; //标点、符号之类的
		}
	}
	if( start >= 0) result += wordToPigLatin(line.substr(start)); //最后一个单词
	return result;
}

string wordToPigLatin( string word ) {
	int vp = findFirstVowel( word);
	if( vp == -1 ) {
		return word;
	} else if ( vp == 0) {
		word += "way";
		return word;
	} else {
		string head = word.substr(0, vp - 1);
		string tail = word.substr(vp);
		return tail + head + "ay";
	}
}

int findFirstVowel( string word ) {
	int vp = 0;
	for(int i= 0; i < word.length(); i++){
		if(isVowel(word[i])) return i;
	}
	return -1;
}

bool isVowel( char ch ) {
	switch (ch) {
	case 'A': case 'E': case 'I': case 'O': case 'U':
	case 'a': case 'e': case 'i': case 'o': case 'u':
		return true;
	default:
		return false;
	}
}



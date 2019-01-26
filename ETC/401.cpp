#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

char convert(char c){
	if(c == '3') return 'E';
	else if(c == 'E') return '3';
	else if(c == 'J') return 'L';
	else if(c == 'L') return 'J';
	else if(c == 'S') return '2';
	else if(c == '2') return 'S';
	else if(c == 'Z') return '5';
	else if(c == '5') return 'Z';
	else return c;
}


bool mirrored(string& line) {
	int l = line.size();
	string b = "";
	for(int j = 0; j < l; ++j){
		if(line[j] == 'B' or line[j] == 'C' or 
		line[j] == 'D' or line[j] == 'F' or 
		line[j] == 'G' or line[j] == 'K' or 
		line[j] == 'N' or line[j] == 'P' or 
		line[j] == 'Q' or line[j] == 'R' or 
		line[j] == '4' or line[j] == '6' or 
		line[j] == '7' or line[j] == '9') {
		return false; break; }
		b += convert(line[j]);
	}
	reverse(b.begin(), b.end());
	return b == line;
}

bool palindrome(string& line) {
    string a = line;
	reverse(a.begin(), a.end());
	return a == line;
}


int main(){	
	string line;
	while(getline(cin, line)){
		bool mir = mirrored(line);
        bool pal = palindrome(line);
		
		if(!mir and !pal)
            cout << line <<" -- is not a palindrome." << endl;
        else if(!mir and pal)
            cout << line <<" -- is a regular palindrome." << endl;
        else if(mir and !pal)
			cout << line <<" -- is a mirrored string." << endl;
        else
            cout << line <<" -- is a mirrored palindrome." << endl;
        cout << endl;
	}
	
	return 0;
}
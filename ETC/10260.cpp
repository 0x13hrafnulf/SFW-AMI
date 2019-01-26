#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(){	
	string word;
	
	while(cin >> word){
		int a = 0, b;
		int l = word.size();
		for(int i = 0; i < l; ++i){
			if(word[i] == 'R'){
				b = 6;
			}
			else if(word[i] == 'L'){
				b = 4;
			}
			else if(word[i] == 'M' or word[i] == 'N'){
				b = 5;
			}
			else if(word[i] == 'D' or word[i] == 'T'){
				b = 3;
			}
			else if(word[i] == 'B' or word[i] == 'F' or word[i] == 'P' or word[i] == 'V'){
				b = 1;
			}
			else if(word[i] == 'C' or word[i] == 'G' or word[i] == 'J' or word[i] == 'K' or word[i] == 'Q' or word[i] == 'S' or word[i] == 'X' or word[i] == 'Z'){
				b = 2;
			}
			else b = 0;
			if(b != a and b != 0) cout << b;
			a = b;
		}
		cout << endl;
	}


	
	return 0;
}
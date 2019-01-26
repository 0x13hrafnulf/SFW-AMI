#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){	
	int test; cin >> test;
	string word;
	
	while(test--){
		cin >> word;
		if(word.size() == 5) cout << 3 << endl; 
		else{
			if((word[0]=='t' && word[1]=='w') || (word[0]=='t' && word[2]=='o') || (word[1]=='w' && word[2]=='o')) cout << 2 << endl; 
			else cout << 1 << endl; 
		}
	}
	
	return 0;
}
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;








int main(){	
	char qwerty[47] = {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
				   'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\',
				   'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
				   'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'} ;
	
	string msg;
	while(getline(cin, msg)){
		int l = msg.size();
		for (int i = 0; i < l; ++i){
			if(msg[i] == ' ') cout << msg[i];
			else{
				for (int j = 0; j < 47; ++j){
					if(tolower(msg[i]) == qwerty[j]){
						cout << qwerty[j - 2];
						break;
					}
				}
			} 
		}
		cout << endl;
	}
	return 0;
}
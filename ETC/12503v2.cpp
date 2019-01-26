#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(){	
	int test, n, p; cin >> test;
	while(test--){
		cin >> n;
		vector<int> com(n);
		string line;
		getline(cin, line);
		p = 0;
		for(int i = 0; i < n; ++i){
			string command;		
			cin >> command;
			if(command == "LEFT"){
				com[i] = -1;
				p+= com[i];
			}
			else if(command == "RIGHT"){
				com[i] = 1;
				p += com[i];
			}
			else{
				int index;
				cin >> command >> index;
				com[i] = com[index -1];
				p+= com[i];
			}
		}
		cout << p << endl;
	}
	return 0;
}
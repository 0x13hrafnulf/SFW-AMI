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
			getline(cin, line);
			istringstream sinp(line);
			if(sinp >> command and sinp.eof()){
				if(command == "LEFT"){
					com[i] = -1;
					p+= com[i];
				}
				else if(command == "RIGHT"){
					com[i] = 1;
					p += com[i];
				}
			}else{
				int index = int(line[line.size() - 1] - '0') - 1;
				com[i] = com[index];
				p+= com[i];
			}
		}
		cout << p << endl;
	}
	return 0;
}
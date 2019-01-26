#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(){		
	int test; cin >> test;
	string line;
	getline(cin, line);
	while(test--){
		getline(cin, line);// blank line
		
		
		
		getline(cin, line);
		istringstream sinp1(line);
		int x;
		vector<int> v;
		while(sinp1 >> x){
			v.push_back(x);
		}
			
		getline(cin, line);
		istringstream sinp2(line);
		int l = v.size();
		vector<string> v2(l);

		for(int i = 0; i < l; ++i){
			
			sinp2 >> v2[v[i]-1];				
		}
		for(int i = 0; i < l; ++i){
			cout << v2[i] << endl;		
		}
		if(test) cout << endl;
	}
	
	return 0;
}
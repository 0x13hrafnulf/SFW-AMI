#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(){		
	vector<string> v;
	vector<string> r;
	string w;
	while(cin >> w){
		v.push_back(w);
	}
	sort(v.begin(), v.end());
	int l = v.size();
	int p = 0;
	for(int i = 0; i < l; ++i, ++p){
		for(int j = 1; j < v[i].size(); ++j){
			string s1, s2;
			s1 = v[i].substr(0, j);
			s2 = v[i].substr(j, v[i].size()-1);
			if(binary_search(v.begin(), v.end(),s1) and binary_search(v.begin(), v.end(),s2)) {
				cout << v[i] << endl;
				break;
			}
		}

	}	
	return 0;
}
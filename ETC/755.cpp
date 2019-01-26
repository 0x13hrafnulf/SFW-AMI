#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(){	
	int test; cin >> test;
	
	while(test--){
		string x;
		int n; cin >> n;
		vector<string> v;
		while(n--){
			cin >> x;
			int l = x.size();
			string num;
			for(int k = 0; k < l; ++k){
				if(isdigit(x[k])){
					num += x[k];
				}	
				else if(isalpha(x[k])){
					if(x[k] == 'A' or x[k] == 'B' or x[k] == 'C') num += '2';
					else if(x[k] == 'D' or x[k] == 'E' or x[k] == 'F') num += '3';
					else if(x[k] == 'G' or x[k] == 'H' or x[k] == 'I') num += '4';
					else if(x[k] == 'J' or x[k] == 'K' or x[k] == 'L') num += '5';
					else if(x[k] == 'M' or x[k] == 'N' or x[k] == 'O') num += '6';
					else if(x[k] == 'P' or x[k] == 'R' or x[k] == 'S') num += '7';
					else if(x[k] == 'T' or x[k] == 'U' or x[k] == 'V') num += '8';
					else if(x[k] == 'W' or x[k] == 'X' or x[k] == 'Y') num += '9';
					else num += x[k];
				}
			}
			num.insert(3,"-");
			v.push_back(num);
		}
		int length = v.size();
		sort(v.begin(),v.end());
		
		for(int i = 0; i < length; ++i){
			int count = 0;			
			for(int k = i; k < length; ++k){
				if(v[i] == v[k]){
					++count;
				}
			}
			cout << v[i] << " " << count << endl;
			i += count;
		}
	}
		return 0;
}
	
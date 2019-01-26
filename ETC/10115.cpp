#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;




int main(){	
	int n;
	while(cin >> n){
		if(n == 0) break;
		vector<string> a(n);
		vector<string> b(n);
		string line; 
		getline(cin, line);
		for(int i = 0; i < n; ++i){
			getline(cin, a[i]);
			getline(cin, b[i]);
		}
		getline(cin, line);
		int j = 0;
		while(j != n){
			int index = line.find(a[j]);
			if(index != -1){
				line.replace(index, a[j].size(), b[j]);
			}else ++j;
			
		}
		cout << line <<endl;
	}
	return 0;
}
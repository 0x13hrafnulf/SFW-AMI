#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(){		
	int n;
	while(true){
		cin >> n;
		if(n == 0) break;
		string line, a ,b;
		getline(cin, line);

		vector<int> v;
		int max = 0, res = 0;
		while(n--){
			getline(cin, line);
			istringstream sinp(line);
			sinp >> a >> b;
			int l = a.size() + b.size();
			v.push_back(l);
			if(l > max) max = l;
		}
		int length = v.size();
		
		for(int i = 0; i < length; ++i){
			res += max - v[i];
		}
		cout << res << endl;
		
	}
	return 0;
}
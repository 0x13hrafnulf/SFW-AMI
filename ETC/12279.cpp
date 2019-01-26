#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){	
	int n, t, z, j; 
	while(cin >> n){
		++j;
		z = 0;
		t = 0;
		if (n == 0) break;
		vector<int> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
			if(v[i] == 0) ++z;
			else if(v[i] > 0) ++t;
		}
		cout << "Case " << j << ": " << t - z << endl;
	}
	
	return 0;
}
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int test, n, result; cin >> test;
	
	
	
	while(test--){
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		sort(v.begin(), v.end());	
		result = 2*(v[n/2 - 1] - v[0]) + 2*(v[n-1] - v[n/2 - 1]);
		cout << result << endl;
		
	}
	
	
	
	return 0;
}
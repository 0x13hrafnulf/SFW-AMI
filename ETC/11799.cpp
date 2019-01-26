#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main(){
	int test,j,n; cin >> test;
	
	while (test--){
		++j;
		cin >> n;
		vector<int> v(n);
		for(int i =0; i < n; ++i){
			cin >> v[i];
		}
		auto max = max_element(v.begin(), v.end());
		cout << "Case " << j << ": " << *max << endl;
	}
	return 0;
}
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main(){
	int test,j = 0,n, max, min; cin >> test;
	
	while (test--){
		++j;
		cin >> n;
		vector<int> v(n);
		max = 0;
		min = 0;
		for(int i =0; i < n; ++i){
			cin >> v[i];
		}
		for(int i = 1; i < n; ++i){
			if(v[i] > v[i-1]) ++max;
			else if(v[i] < v[i-1]) ++min;
		}
		cout << "Case " << j << ": " << max << " " << min << endl;
	}
	return 0;
}
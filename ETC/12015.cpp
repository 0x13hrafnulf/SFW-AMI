#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){	
	int test, max, j = 0; cin >> test;
	while(test--){
		++j;
		vector<string> site(10);
		vector<int> n(10);
		max = 0;
		for(int i = 0; i < 10; ++i){
			cin >> site[i];
			cin >> n[i];
			if(n[i] > max) {
				max = n[i];
			}
		}
		cout << "Case #" << j << ":" << endl;
		for(int i = 0; i < 10; ++i){
			if(max == n[i]) cout << site[i] << endl;
		}
	}
	return 0;
}
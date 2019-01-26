#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int test, j = 0; cin >> test;
	while(test--){
		++j;
		vector<int> v(3);
		for(int i = 0; i < 3; ++i){
			cin >> v[i];		
		}
		sort(v.begin(), v.end());
		cout << "Case " << j << ": " << v[1] << endl;
	}
	return 0;
}
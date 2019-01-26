#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int b, n, d,c,v;
	while(cin >> b >> n){
		if( b == 0 && n == 0) break;
		d = 0;
		c = 0;
		v = 0;
		bool check = true;
		vector<int> reserves(b);
		for(int i = 0; i < b; ++i){
			cin >> reserves[i];
		}
		for(int i = 0; i < n; ++i){
			cin >> d >> c >> v;
			reserves[d-1] -= v;
			reserves[c-1] += v;
		}
		for(int i = 0; i < b; ++i){
			if(reserves[i] < 0) check = false;
		}
		if (!check)cout << "N" << endl;
		else cout << "S" << endl;
	}
	return 0;
}
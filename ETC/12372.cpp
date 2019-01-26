#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){	
	int test, l, w, h, j = 0; cin >> test;
	while(test--){
		++j;
		cin >> l >> w >> h;
		if(l <= 20 and w <= 20 and h <= 20) cout << "Case " << j << ": " << "good" << endl;
		else cout << "Case " << j << ": " << "bad" << endl;
	}
	return 0;
}
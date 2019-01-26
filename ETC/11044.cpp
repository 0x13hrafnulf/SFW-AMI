#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int test, x, y; cin >> test;
	
	while(test--){
		cin >> x >> y;
		cout << (x/3) * (y/3) << endl;	
	}
	
	return 0;
}
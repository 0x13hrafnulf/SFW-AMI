#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int test; cin >> test;
	int w, n1,n2, dif;
	bool check = true;
	while(test--){
		bool check = true;
		cin >> w;
		cin >> n1 >> n2;
		dif = n1 - n2;
		
		for(int i = 1; i < w; ++i){
			cin >> n1 >> n2;
			if(dif != n1 - n2) check = false;
		}
		if(check) cout << "yes" << endl;
		else cout << "no" << endl;
		if(test) cout << endl;
	}
	return 0;
}

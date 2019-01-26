#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
	int n;
	int res;
	while (cin >> n){
		
		if (n == 0) break;
		
		while(1){
			while (n != 0){
			res += n%10;
			n /= 10;
			}
			n = res;
			res = 0;
			if(n/10 == 0) break;
		}
		
		cout << n << endl;
	}
	return 0;
}


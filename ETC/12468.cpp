#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){	
	int a, b, result;
	while(cin >> a >> b){
		if(a == -1 and b == -1) break;
		result = abs(b-a);
		if(result > 50) result = 100 - result;
		cout << result << endl;
	}
	return 0;
}
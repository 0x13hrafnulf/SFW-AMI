#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
	int init, a, b, c;
	int result;
	while(cin >> init >> a >> b >> c){
		if(init == 0 &&  a == 0 &&  b == 0 &&  c== 0) break;
		result = 1080;
		result += 9*((init - a + 40)%40);
		result += 9*((b - a + 40)%40);
		result += 9*((b - c + 40)%40);
		cout << result << endl;
	}

	return 0;
}
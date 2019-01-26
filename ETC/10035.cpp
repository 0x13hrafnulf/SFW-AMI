#include <iostream>
#include <cmath>
#include <string>
#include <cstdint>
using namespace std;

int main(){
	int64_t a, b;
	int64_t carry, result;
	while(cin >> a >> b){
		if(a == 0 && b == 0) 
			break;
		carry = 0;
		result = 0;
		while (a || b){
			carry = (a%10 + b%10 + carry)/10;
			a /= 10;
			b /= 10;
			result += carry;
		}
		if (result == 0) 
			cout << "No carry operation." << endl;
		else if(result == 1)
			cout << "1 carry operation." << endl;
		else
			cout << result << " carry operations." << endl;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

class BigInt
{
    friend std::ostream& operator<<(std::ostream& out, const BigInt& number);
    private:
    public:
	BigInt(const string& number = "0");
	deque<int> digits;
	
};
BigInt::BigInt(const string& number){
	int l = number.size();
	for(int i = 0; i < l; ++i){
		char ch = number[i];
		digits.push_back(ch - '0');
	}
	
}

BigInt operator+(const BigInt& a, const BigInt& b){
	BigInt result;
	result.digits.erase(result.digits.begin());
	
	int i = a.digits.size() - 1;
	int j = b.digits.size() - 1;
	int carry = 0;

	while (i > -1 or j > -1 or carry != 0) {
		int sum = carry;
		if (i > -1) {
			sum += a.digits[i];
			--i;
		}
		if (j > -1) {
			sum += b.digits[j];
			--j;
		}
		carry = sum / 10;
		int d = sum % 10;
		result.digits.push_front(d);
	}

	return result;
}

ostream& operator<<(ostream& out,const BigInt& number)
{
	int l = number.digits.size();
	for(int i = 0; i < l; ++i){
		out << number.digits[i];
	}
	return out;
}

int main(){	
	deque<BigInt> Fib(5001);
	Fib[0] = to_string(0);
	Fib[1] = to_string(1);
	for(int i = 2; i <= Fib.size(); ++i){
		Fib[i] = Fib[i-1] + Fib[i-2];
	}
	int a;
	while(cin >> a){
		cout << "The Fibonacci number for " << a << " is " << Fib[a] << endl;
	}
	return 0;
}
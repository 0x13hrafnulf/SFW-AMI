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
BigInt operator*(const BigInt& a, const BigInt& b){
	BigInt result;
	result.digits.erase(result.digits.begin());
	
	int i = a.digits.size() - 1;
	int j = b.digits.size() - 1;
	int k = j;
	while (j > -1) {
		BigInt smthg;
		smthg.digits.erase(smthg.digits.begin());
		int carry = 0;
		while (i > -1 || carry != 0) {
			int sum = carry;
			if (i > -1) {
				sum += a.digits[i] * b.digits[j];
				--i;
			}
			carry = sum / 10;
			int d = sum % 10;
			smthg.digits.push_front(d);
		}
		if (j < k) {
			for (int s = j; s < k; ++s) {
				smthg.digits.push_back(0);
			}
		}
		--j;
		result = result + smthg;
		i = a.digits.size() - 1;
	}
	return result;
}
BigInt pw(const BigInt& a, const int& t){
	BigInt result = a;
	for(int i = 0; i < t; ++i){
		result = result * a;
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

int main(){	//N <= 150 A <= 15
	deque<deque<BigInt>> a(15);
	deque<BigInt> b(150);
	for(int i = 0; i < 15; ++i){
		BigInt n = to_string(i+1);
		for(int j = 0; j < 150; ++j){
			b[j] = pw(n, j);
		}	
		a[i] = b;
	}
	int N, A;
	while(cin >> N >> A){
		BigInt res;
		if (A == 0) cout << 0 << endl;
		else {
			for(int i = 0; i < N; ++i){
			BigInt j = to_string(i+1);
			res = res + a[A-1][i] * j;
			}
			cout << res << endl;
		}
	}
	return 0;
}
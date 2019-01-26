#ifndef BIGINT_H
#define  BIGINT_H

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;
class BigInt
{
    friend std::ostream& operator<<(std::ostream& out, const BigInt& number);
	friend std::istream& operator>>(std::istream& inp, BigInt& number);
	friend BigInt operator+(const BigInt& a, const BigInt& b);
    friend BigInt operator-(const BigInt& a, const BigInt& b);
    friend BigInt operator*(const BigInt& a, const BigInt& b);
    friend BigInt operator/(const BigInt& a, const BigInt& b);
	friend BigInt operator%(const BigInt& a, const BigInt& b);
	friend int comparison(const BigInt& a, const BigInt& b);

	
    private:
    
    deque<int> digits;
    int sign = 1;
	
    public:
    
	BigInt(const string& number = "0");
	
	
};

#endif
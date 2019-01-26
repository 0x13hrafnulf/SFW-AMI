#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	
	int n;
	cout << "PERFECTION OUTPUT" << endl;
	while (cin >> n){
		if (n == 0) break;
		int sum = 0;
		for (int i = 1; i < n; ++i){
			if (n % i == 0) 
				sum += i;
		}
		
		cout << setfill(' ');
		cout << right << setw(5) << n << "  ";
		if (sum < n)
			cout << "DEFICIENT" << endl;
		else if (sum == n)
			cout << "PERFECT"<< endl;
		else if (sum > n)
			cout << "ABUNDANT" << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int duration, record,  result, month;
	double dpay, payment, loan, price;

	
	while(cin >> duration >> dpay >> loan >> record){
		result = 0;
		if(duration < 0) break;
		vector<double> rate(duration);
		fill(rate.begin(), rate.end(), -1);
		
		for (int i = 0; i < record; ++i){
			cin >> month;
			cin >> rate[month];
		}
		
		price = (dpay + loan);
		payment = loan/duration;
		
		for (int i = 0; i <= duration; ++i){
			if(rate[i] < 0) rate[i] = rate[i-1];
			price *= (1 - rate[i]);		
			if(price >= loan) {
				result = i; 
				break;
			}
			loan -= payment;
			
		}			
		
		if (result == 1) cout << result << " month" << endl;
		else cout << result << " months"<< endl;
	}
	return 0;
}
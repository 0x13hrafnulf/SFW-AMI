#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){	
	int test, sum, c; cin >> test;
	string command;
	while(test--){
		cin >> command;
		if(command == "report") cout << sum << endl;
		else{
			cin >> c;
			sum += c;
		}		
	}
	return 0;
}
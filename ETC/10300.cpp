#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
	int n; cin >> n;
	int f; 
	while (n--){
		cin >> f;
		int sum = 0;
		int a,b,c;
		while (f--){
			cin >> a >> b >> c;
			sum += a*c;
		}
		cout << sum << endl;
	}
	return 0;
}
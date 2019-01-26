#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
	int n; cin >> n;
	string s;
	
	while (n--){
		cin >> s;
		int l = s.size();
		
		if(s == "1" || s == "4" || s == "78")
			cout << '+' << endl;
		else if(s[l - 2] == '3' && s[l - 1] == '5')
			cout << '-' << endl;
		else if(s[0] == '9' && s[l-1] == '4')
			cout << '*' << endl;
		else
			cout << '?' << endl;
		
	}
	return 0;
}
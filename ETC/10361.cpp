#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(){	
	int n; cin >> n;
	string a, b, s1, s2, s3, s4;
	getline(cin, a);
	while(n--){
		getline(cin, a);
		getline(cin, b);
		
		size_t i1= a.find("<");
        size_t i2= a.find(">");
        size_t i3= a.find("<",i1+1);
        size_t i4= a.find(">",i2+1);
		size_t dots = b.find("...");
		
		s1=a.substr(i1+1, i2-i1-1);
        s2=a.substr(i2+1,i3-i2-1);
        s3=a.substr(i3+1,i4-i3-1);
        s4=a.substr(i4+1, a.size() - i4-1);
		
		a.erase(i1,1);
        a.erase(i2-1,1);
        a.erase(i3-2,1);
        a.erase(i4-3,1);
		b.erase(dots, 3);
		b.insert(dots, s3+s2+s1+s4); 
		
		
		cout << a << endl;
		cout << b << endl;
	}
	return 0;
}
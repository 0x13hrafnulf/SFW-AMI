#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){	
	int j = 0;
	string s, l;
	while(cin >> s){
		if(s == "#") break;

		++j;
		if(s == "HELLO")
            l = "ENGLISH";
        else if(s == "HOLA")
			l = "SPANISH";
        else if(s == "HALLO")
            l = "GERMAN";
        else if(s== "BONJOUR")
            l = "FRENCH";
        else if( s=="CIAO")
            l = "ITALIAN";
        else if( s=="ZDRAVSTVUJTE")
            l = "RUSSIAN";
        else
           l = "UNKNOWN";
	   
		cout << "Case " << j << ": " << l << endl;
	}
	return 0;
}
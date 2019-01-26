#include <iostream>

using namespace std;
int main(){
	char ch;
	bool inQuote = false;
	while(cin.get(ch)){
	if (ch == '\"' and not inQuote) {
		cout.put('`');
		cout.put('`');
		inQuote = true;
	}
	else if (ch == '\"' and inQuote) {
		cout.put('\'');
		cout.put('\'');	
		inQuote = false;
	}
	else {
		cout.put(ch);
	}
	}
	return 0;
}
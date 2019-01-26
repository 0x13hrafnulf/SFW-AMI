#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

string parse(const string& line){
	string s = "";
	int l = line.size();
	for(int i = 0; i < l; ++i){
		if(isalpha(line[i])) s+=line[i];
	}
	
	return s;
}
int check(string& line){
	int l = line.size();
	int bs = sqrt(l);
	string a = line;
	reverse(a.begin(), a.end());
	if(bs*bs != l) return 0;
	else if(a != line) return 0;
	return bs;
}

int main(){	
	int n; cin >> n;
	string line, pol;
	int i = 1;
	getline(cin, line);
	while(n--){
		getline(cin, line);
		pol = parse(line);
		int size = check(pol);
		cout << "Case #:" << i << endl;
		if(size > 0) cout << size << endl;
		else cout << "No magic :(" << endl;
		++i;
	}
	
	



	return 0;
}
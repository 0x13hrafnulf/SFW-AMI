#include <string>
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <set>
using namespace std;

int main()
{
	int n; cin >> n;
	string s, l;
	unordered_map<string, string> m;
	getline(cin, s);
	while(n--)
	{
		getline(cin, s);
		getline(cin, l);
		m[s] = l;
	}
	
	cin >> n; 
	getline(cin, s);
	while(n--)
	{
		getline(cin, s);
		
		cout << m[s] << endl;
	}
	
	
	return 0;
}
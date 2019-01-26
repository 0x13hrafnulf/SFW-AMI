#include <string>
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

bool ballot(const string& line, unordered_map<string, int>& m)
{
	istringstream sinp(line);
	
	string s;
	double d = 0;
	int a;
	bool c = false;
	
	while(sinp >> s)
	{
		if(m.find(s) != m.end()) d += m[s];
		
		else if(s == "<")
		{
			sinp >> a;
			c = d < a*10;
		}
		else if(s == ">")
		{
			sinp >> a;
			c = d > a*10;
		}
		else if(s == "<=")
		{
			sinp >> a;
			c = d <= a*10;
		}
		else if(s == ">=")
		{
			sinp >> a;
			c = d >= a*10;
		}
		else if(s == "=")
		{
			sinp >> a;
			c = d == a*10;
		}
	}
	
	return c;
}
int main()
{
	
	int p, g; cin >> p >> g;
	unordered_map<string, int> m;
	string s;
	double d;
	int f;
	while(p--)
	{
		cin >> s >> d;
		f = d*10;
		m[s] = f;
	}
	getline(cin, s);
	for(int i = 1; i <= g; ++i)
	{
		getline(cin, s);
		
		bool check = ballot(s, m);
		if(check)
		{
			cout << "Guess #" << i << " was correct." << endl;
		}
		else
		{
			cout << "Guess #" << i << " was incorrect." << endl;
		}
	}
	
	
	return 0;
}
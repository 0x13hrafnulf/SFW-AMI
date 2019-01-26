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
	int t;
	cin >> t;
	int i = 1;
	while(t--)
	{
		int n; cin >> n;
		unordered_map<string, int> m;
		string s;
		int h, d;
		while(n--)
		{
			cin >> s >> h;
			m[s] = h;
		}
		cin >> d >> s;
		
		if(m.find(s) == m.end() or d + 5 < m[s])
		{
			cout << "Case " << i <<": Do your own homework!" << endl;
		}
		else if(d >= m[s] and m.find(s) != m.end())
		{
			cout << "Case " << i <<": Yesss" << endl;
		}
		else if(d + 5 >= m[s] and m.find(s) != m.end())
		{
			cout << "Case " << i <<": Late" << endl;
		}
		
		++i;
	}
	
	
	
	
	
	
	
	return 0;
}
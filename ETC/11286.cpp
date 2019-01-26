#include <string>
#include <iostream>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <set>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		if(n == 0) break;
		
		map<set<int>, int > m;
		int a;
		string line;
		getline(cin, line);
		while(n--)
		{
			set<int> s;
			cin >> a; 
			s.insert(a);
			cin >> a; 
			s.insert(a);
			cin >> a; 
			s.insert(a);
			cin >> a; 
			s.insert(a);
			cin >> a; 
			s.insert(a);
			
			++m[s];
		}
		int max = 0;
		int res = 0;
		for(auto it = m.begin(); it != m.end(); ++it)
		{
			if(it->second == max) res += it->second;
			else if(it->second > max) 
			{
				max = it->second;
				res = it->second;
			}
		}
		cout << res << endl;
		
	}

	
	return 0;
}
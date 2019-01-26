#include <string>
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <set>
#include <vector>

using namespace std;
int main()
{
	int t; cin >> t;
	int n;
	while(t--)
	{
		cin >> n;

		int a;
		vector<int> v;
		while(n--)
		{
			cin >> a;
			v.push_back(a);

		}
		int l = 0;
		unordered_map<int, int> m;
		for(int i = 0; i < v.size(); ++i)
		{
			if(m.find(v[i]) == m.end())
			{
				m[v[i]] = i;
			}
			else
			{
				if(l < m.size()) l = m.size();	
				i = m[v[i]];
				m.clear();
			}
			
		}
		if(l < m.size()) l = m.size();
		cout << l << endl;
		
	}
	
	return 0;
}
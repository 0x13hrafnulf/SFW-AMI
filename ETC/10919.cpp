#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	string line;
	
	while(getline(cin, line))
	{
		if(line == "0") break;
		
		istringstream sinp(line);
		
		int k, m; sinp >> k >> m;
		
		vector<string> v;
		string id;
		while(k--) 
		{
			cin >> id;
			v.push_back(id);
		}
		sort(v.begin(), v.end());
		
		int c, r;
		vector<int> check(m);
		for(int i = 0; i < m; ++i)
		{
			cin >> r >> c;
			check[i] = c;
			while(r--)
			{
				cin >> id;
				if(binary_search(v.begin(), v.end(), id)) --check[i];
			}
		}
		int sum = 0;
		bool pass = true;
		for(int i = 0; i < m; ++i)
		{
			if(check[i] > 0) pass = false;
		}
		
		if(pass) cout << "yes" << endl;
		else cout << "no" << endl;
		getline(cin, line);
	}
}
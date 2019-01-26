#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	int n; cin >> n;
	
	int a,b;
	
	while(n--)
	{
		int count = 0;
		cin >> a >> b;
		int t;
		unordered_map<int, int> m;
		while(a--)
		{
			cin >> t;
			++m[t];
		}
		while(b--)
		{
			cin >> t;
			--m[t];
		}
		

		for (auto i = m.begin(), e = m.end(); i != e; ++i)
		{
				count += abs(i->second);
		}
		
		cout << count << endl;
	}

	return 0;
}
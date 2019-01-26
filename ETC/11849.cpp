#include <iostream>
#include <unordered_set>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	
	int n, m, count, d;
	
	while(cin >> n >> m)
	{
		if(n== m and n == 0) break;
		
		unordered_set<int> a;
		while(n--)
		{
			cin >> d;
			a.insert(d);
		}
		
		while(m--)
		{
			cin >> d;
			if(a.find(d) != a.end()) ++count;
		}
		
		cout << count << endl;
		count = 0;
	};
	
	
	return 0;
}
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
	int n; 
	while(cin >> n)
	{
		if(n == 0) break;
		
		multiset<int> s;
		int k, a; 
		long sum = 0;
		
		while(n--)
		{
			cin >> k;
			while(k--)
			{
				cin >> a;
				s.insert(a);
			} 
			sum = sum + *(--s.end()) - *(s.begin());
			s.erase(--s.end());
			s.erase(s.begin());
		}
		cout << sum << endl;
	}
	
	
	
	return 0;
}
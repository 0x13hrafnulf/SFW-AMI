#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	
	int n;
	unordered_map<int, int> m;
	vector<int> v;
	while(cin >> n)
	{
		if(m.find(n) != m.end())
		{
			++m[n];
		}
		else
		{
			++m[n];
			v.push_back(n);
		}
	}
	
	
	for (auto i = v.begin(), e = v.end(); i != e; ++i)
	{	
		cout << *i << " " << m[*i] <<  endl;
	}
	
	return 0;
}
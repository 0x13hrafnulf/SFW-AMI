#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct DNA
{
	string seq;
	int inv = 0;
	
	
	DNA(const string& s)
	: seq(s)
	{
		for(int i = 0; i < s.size(); ++i)
		{
			for(int j = i + 1; j < s.size(); ++j)
			{
				if(s[i] > s[j]) ++inv;
			}
		}
		
	}
	
};
bool cmp(const DNA& first, const DNA& second)
{
	if(first.inv == second.inv) return false;
	return first.inv < second.inv;
}

int main()
{
	int t; cin >> t;
	
	while(t--)
	{
		int n, m; cin >> n >> m;
		vector<DNA> v;
		string w;
		for(int i = 0; i < m; ++i)
		{
			cin >> w;
			DNA d{w};
			v.push_back(d);
		}
		
		stable_sort(v.begin(), v.end(), cmp);
		
		for(int i = 0; i < m; ++i)
		{
			cout << v[i].seq << endl;
		}

		if(t > 0) cout << endl;
	}
}
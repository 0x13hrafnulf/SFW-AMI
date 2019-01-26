#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
struct dict
{
	string job;
	int salary;
	
	dict(string s, int m)
	: job(s), salary(m)
	{
	}
	
};

bool cmp(dict& a, dict& b)
{	
	return a.job < b.job;
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	string job;
	int sal;
	vector<dict> v;
	
	while(n--)
	{
		cin >> job >> sal;
		v.push_back(dict{job,sal});
	}
	sort(v.begin(), v.end(), cmp);
	
	while(m--)
	{
		string line;
		vector<string> s;
		long long sum = 0;
		while(cin >> line)
		{
			if(line == ".") break;
			s.push_back(line);
		}
		for(int i = 0; i < s.size(); ++i)
		{
			for(int j = 0; j < v.size(); ++j)
			{
				if(s[i] == v[j].job) sum += v[j].salary;
			}
		}
		cout << sum << endl;
	}
}
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>

using namespace std;

void dist(set<string>& s, string w, int i, int h, int times)
{
	w[i] = '1';
	++times;
	if(times == h)
	{
		s.insert(w);
	}
	else if(times > h) return;
	
	for(int j = i + 1; j < w.size(); ++j)
	{
		dist(s, w, j, h, times);
	}
}

int main()
{
	int t;
	cin >> t;
	string line;
	getline(cin, line);
	
	while(t--)
	{
		getline(cin, line);
		getline(cin, line);
		istringstream sinp(line);
		
		int n, h;
		sinp >> n >> h;
		string w = "";
		
		for(int i = 0; i < n; ++i)
		{
			w += '0';
		}
		set<string> s;
		for(int i = 0; i < w.size(); ++i)
		{
			dist(s, w, i, h, 0);
		}
		for(auto e : s)
		{
			cout << e << endl;
		}
		if(t > 0) cout << endl;
	}
}
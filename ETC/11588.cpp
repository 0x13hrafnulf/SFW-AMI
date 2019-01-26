#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

struct Freq
{
	int Ch;
	int n;
	
	Freq(char c, int t)
	: Ch(c), n(t)
	{
	}
};
bool cmp(const Freq& one, const Freq& other)
{
	if(one.n < other.n) return true;
	if(one.n == other.n and one.Ch > other.Ch) return true;
	return false;
}

using namespace std;
int main()
{
	
	int x; cin >> x;
	for(int i = 1; i <= x; ++i)
	{	
		map<char, int> mp;
		vector<Freq> fr;
		int r, c, m, n;
		cin >> r >> c >> m >> n;
		char ch;
		for(int j = 0; j < r*c; ++j)
		{
			cin >> ch;
			++mp[ch];
		}
		
		for(auto it = mp.begin(); it != mp.end(); ++it)
		{
			Freq alph{(*it).first, (*it).second};
			fr.push_back(alph);
		}

		sort(fr.begin(), fr.end(), cmp);

		int byte = 0;
		byte += (fr[fr.size() - 1].n)*m;
		for(int j = fr.size() - 2; j > -1; --j)
		{
			if(fr[j].n == fr[fr.size() - 1].n) byte += (fr[j].n)*m;
			else byte += (fr[j].n)*n;
		}
		cout << "Case " << i << ": " << byte << endl;
	}
}
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
	
	
	string line;
	int i = 0;
	while(getline(cin, line))
	{
		if(i > 0) cout << endl;
		i = 1;
		map<char, int> m;
		vector<Freq> fr;
		
		for(int i = 0; i < line.size(); ++i)
		{
			++m[line[i]];
		}
		
		for(auto it = m.begin(); it != m.end(); ++it)
		{
			Freq alph{(*it).first, (*it).second};
			fr.push_back(alph);
		}

		sort(fr.begin(), fr.end(), cmp);
		
		for(int i = 0; i < fr.size(); ++i)
		{
			cout << fr[i].Ch << " " << fr[i].n << endl;
		}
	}
}
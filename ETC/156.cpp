#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
struct word
{
	string s;
	string an;
	
	word(string line)
	: s(line)
	{
		for(int i = 0; i < line.size(); ++i)
		{
			an += tolower(line[i]);
		}
		sort(an.begin(), an.end());
	}
};
bool cmp(const word& a, const word& b)
{
	return a.an < b.an;
}
int main()
{
	string line;
	vector<word> dict;
	while(cin >> line)
	{
		if(line == "#") break;
		
		dict.push_back(word{line});
	}

	sort(dict.begin(), dict.end(), cmp);
	vector<string> v;
	for(int i = 0; i < dict.size(); ++i)
	{
		auto border = equal_range(dict.begin(), dict.end(), dict[i], cmp);
		int up = border.first - dict.begin();
		int down = border.second - dict.begin();
		if(down - up == 1) v.push_back(dict[i].s);
	}
	sort(v.begin(), v.end());
	for(auto e : v)
	{
		cout << e << endl;
	}
}
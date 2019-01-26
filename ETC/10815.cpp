#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	set<string> dict;
	string s;
	while(cin >> s)
	{
		auto beg = s.begin();
		auto end = s.end();
		transform(beg, end, beg, ::tolower);
		string res = "";
		for(int i = 0; i < s.size(); ++i)
		{
			if(isalpha(s[i])) res += s[i];
			else if(res != "") 
			{
				dict.insert(res);
				res = "";
			}
		}
		if(res != "") dict.insert(res);
	}
	

	for(auto it = dict.begin(); it != dict.end(); ++it)
	{
		cout << *it << endl;
	}
	
	return 0;
}
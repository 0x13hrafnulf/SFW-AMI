#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	string s;
	set<string> dict;
	while(cin >> s)
	{
		dict.insert(s);
	}
	
	for(auto it = dict.begin(); it != dict.end(); ++it)
	{
		string word = *it;
		for(int i = 1; i < word.size(); ++i)
		{
			string s1 = word.substr(0, i);
			string s2 = word.substr(i, word.size() - 1);
			if(dict.find(s1) != dict.end() and dict.find(s2) != dict.end()) 
			{
				cout << word << endl;
				break;
			}
		}
		
		
	}
	
	return 0;
}
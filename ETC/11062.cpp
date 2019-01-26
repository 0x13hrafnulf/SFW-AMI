#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	set<string> dict;
	string line;
	string text;
	bool carry;
	while(getline(cin, line))
	{
		auto beg = line.begin();
		auto end = line.end();
		transform(beg, end, beg, ::tolower);
		
		carry = line[line.size() - 1] == '-';
		if(carry)
		{
			for(int i = 0, l = line.size() - 1; i < l; ++i)
			{
				if(isalpha(line[i]) or line[i] == '-' ) text += line[i];
				else  text += ' ';
			}
		}
		else
		{
			for(int i = 0, l = line.size(); i < l; ++i)
			{
				if(isalpha(line[i]) or line[i] == '-' ) text += line[i];
				else  text += ' ';
			}
		}
		
		if(!carry) text += " ";
	}
	
	istringstream sinp(text);
	
	
	while(sinp >> line)
	{
		dict.insert(line);
	}
	
	for(auto it = dict.begin(); it != dict.end(); ++it)
	{
		cout << *it << endl;
	}
	
	return 0;
}
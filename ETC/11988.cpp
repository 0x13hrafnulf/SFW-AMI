#include <iostream>
#include <list>
#include <sstream>
using namespace std;
int main()
{
	for(string s; cin >> s;)
	{
		list<char> l;
		int length = line.size();
		
		auto it = l.begin();
		
		for(int i = 0; i < length; ++i)
		{
			if(line[i] == '[') it = l.begin();
			else if(line[i] == ']') it = l.end();
			else l.insert(it, line[i]);
		}
		
		for(auto i = l.begin(); i != l.end(); ++i)
		{
			cout << *i;
		}
		cout << endl;
	}
	
	return 0;
}
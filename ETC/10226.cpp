#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;


int main()
{
	int n; cin >> n;
	string line;
	getline(cin, line);
	getline(cin, line);
	while(n--)
	{
		map<string, int> m;
		double count = 0.0;
		while(getline(cin, line))
		{
			if(line == "") break;
			++m[line];
			++count;			
		}
		
		for(auto i = m.begin(); i != m.end(); ++i)
		{
			cout << i->first << " " << setprecision(4) <<fixed << 100.00*(i->second)/count << endl;
		}
		if(n > 0) cout << endl;
	}
	
	return 0;
}
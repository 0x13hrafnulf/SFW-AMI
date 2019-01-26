#include <string>
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <sstream>




using namespace std;



int main()
{
	string line, a, b;
	unordered_map<string, string> m;
	while (getline(cin, line))
	{
		if(line == "") break;
		
		istringstream sinp(line);
		
		sinp >> a >> b;
		
		m.insert({b, a});
		
	}
	

	while(getline(cin, line))
	{
		if(m.find(line) != m.end()) cout << m[line] << endl;
		else cout << "eh" << endl;
	}

	return 0;
}
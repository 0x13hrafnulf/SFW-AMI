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
	
	vector<string> names;
	vector<string> db;
	while(n--)
	{
		getline(cin, line);
		istringstream sinp(line);
		string name;
		string day, month, year; 
		
		sinp >> name >> day >> month >> year;
		day = day.size() == 2 ? day : day = "0" + day;
		month = month.size() == 2 ? month : month = "0" + month;
		db.push_back(year + month + day);
		names.push_back(name);
	}
	auto max = min_element(db.begin(), db.end()) ;
	auto min = max_element(db.begin(), db.end());
	
	cout << names[min - db.begin()] << endl;
	cout <<  names[max - db.begin()]<< endl;
}
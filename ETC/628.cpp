#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
vector<int> numbers{0,1,2,3,4,5,6,7,8,9};

void backtrack(string w, int i, string r, const string& d)
{
	if(i == r.size()) 
	{
		cout << w << endl;
		return;
	}
	else if( i < r.size())
	{
		if(r[i] == '#')
		{
			w += d;
			backtrack(w, i + 1, r, d);

		}
		else if(r[i] == '0')
		{
			for(int k = 0; k < numbers.size(); ++k)
			{
				backtrack(w + to_string(numbers[k]), i + 1, r, d);
			}
		}
	}
}

int main()
{
	int n; 
	while(cin >> n)
	{
		cout << "--" << endl;
		vector<string> d(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> d[i];
			
		}
		
		cin >> n;
		vector<string> r(n);
		string w = "";
		for(int i = 0; i < n; ++i)
		{
			cin >> r[i];			
			for(int j = 0; j < d.size(); ++j)
			{
				backtrack(w, 0, r[i],  d[j]);
			}
		}
	
	}
}
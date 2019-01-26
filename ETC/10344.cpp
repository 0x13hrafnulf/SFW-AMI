#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

bool backtrack(const vector<int>& v, int i, int sum)
{
	if(i == 5)
	{
		if(sum == 23) return true;
		else return false;
	}
	else if(i < 5)
	{
		return backtrack(v, i + 1, sum + v[i]) or
				backtrack(v,  i + 1, sum - v[i]) or
				backtrack(v,  i + 1, sum * v[i]);
	}
}



int main()
{
	string line;
	while(getline(cin, line))
	{
		if(line == "0 0 0 0 0") break;
		
		istringstream sinp(line);
		
		vector<int> v(5);
		vector<bool> visited(5);
		for(int i = 0; i < 5; ++i)
		{
			sinp >> v[i];
		}
		bool check = false;
		sort(v.begin(), v.end());
		do
		{
			if(backtrack(v, 1, v[0]))
			{
				check = true;
				break;
			}
		} while(next_permutation(v.begin(), v.end()));
		
		
		if(check) cout << "Possible" << endl;
		else cout << "Impossible" << endl;
	}
	
}
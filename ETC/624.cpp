#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <unordered_set>
#include <vector>
using namespace std;
int best;
vector<int> bpath;
void backtrack(int sum, int i, vector<int> path, const vector<int>& v, const int& N)
{
	sum += v[i];
	path.push_back(v[i]);
	for(int j = i + 1; j < v.size(); ++j)
	{
		if(sum + v[j] <= N)
		{
			backtrack(sum, j, path, v, N);
		}
	}
	if(sum > best )
	{
		best = sum;
		bpath = path;
	}
}


int main()
{
	string line;
	
	while(getline(cin, line))
	{
		istringstream sinp(line);
		int N, T;
		sinp >> N >> T;
		vector<int> v(T);
		
		for(int i = 0; i < T; ++i)
		{
			sinp >> v[i]; 
		}
		
		int sum = 0;
		best = 0;
		vector<int> path;
		for(int i = 0; i < v.size(); ++i)
		{
			backtrack(sum, i, path, v, N);
		}
		for(auto e : bpath)
		{
			cout << e << " ";
		}
			cout << "sum:" << best << endl;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int nil = -1;
const int inf = -2;

using Graph = vector<vector<int>>;

int main()
{
	int n; cin >> n;
	
	Graph graph(n);
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			char c; cin >> c;
			if(c == '1') graph[i].push_back(j);
		}
	}
	
	vector<char> states(n, 'W');
	vector<int> distances(n, inf);
	vector<int> pred(n, nil);
	
	int start; cin >> start;
	
	queue<int> q;
	q.push(start);
	states[start] = 'R';
	distances[start] = 0;
	
	while(not q.empty())
	{
		int u = q.front(); q.pop();
		states[u] = 'G';
		
		for(auto v : graph[u])
		{
			if(states[v] == 'W')
			{
				states[v] = 'R';
				distances[v] = distances[u] + 1;
				pred[v] = u;
				q.push(v);
			}
		}	
	}
	
	cout << "distances:"
	for(auto d : distances)
	{
		cout << " " << d;
	}
	cout << endl;
	for(auto p : pred)
	{
		cout << " " << p;
	}
	cout << endl;
	
	int dest; cin >> dest;
	
	vector<int> path;
	if(pred[dest] == nil)
	{
		cout << "no path." << endl;
	}
	else
	{
		cout << "path to " << dest << ": ";
		path.push_back(dest);
		while(dest != start)
		{
			dest = pred[dest];
			path.push_back(dest);
		}
		reverse(path.begin(), path.end());
		
		for(auto v: path)
		{
			cout << " " << v;
		}
		cout << endl;
	}
	
	
	
	
	return 0;
}
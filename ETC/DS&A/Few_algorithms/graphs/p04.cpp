#include<iostream>
#include<vector>
using namespace std;
struct Edge
{
	int u, v, w;
};

const int DEFINED = 1;
const int UNDEFINED = 0;


int main()
{
	int n; cin >> n;
	int m; cin >> m;
	
	vector<Edge> edges;
	for(int i = 0; i < m; ++i)
	{
		Edge e; cin >> e.u >> e.v >> e.w;
		edges.push_back(e);
	}
	
	vector<int> d(n, -1);
	vector<int> r(n, UNDEFINED);
	
	d[0] = 0;
	r[0] = DEFINED;
	
	for(int i = 0; i < n -1; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			Edge e = edges[j];
			if(r[e.u] == DEFINED and r[e.v] == DEFINED)
			{
				if(d[e.v] > d[e.u] + e.w)
				{
					d[e.v] = d[e.u] + e.w;
					r[e.v] = DEFINED;
				}
			}
			else if(r[e.u] == DEFINED and r[e.v] == UNDEFINED)
			{
				d[e.v] = d[e.u] + e.w;
				r[e.v] = DEFINED;
			}
		}
	}
	
	bool isNegative = false;
	
	for(int i = 0; i < m and not isNegative; ++i)
	{
		Edge e = edges[i];
		
		if(r[e.u] == DEFINED and r[e.v] == DEFINED)
		{
			if(d[e.v] > d[e.u] + e.w)
			{
				isNegative = true;
			}
		}
		else if(r[e.u] == DEFINED and r[e.v] == UNDEFINED)
		{
			isNegative = true;
		}			
	}
	
	if(not isNegative)
	{
		for(int i = 0; i < n; ++i)
		{
			if(r[i] == DEFINED) cout << d[i];
			else cout << "inf";
			cout << " ";
		}
		cout << endl;
	}
	else 
	{
		cout << "negative cycle" << endl;
	}
	return 0;
}


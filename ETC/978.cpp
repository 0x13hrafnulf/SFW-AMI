#include <string>
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <set>
#include <vector>
using namespace std;


int main()
{
	int n; cin >> n;
	while(n--)
	{
		multiset<int> g;
		multiset<int> b;
		int bg, sg, sb, w;
		cin >> bg >> sg >> sb;
		
		
		while(sg--)
		{
			cin >> w;
			g.insert(w);
		}
		
		while(sb--)
		{
			cin >> w;
			b.insert(w);
		}
		
	
		while(true)
		{
			vector<int> v(bg);
			
			
			for(int i = 0; i < bg; ++i)
			{
				auto ig = g.end(); --ig;
				auto ib = b.end(); --ib;
				v[i] = *ig - *ib;
				g.erase(ig);
				b.erase(ib);
				if(g.empty() or b.empty()) break;
			}
			
			for(int i = 0; i < bg; ++i)
			{
				if(v[i] < 0)
				{
					b.insert(-1*v[i]);
				}
				else if(v[i] > 0)
				{
					g.insert(v[i]);
				}
				else 
				{
					continue;
				}
			}
		
			if(g.empty() or b.empty()) break;
		}
		
		
		if(g.empty() and b.empty())
		{
			cout << "green and blue died" << endl;
		}
		else if(g.empty() and !b.empty())
		{
			cout << "blue wins" << endl;
			for(auto it = b.rbegin(); it != b.rend(); ++it)
			{
				cout << *it << endl;
			}
		}
		
		else if(!g.empty() and b.empty())
		{
			cout << "green wins" << endl;
			for(auto it = g.rbegin(); it != g.rend(); ++it)
			{
				cout << *it << endl;
			}
		}
		
		if(n >= 1) cout << endl;
	}

	return 0;
}
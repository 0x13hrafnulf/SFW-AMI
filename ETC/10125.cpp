#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
using namespace std;

struct Tuple
{
	int a;
	int b;
	int s;
	
	Tuple(int a1, int b1, int sum)
	: a(a1), b(b1), s(sum)
	{
		
	}
};

int main()
{
	int n;
	while(cin >> n)
	{
		if(n == 0) break;
		vector<int> v;
		int x;
		while(n--)
		{
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		
		vector<Tuple> p;
		vector<Tuple> d;
		for(int i = 0; i < v.size(); ++i)
		{
			for(int j = i + 1; j < v.size(); ++j)
			{
				p.push_back({v[i], v[j], v[i] + v[j]});
				d.push_back({v[j], v[i], v[j] - v[i]});
			}
		}
		
		sort(p.begin(), p.end(), [] (Tuple one, Tuple other) {return one.s < other.s;});
		sort(d.begin(), d.end(), [] (Tuple one, Tuple other) {return one.s < other.s;});
		
		int max = v[0];
		bool f = false;
		for(int i = 0; i < d.size(); ++i)
		{
			auto it = lower_bound(p.begin(), p.end(), d[i], 
															 [] (Tuple one, Tuple other) {return one.s < other.s;});
			for(auto j = it;; ++j)
			{
				if(j->s != d[i].s) break;
				
				if(d[i].a != j->a and d[i].a != j->b and d[i].b != j->a and d[i].b != j->b)
				{
					if(d[i].a > max) 
					{
						max = d[i].a;
						f = true;
					}
				}
			}				
		}
		
		if(f) cout << max << endl;
		else cout << "no solution" << endl;
		
	}
}

// bool F = true;
		// 
		// for(int i = v.size() - 1; i >= 0; --i)
		// {
			// for(int j = i - 1; j >= 0; --j)
			// {
				// int d = v[i] - v[j];
				// auto it = lower_bound(p.begin(), p.end(), d, 
															 // [] (Tuple one, int other) {return one.s < other;});
				// while(it->s == d)
				// {
					// if(v[i] != it->a and v[i] != it->b and v[j] != it->a and v[j] != it->b)
					// {
						// max = v[i];
						// F = false;
					// }
					// else ++it;
				// }
			// }
		// }
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct forwardcell
{
	
	int t;
	int d;
	int tg;
	
	forwardcell()
	{
		t = d = tg = 0;
	}
	forwardcell(const int& time, const int& dur, const int& target )
	: t(time), d(dur), tg(target)
	{
		
	}
};
int targetF(int i, const int& time, const vector<forwardcell>& v)
{
	if(i >= v.size()) return 0;
	else if(v[i].t <= time and time <= v[i].t + v[i].d) return v[i].tg;
	
	return targetF(i + 1, time, v);
}

void forward(const int& source, const int& time, map<int, vector<forwardcell>>& m)
{
	cout << "AT " << setfill('0') << setw(4) << time << " CALL TO " << setfill('0') << setw(4) << source << " RINGS ";
	int tg = source;
	int target = targetF(0, time, m[tg]);
	while(target != 0)
	{
		if(target == source) 
		{
			tg = 9999;
			break;
		}
		tg = target;
		target = targetF(0, time, m[tg]);
			
	}
	cout << setfill('0') << setw(4) << tg << endl;
}

int main()
{
	int n; cin >> n;
	string st;
	
	getline(cin, st);
	
	cout << "CALL FORWARDING OUTPUT" << endl;
	
	for(int i = 0; i < n; ++i)
	{
		map<int, vector<forwardcell>> m;
		
		int s, t, d, tg;
		while(getline(cin, st))
		{
			if(st == "0000") break;
			
			istringstream sinp(st);
			
			sinp >> s >> t >> d >> tg;
			
			m[s].push_back({t,d,tg});
			
		}	
		cout << "SYSTEM " << i+1 << endl;
		while(getline(cin, st))
		{
			if(st == "9000") break;
			
			istringstream sinp(st);
			
			sinp >> t >> s;
			
			forward(s, t, m);
		}
		
		
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
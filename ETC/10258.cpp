#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set> 

using namespace std;

struct sub
{
	int id;
	int problem;
	int time;
	char state;
	
	sub(int who, int i, int t, char c)
	: id(who), problem(i), time(t), state(c)
	{
		
	}
};
struct Rank
{
	int id;
	int problems;
	int penalty;
	vector<bool> solved;
	//vector<int> time;
	Rank(int who, int n, int p)
	: id(who), problems(n), penalty(p)
	{
		solved = vector<bool>(10, false);
		//time = vector<int> (10, 0);
	}
};
bool cmp1(const Rank& a, const Rank& b)
{
	if(a.problems == b.problems) return a.penalty < b.penalty;
	return a.problems > b.problems;
}
bool cmp(const sub& a, const sub& b)
{
	return a.id < b.id;
}
bool cmp2(const sub& a, const Rank& b)
{
	return a.id < b.id;
}

int main()
{
	int t; cin >> t;
	string line;
	getline(cin, line);
	getline(cin, line);
	while(t--)
	{
		vector<sub> v;
		vector<Rank> ranks;
		set<int> ids;
		int id, problem, time;
		char state;
		while(getline(cin, line))
		{
			if(line == "") break;
			istringstream sinp(line);
			sinp >> id >> problem >> time >> state;
			ids.insert(id);
			if(state == 'I' or state == 'C') v.push_back({id, problem, time, state});
		}
		sort(v.begin(), v.end(), cmp);
		
		for(auto e : ids)
		{
			ranks.push_back({e, 0, 0});
		}
		
		for(auto it = v.begin(); it != v.end(); ++it)
		{
			auto i = find_if(ranks.begin(), ranks.end(), [&it](Rank one)
																			{
																				return it->id == one.id;
																			});
			if(it->state == 'C' and i->solved[it->problem] == false)
			{
				i->penalty = i->penalty + it->time;
				i->problems = i->problems + 1;
				i->solved[it->problem] = true;
			}
			else if(it->state == 'I' and i->solved[it->problem] == false)
			{
				auto f = find_if(v.begin(), v.end(), [&it] (sub other) {
																		if(it->id == other.id)
																			if(it->problem == other.problem)
																				if(other.state == 'C') return true; return false;});
				if(f != v.end()) {
					i->penalty = i->penalty + 20;													
				}
			}
		}
		
		sort(ranks.begin(), ranks.end(), cmp1);
		
		for(int i = 0; i < ranks.size(); ++i)
		{
			cout << ranks[i].id << " " << ranks[i].problems << " " << ranks[i].penalty << endl;
		}
		
		if(t > 0) cout << endl;
	}
}
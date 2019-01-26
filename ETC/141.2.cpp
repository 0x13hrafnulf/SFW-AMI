#include <iostream>
#include <unordered_set>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class board
{
	public:
	int size;
	int elements;
	vector<vector<int>> v;
	
	board()
	: size(0), v(0, vector<int>(0)), elements(0)
	{
		
	}
	board(const int& n)
	: size(n), v(n, vector<int>(n)), elements(0)
	{
	}
	
	int getsize() const
	{
		return size;
	}
	
	void print()
	{
		for(int i = 0; i < size; ++i)
		{
			for(int j = 0; j < size; ++j)
			{
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	void push(const int& x, const int& y)
	{
		v[x-1][y-1] = 1;
		++elements;
	}
	void pop(const int& x, const int& y)
	{
		v[x-1][y-1] = 0;
		--elements;
	}
	
	void rotation()
	{
		for (int i = 0; i < size/2; ++i)
		{
			for (int j = i; j < size - i - 1; ++j)
			{
				int temp = v[i][j];
				v[i][j] = v[j][size-1-i];
				v[j][size-1-i] = v[size-1-i][size-1-j];
				v[size-1-i][size-1-j] = v[size-1-j][i];
				v[size-1-j][i] = temp;
			}
		}
		
	}
};

struct comparator
{
	bool operator()(const board& a, const board& b) const
	{
		if(a.size != b.size) return false;
		
		for (int i = 0; i < a.size; ++i)
		{
			for (int j = 0; j < a.size; ++j)
			{
				if(a.v[i][j] != b.v[i][j]) return false;
			}
		}

		return true;
	}
		
};
struct hashF
{
	size_t operator()(const board& a) const
	
	{
		size_t hash = 0;
		for (int i = 0; i < a.size; ++i)
		{
			for (int j = 0; j < a.size; ++j)
			{
				hash = (hash) ^ ((size_t{pow(97,i)} + size_t{pow(97,j)}) * a.v[i][j]);
			}
		}
		return hash;
	}
};


int main()
{
	
	int n;
	string line;
	while(cin >> n)
	{
		if(n == 0) break;
		
		getline(cin, line);
		
		unordered_set<board, hashF, comparator> s;
		board a{n};
		s.insert(a);

		int x, y;
		char op;
		n *= 2;
		
		int player = 0;
		int move = 0;
		bool brk = false;
		for(int i = 0; i < n; ++i)
		{
			getline(cin, line);
			istringstream sinp(line);
			sinp >> x >> y >> op;
			if(op == '+') a.push(x,y);
			else if(op == '-') a.pop(x,y);
			
			if(move == 1)
			{
				s.insert(a);
				a.rotation(); s.insert(a);
				a.rotation(); s.insert(a);
				a.rotation(); s.insert(a);
				a.rotation();
			}
			else
			{
				if(s.find(a) == s.end())
				{
					s.insert(a);
					a.rotation();
					if(s.find(a) == s.end())
					{
						s.insert(a);
						a.rotation();
						if(s.find(a) == s.end())
						{
							s.insert(a);
							a.rotation();
							if(s.find(a) == s.end())
							{
								s.insert(a);
								a.rotation();
							}
						}
					}
				}
				else 
				{
					player = (i+1) % 2 == 0 ? 1 : 2;
					move = (i+1);
					brk = true;
				}
			}
		}
		if(brk)
		{
			cout << "Player " << player << " wins on move " << move << endl;
		}
		else cout << "Draw" << endl;

	}
	
	return 0;
}
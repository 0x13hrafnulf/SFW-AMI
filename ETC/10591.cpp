#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int sum(const int& n)
{
	int sum = 0;
	int a = n;
	while(a != 0)
	{
		sum += (a % 10) * (a % 10);
		a /= 10;
	}

	return sum;
}

int main()
{
	int n, c; cin >> c;
	int i = 1;
	while(i <= c)
	{
		cin >> n;
		set<int> check;
		check.insert(n);
		int a = n;
		while(n != 1)
		{
			n = sum(n);
			if(check.find(n) != check.end()) 
			{
				cout << "Case #" << i << ": " 
					 << a << " is an Unhappy number." << endl;
				++i;
				break;
			}
			check.insert(n);
		}
		if(n == 1) 
		{
			cout << "Case #" << i << ": " 
				 << a << " is a Happy number." << endl;
			++i;
		}
	}

	return 0;
}
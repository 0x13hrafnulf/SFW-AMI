#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
int main()
{
	string A, B;
	while(getline(cin, A) and getline(cin, B))
	{
		istringstream subA(A);
		istringstream subB(B);
		
		int n;
		vector<int> setA;
		vector<int> setB;
		
		while(subA >> n)
		{
			setA.push_back(n);
		}
		sort(setA.begin(), setA.end());
		
		while(subB >> n)
		{
			setB.push_back(n);
		}
		sort(setB.begin(), setB.end());
		
		int i = 0;
		if(setA.size() >= setB.size())
		{
			if(equal(setA.begin(), setA.end(), setB.begin()))
			{
				cout << "A equals B" << endl;
				continue;
			}
			bool checkB = false;
			while(binary_search(setA.begin(), setA.end(), setB[i]) and i < setB.size())
			{
				checkB = true;
				++i;
			}
			
			if(checkB and i == setB.size()) cout << "B is a proper subset of A" << endl;
			else if(checkB and i < setB.size()) cout << "I'm confused!" << endl;
			else if(!checkB) cout << "A and B are disjoint" << endl;
			
		}
		else if(setA.size() <= setB.size())
		{
			if(equal(setB.begin(), setB.end(), setA.begin()))
			{	
				cout << "A equals B" << endl;
				continue;
			}
			bool checkA = false;
			while(binary_search(setB.begin(), setB.end(), setA[i]) and i < setA.size())
			{
				checkA = true;
				++i;
			}
			if(checkA and i == setA.size()) cout << "A is a proper subset of B" << endl;
			else if(checkA and i < setA.size()) cout << "I'm confused!" << endl;
			else if(!checkA) cout << "A and B are disjoint" << endl;
		}
	}
}
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

class TeamQueue {
	
	private:
	queue<int> Tlist;
	
	public:
	TeamQueue() 
	: 
		Tlist()
	{};
	void enqueue(int id);
	int dequeue();
	
	
};
void TeamQueue::enqueue(int id){
	
}
int TeamQueue::dequeue(){
	cout << Tlist.front() << endl;
	Tlist.pop();
	return 0;
}


int main(){
	int n, t = 1;
	string line;
	while(cin >> n){
		if(n == 0) break;
		getline(cin, line); //blank space

		int m;

		vector<vector<int>> l(n);
	
		for(int i = 0; i < n; ++i){
			getline(cin, line);
			istringstream sinp(line);
			sinp >> m;
			vector<int> a(m);
			for(int j = 0; j < m; ++j){
				sinp >> a[j];
			}
			l[i] = a;
		}
		cout << "Scenario #" << t << endl;
		string com;
		int numb;
		TeamQueue tq;
		while(cin >> com && com != "STOP"){
			if(com == "DEQUEUE"){
				tq.dequeue();
			}
			else{
				cin >> numb;
				
				
				
				
				
				enqueue(numb);
			}
		}
		++t;
		getline(cin, line); // blank
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class TeamQueue {
private:
	const int MAXNUMBEROFTEAMS = 1000;
	const int MAXID = 1000000;

	vector<queue<int> > teamMembers;
	vector<int> idContainer;
	queue<int> helpQueue;
	
public:
	TeamQueue();
	void enqueue(const int& id);
	int dequeue();

	void initializeTeams(const int& t);
};

TeamQueue::TeamQueue() : idContainer(MAXID), teamMembers(MAXNUMBEROFTEAMS) {
	
}

void TeamQueue::initializeTeams(const int& t) {
	for(int teamID = 0; teamID < t; teamID++) {
		int n;
		cin >> n;
		for(int j = 0; j < n; j++) {
			int memberID;
			cin >> memberID;
			
			idContainer[memberID] = teamID;
		}
	}
}

void TeamQueue::enqueue(const int& id) {
	int teamID = idContainer[id];
	
	if(teamMembers[teamID].empty()) {
		helpQueue.push(teamID);
	}
	
	teamMembers[teamID].push(id);
}

int TeamQueue::dequeue() {
	
	int teamID = helpQueue.front();
	int id = teamMembers[teamID].front();
	teamMembers[teamID].pop();
	
	if(teamMembers[teamID].empty()) {
		helpQueue.pop();
	}
	
	return id;
}

int main() {
	int t, scen = 1;
	
	while(true) {
		cin >> t;
		if(t == 0)
			break;
		
		TeamQueue tq;
		tq.initializeTeams(t);
		
		cout << "Scenario #" << scen++ << endl;
		
		string command;
		while(cin >> command) {
			if(command == "STOP") {
				cout << endl;
				break;
			}
			
			if(command == "DEQUEUE") {
				cout << tq.dequeue() << endl;
			}
			else {
				int id;
				cin >> id;
				tq.enqueue(id);
			}
		}
	}

	return 0;
}
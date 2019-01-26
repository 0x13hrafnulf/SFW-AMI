#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

class RobotWorld {
private:
	vector<vector<int> > table;
public:
	RobotWorld(const int& n);
	void moveOnto(int a, int b);
	void moveOver(int a, int b);
	void pileOnto(int a, int b);
	void pileOver(int a, int b);
	void printBlocks();
	int findBlockPos(const int& block);
};

RobotWorld::RobotWorld(const int& n) {
	for(int i = 0; i < n; i++) {
		vector<int> v;
		v.push_back(i);
		table.push_back(v);
	}
}

void RobotWorld::moveOnto(int a, int b) {

	int aPos = findBlockPos(a);
	int bPos = findBlockPos(b);
	
	if(table[aPos].size() > 1) {
		vector<int>::iterator it = table[aPos].end();
		it--;
		for(; *it != a; --it) {
			table[*it].push_back(*it);
			table[aPos].pop_back();
		}
	}

	if(table[bPos].size() > 1) {
		vector<int>::iterator it = table[bPos].end();
		it--;
		for(; *it != b; --it) {
			table[*it].push_back(*it);
			table[bPos].pop_back();
		}
	}

	table[bPos].push_back(a);
	table[aPos].pop_back();
}

void RobotWorld::moveOver(int a, int b) {

	int aPos = findBlockPos(a);
	int bPos = findBlockPos(b);
	
	if(table[aPos].size() > 1) {
		vector<int>::iterator it = table[aPos].end();
		it--;
		for(; *it != a; --it) {
			table[*it].push_back(*it);
			table[aPos].pop_back();
		}
	}

	table[bPos].push_back(a);
	table[aPos].pop_back();
}

void RobotWorld::pileOnto(int a, int b) {

	int aPos = findBlockPos(a);
	int bPos = findBlockPos(b);
	
	if(table[bPos].size() > 1) {
		vector<int>::iterator it = table[bPos].end();
		it--;
		for(; *it != b; --it) {
			table[*it].push_back(*it);
			table[bPos].pop_back();
		}
	}

	vector<int>::iterator it = find(table[aPos].begin(), table[aPos].end(), a);

	while (it != table[aPos].end()) {
		table[bPos].push_back(*it);
		it = table[aPos].erase(it);
	}
}

void RobotWorld::pileOver(int a, int b) {

	int aPos = findBlockPos(a);
	int bPos = findBlockPos(b);

	vector<int>::iterator it = find(table[aPos].begin(), table[aPos].end(), a);

	while (it != table[aPos].end()) {
		table[bPos].push_back(*it);
		it = table[aPos].erase(it);
	}
}

void RobotWorld::printBlocks() {
	int i = 0;
	for(vector<int> it : table) {
		cout << i++ << ":";
		for(int el : it) {
			cout << " " << el;
		}
		cout << endl;
	}
}

int RobotWorld::findBlockPos(const int& blockNum) {
	int i = 0;
	for(vector<int> it : table) {
		if(find(begin(it), end(it), blockNum) != end(it))
			return i;
		i++;
	}
	return -1;
}

void executeCommand(const string& command, RobotWorld& rw) {
	istringstream sinp(command);
	string first, second;
	int a, b;
	sinp >> first >> a >> second >> b;

	if(a != b && rw.findBlockPos(a) != rw.findBlockPos(b)) {
		if(first == "move") {
			if(second == "onto") {
				rw.moveOnto(a, b);
			}
			else if(second == "over") {
				rw.moveOver(a, b);
			}
		}
		else if(first == "pile") {
			if(second == "onto") {
				rw.pileOnto(a, b);
			}
			else if(second == "over") {
				rw.pileOver(a, b);
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	RobotWorld rw(n);

	string command;

	while(getline(cin, command)) {
		if(command == "quit")
			break;
		executeCommand(command, rw);
	}

	rw.printBlocks();

	return 0;
}
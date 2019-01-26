#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void parse(const string& line, vector<int>& pos){
	istringstream sinp(line);
	sinp >> pos[0];
	sinp >> pos[1];
	sinp >> pos[2];	
}
bool check(int k, int q, int s){
	bool between = false;
	if(k <= s and q < k) between = true;
	else if(k >= s and q > k) between = true;
	return between;
}
int main(){	
	string line;
	while(getline(cin, line)){
		vector<int> pos(3);
		parse(line, pos);
		int kx, ky, qx, qy, sx, sy;
		kx = pos[0]/8; ky = pos[0]%8;
		qx = pos[1]/8; qy = pos[1]%8;
		sx = pos[2]/8; sy = pos[2]%8;
		if(pos[0] == pos[1]) cout << "Illegal state" << endl;
		else if(pos[1] == pos[2]) cout << "Illegal move" << endl;
		else if(qx != sx and qy != sy) cout << "Illegal move" << endl;	
		else{
			if((qx == sx and kx == sx and check(ky, qy, sy)) or (qy == sy and ky == sy and check(kx, qx, sx))) {
				cout << "Illegal move" << endl;
			}
			else if(abs(kx - sx) + abs(ky - sy) == 1) cout << "Move not allowed" << endl;
			else if((pos[0] == 0 and pos[2] == 9) or (pos[0]==7 and  pos[2] ==14) or (pos[0]==56 and  pos[2]==49) or (pos[0]==63 and  pos[2]==54)) 
				cout << "Stop" << endl;
			else cout << "Continue" << endl;
			}
	}	
	return 0;
}
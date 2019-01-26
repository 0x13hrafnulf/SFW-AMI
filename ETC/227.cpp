#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

void shuffle(vector<string>& puzzle,const string& line, int& bi, int& bj){
	int l = line.size();
	for (int i = 0; i < l; i++ ) {
		if(line[i] == '0') break;
		else{
			if(line[i] == 'A'){	
				puzzle[bi][bj] = puzzle[bi - 1][bj];
				puzzle[bi - 1][bj] = ' '; --bi;
			}
			else if(line[i] == 'B'){
				puzzle[bi][bj] = puzzle[bi + 1][bj];
				puzzle[bi + 1][bj] = ' '; ++bi;
				
			}
			else if(line[i] == 'R'){
				puzzle[bi][bj] = puzzle[bi][bj + 1];
				puzzle[bi][bj + 1] = ' '; ++bj;
				
			}
			else if(line[i] == 'L'){
				puzzle[bi][bj] = puzzle[bi][bj - 1];
				puzzle[bi][bj - 1] = ' '; --bj;			
			}
		}
	}
}
bool valid(const string& line, const int& bi, const int& bj){
	bool check = true;
	int l = line.size();
	int ti = bi;
	int tj = bj;
	for (int i = 0; i < l; i++ ) {
		if(line[i] == '0') break;
		else{
			if(line[i] == 'A'){
				if(ti == 0) check = false;
				--ti;
			}
			else if(line[i] == 'B'){
				if(ti == 4) check = false;
				++ti;
			}
			else if(line[i] == 'R'){
				if(tj == 4) check = false;
				++tj;
			}
			else if(line[i] == 'L'){
				if(tj == 0) check = false;
				--tj;
			}
			else check = false;
		}	
	}
	return check;
}
int main(){	

	vector<string> l(5);
	string command;
	int bi, bj;
	int j = 1;
	bool anyLine = false;
	while(getline(cin, l[0])){
		if(l[0] == "Z") break;
		getline(cin, l[1]);
		getline(cin, l[2]);
		getline(cin, l[3]);
		getline(cin, l[4]);		
		
		for (int i = 0; i < 5; i++ ) {
			for ( int j = 0; j < 5; j++ ) {
				if (l[i][j] == ' '  or l[i].size() == 4) {
					bi = i;
					bj = (l[i].size() == 4) ? 4 : j;
					i = j = 5;
				}
			}
		}
		bool isValid = true;
		while(getline(cin, command)){
			isValid = valid(command, bi, bj);
			if(!isValid) break;
			else{
				shuffle(l, command, bi, bj);
				if(command[command.size()-1] == '0') break;
			}
		}
		if(anyLine) cout << endl;
		anyLine = true;
		
		cout << "Puzzle #" << j << ":" << endl;
		if(isValid){
			cout << l[0][0] << " " << l[0][1] << " "<< l[0][2] << " "<< l[0][3] << " "<< l[0][4] << endl;
			cout << l[1][0] << " " << l[1][1] << " "<< l[1][2] << " "<< l[1][3] << " "<< l[1][4] << endl;
			cout << l[2][0] << " " << l[2][1] << " "<< l[2][2] << " "<< l[2][3] << " "<< l[2][4] << endl;
			cout << l[3][0] << " " << l[3][1] << " "<< l[3][2] << " "<< l[3][3] << " "<< l[3][4] << endl;
			cout << l[4][0] << " " << l[4][1] << " "<< l[4][2] << " "<< l[4][3] << " "<< l[4][4] << endl;
		}else{
			cout << "This puzzle has no final configuration." << endl;
		}
		++j;
	}
	return 0;
}
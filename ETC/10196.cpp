#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

bool isEmp(const vector<string>& board){
	int l = board.size();
	bool check = false;
	for (int i = 0; i < l; i++ ) {
		for (int j = 0; j < l; j++ ) {
			if(isalpha(board[i][j])) check = true;
		}
	}
	return check;
}

int main(){
	vector<string> board(8);
	while(getline(cin, board[0])){
		
		for(int i = 1; i < 8; ++i){
			getline(cin, board[i]);
		}
		
		bool valid = isEmp(board);
		if(!valid) break;
		else{
			
			
			
			
			
		}
	}
	return 0;
}
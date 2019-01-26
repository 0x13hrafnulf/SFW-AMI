#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(){		
	int n;
	while(cin >> n){
		if(n == 0) break;
		int matrix[n][n];
		vector<int> rows(n); 
		vector<int> cols(n);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> matrix[i][j];
				rows[i] += matrix[i][j];
				cols[j] += matrix[i][j];
			}
		}
		
		int row = 0, crow = 0;
		int col = 0, ccol = 0;
		for(int i = 0; i < n; ++i){
			if(rows[i]%2 != 0) {
				row = i;
				++crow;
			}
			if(cols[i]%2 != 0) {
				col = i;
				++ccol;
			}
		}
		if(crow + ccol == 0) cout << "OK" << endl;
		else if (crow == 1 && ccol == 1) cout<< "Change bit (" << row+1 << "," << col+1 << ")"<< endl;
		else cout << "Corrupt" << endl;
	}
	return 0;
}
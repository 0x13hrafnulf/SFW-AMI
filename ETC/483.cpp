#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(){	
	string line;
	while(getline(cin, line)){
		
		istringstream sinp(line);
		bool space = false;
		while(sinp >> line){
			int l = line.size();
			
			if(space) cout << " ";
			space = true;
	
			for(int i = l-1; i >= 0; --i) cout << line[i];
			
		}
		cout << endl;

	}
	return 0;
}
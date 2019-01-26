#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(){
	vector<string> song = {"Happy", "birthday", "to", "you",
	"Happy", "birthday", "to", "you",
	"Happy", "birthday", "to", "Rujia",
	"Happy", "birthday", "to", "you"};
	int n; cin >> n;
	vector<int> c(n);
	vector<string> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];	
	}
	int loop;
	if(n % 16 > 0) loop = n/16 + 1;
	else loop = n/16;
	loop *= 16;
	
	
	int i = 0;
	int j = 0;
	while(loop--){
		cout << v[i] << ": " << song[j] << endl;
		++i;
		++j;
		if(i == n) i = 0;
		if(j == 16) j = 0;
	}
	return 0;
}
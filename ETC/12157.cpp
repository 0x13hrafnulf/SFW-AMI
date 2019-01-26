#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){	
	int test,j, mile, juice,n; cin >> test;
	while(test--){
		++j;
		cin >> n;
		mile = 0;
		juice = 0;
		vector<int> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
			mile += (v[i]/30)*10 + 10;
			juice += (v[i]/60)*15 + 15;
		}
		if(mile < juice) cout << "Case " << j << ": " <<"Mile " << mile << endl;
		else if(mile > juice) cout << "Case " << j << ": " <<"Juice " << juice << endl;
		else cout << "Case " << j << ": " <<"Mile Juice " << mile << endl;
	}
	return 0;
}
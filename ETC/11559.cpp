#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

int main(){
	int n, b, h, w, result, min = 0;
	while(cin >> n >> b >> h >> w){
		result = 99999999;
		min = 0;
		vector<int> p(h);
		for(int i = 0; i < h; ++i){
			cin >> p[i];
			vector<int> a(w);			
			for(int j = 0; j < w; ++j){
				cin >> a[j];
				if(a[j] >= n) {
					min = p[i]*n;
					if(min < result) result = min;
				}
			}
		}
		if (result > b) cout << "stay home" << endl;
		else cout << result << endl;
	}
	return 0;
}
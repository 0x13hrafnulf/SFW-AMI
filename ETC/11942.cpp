#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int test; cin >> test;
	cout << "Lumberjacks:" << endl;
	while(test--){
		bool order = false;
		vector<int> v(10);
		for(int i = 0; i < 10; ++i){
			cin >> v[i];		
		}
		auto max =  max_element(v.begin(), v.end());
		if(*max == v[9]){
			order = is_sorted(v.begin(),v.end());
		}
		else if(*max == v[0]){
			reverse(v.begin(),v.end());
			order = is_sorted(v.begin(),v.end());
		}
		if(order == true) 
			cout << "Ordered" << endl;
		else 
			cout << "Unordered" << endl;
	}
	
	
	
	return 0;
}
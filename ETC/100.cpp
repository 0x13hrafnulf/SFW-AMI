#include <iostream>

using namespace std;
int main(){
	int a, b;
	
	while(cin >> a >> b){
		int x = a;
		int y = b;
		if (x > y) swap(x,y);
		
		int r = 0;
		for (int i = x; i <= y; ++i){
			int t = i;
			int c = 1;
			while(t != 1){
				++c;
				if (t%2 == 0) 
					t /=2;
				else 
					t = 3*t + 1;
			}
			r = max(r,c);
		}
		cout << a << ' ' << b << ' ' << r << "\n";
	}

	return 0;
}
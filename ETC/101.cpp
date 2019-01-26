#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
class RobotWorld 
{
	private:

	public:
	int ax, ay, bx, by;
	vector<vector<int>> w;
	void output(const RobotWorld& a);
	void moveOnto(const int& a, const int& b);
	void moveOver(const int& a, const int& b);
	void pileOnto(const int& a, const int& b);
	void pileOver(const int& a, const int& b);
	void find(const int& a, const int& b);
	//constructor
	RobotWorld(const int& n);
};

RobotWorld::RobotWorld(const int& n){
	for(int i = 0; i < n; ++i){
		vector<int> a;
		a.push_back(i);
		w.push_back(a);
	}
}
void output(RobotWorld& a){
	RobotWorld *p = &a;
	for ( int i = 0; i < p->w.size(); ++i ) {
        cout << i << ":";
        for ( int j = 0; j < p->w[i].size(); ++j){
            cout << " " << p->w[i][j];
		}
        cout << endl;
    }
}
void RobotWorld::find(const int& a, const int& b){
	
	for ( int i = 0; i < w.size(); ++i ) {
        for ( int j = 0; w[i].size(); ++j ) {
            if (w[i][j] == a ) {
                ax = i;
                ay = j;
            }
            else if (w[i][j] == b ) {
                bx = i;
                by = j;
            }
        }
    }
}
void RobotWorld::moveOnto(const int& a, const int& b){
	
}
void RobotWorld::moveOver(const int& a, const int& b){

}
void RobotWorld::pileOnto(const int& a, const int& b){

}
void RobotWorld::pileOver(const int& a, const int& b){

}

int main(){
	
	int n;
	while(cin >> n){
		RobotWorld r = RobotWorld(n);
		string line, command, ovpi;
		int a,b;
		// while(getline(cin, line)){
			// istringstream sinp(line);
			// sinp >> command;
			// if(command == "quit") break;
			// else{
				// sinp >> a >> ovpi >> b;
				// if (command == "move" and ovpi == "onto"){
					// r.moveOnto(a,b);
				// }
				// else if(command == "move" and ovpi == "over"){
					// r.moveOver(a,b);
				// }
				// else if(command == "pile" and ovpi == "onto"){
					// r.pileOnto(a,b);
				// }
				// else if(command == "pile" and ovpi == "over"){
					// r.pileOver(a,b);
				// }					
			// }
		// }
		output(r);
	}
	return 0;
}
#include <iostream>
#include <algorithm>


class VecInt{
	
	private:
	
	int* a;
	int cp;
	int sz;
	
	public:
	
	VecInt()
	: a(nullptr), sz(0), cp(0)
	{}
	
	~VecInt(){
		delete[] a;
	};
	
	int& operator[](int index){
		return a[index];
	}
	const int& operator[](int index) const{
		return a[index];
	}
	int size() const
	{
		return sz;
	}
	void pushBack(int x);
	
	int* begin(){
		return a;
	}
	int* end(){
		return a + sz;
	}
	
	VecInt(const VecInt& other) : cp(other.cp), sz(other.sz)
	{
		a = new int[sz];
		for (int i = 0; i < sz; ++i){
			
			a[i] = other[i];
		}
	}
	
	VecInt& operator=(const VecInt& other)
	{
		if(this != &other){
			delete[] a;
			sz = other.sz;
			cp = other.cp;
			
			a = new int[sz];
			
			for(int i = 0; i < other.size(); ++i)
			{
				a[i] = other[i];
			}
		}
		
		return *this;
	}

};

void VecInt::pushBack(int x){
	if(sz == cp) {
		cp = cp == 0 ? 1 : cp * 2;
		int* p = new int[cp];
		for (int i = 0; i < sz; ++i){
			p[i] = a[i];
		}
		delete[] a;
		a = p;
	}
	a[sz] = x;
	++sz;
}
bool operator==(const VecInt& a, const VecInt& b){
	
if (a.size() != b.size())
	{
		return false;
	}
	
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	
	return true;
}
bool operator!=(const VecInt& a, const VecInt& b){
	return !(a == b);
}








using namespace std;
int main(){
	VecInt v;
	int x;
    while (cin >> x)
    {
        v.pushBack(x);
    }
	VecInt w = v;
	reverse(w.begin(), w.end());
    
    cout << (v == w ? "palindrome": "not a palindrome");
	return 0;
}
#include <iostream>
#include <vector>

class VecInt{
	private:
	int* a;
	int sz;
	int cp;
	
	public:
	
	VecInt() 
	: a(nullptr), sz(0), cp(0)
	{}
	
	~VecInt()
	{
		delete[] a;
	}
	
	VecInt(const VecInt& other)
	: sz(other.sz), cp(other.cp)
	{
		a = new int[other.sz];
		
		for (int i = 0; i < other.sz; ++i)
		{
			a[i] = other[i];
		}
		
	}

	VecInt& operator=(const VecInt& other)
	{
		if (this != &other) 
		{
			sz = other.sz;
			cp = other.cp;
			delete[] a;
			a = new int[sz];
			
			for (int i = 0; i < sz; ++i)
			{
				
				a[i] = other[i];
			}
		}
		return *this;
	}
	
	int* begin()
	{
		return a;
	}
	int* end()
	{
		return a + sz;
	}
	int size() const 
	{
		return sz;
	}
	
	int& operator[] (int index)
	{
		return a[index];
	}
	const int& operator[] (int index) const
	{
		return a[index];
	}
	
	void pushBack(int x);
	int* erase(int* it);
	int* insert(int* it, int x);
	void ensureCapacity();
};

void VecInt::ensureCapacity()
{
	if(sz == cp)
	{
		cp = cp == 0 ? 1 : cp * 2;
		int* p = new int[cp];
		for(int i = 0; i < sz; ++i)
		{
			p[i] = a[i];
		}
		delete[] a;
		a = p;
	}
}
void VecInt::pushBack(int x){
	ensureCapacity();
	a[sz] = x;
	++sz;
}
int* VecInt::insert(int* it, int x) 
{
	int index = it - begin();
	ensureCapacity();
	
	for (int i = sz; i > index; --i){
		a[i] = a[i - 1];
	}
	a[index] = x;
	++sz;
	return a + index;
}
int* VecInt::erase(int* it) 
{
	int index = it - begin();
	
	for (int i = index; i < sz - 1; ++i) {
		a[i] = a[i+1];
	}
	--sz;
	return a + index;
}
bool operator==(const VecInt& a, const VecInt& b){
	if (a.size() != b.size()) return false;
	
	for(int i = 0; i < a.size(); ++i){
		if(a[i] != b[i]) return false;	
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
	
	auto it = v.begin();
    while (it != v.end())
    {
        if (*it % 2 == 0)
        {
            it = v.insert(it, 0);
            ++it;
        }
        ++it;
    }
	for (int e: v)
    {
        cout << e << " ";
    }
    cout << endl;
	
	it = v.begin();
    while (it != v.end())
    {
        if (*it % 2 == 0)
        {
            it = v.erase(it);
        }
        else
        {
            ++it;
        }
    }
    
    for (int e: v)
    {
        cout << e << " ";
    }
    cout << endl;
	
	return 0;
}
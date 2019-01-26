#include <iostream>
#include <stdexcept>

#include "BigInt.h"

using namespace std;

int main()
{
	BigInt a;
	BigInt b;
	char op;
	try {
		cin >> a >> op >> b;
		BigInt c;
		switch (op)
            {
                case '+':
                    c = a + b;
                    cout << c << endl;
                    break;
                case '-':
                    c = a - b;
                    cout << c << endl;
                    break;
                case '*':
                    c = a * b;
                    cout << c << endl;
                    break;
                case '/':
                    c = a / b;
                    cout << c << endl;
                    break;
                default:
                    cout << "Unknown operation: " << op << endl;
                    break;
            }
	}
	catch (exception& e)
	{
		cout << e.what() << endl;	
	}
    
    return 0;
}
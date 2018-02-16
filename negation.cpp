#include <bits/stdc++.h>
using namespace std;

class Negation
{
public:
	int a, b;
	Negation()
	{
		a = 0;
		b = 0;
	}
	Negation(int x, int y)
	{
		a = x;
		b = y;
	}
	void display()
	{
		cout<<"x = "<<a<<" y = "<<b<<endl;
	}
	Negation operator - ()
	{
		a = -a;
		b = -b;
		return Negation(a, b);
	} 
};

int main()
{
	Negation N;
	cout<<"Enter x and y: ";
	cin>>N.a>>N.b;
	-N;
	N.display();
	return 0;
}
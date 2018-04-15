#include <bits/stdc++.h>
using namespace std;

class octal
{
	int oct[15], count;
public:
	octal(int x);
	int operator + (int);
	friend ostream & operator << (ostream &, octal &);
};

octal::octal(int x)
{
	int rem, i=0, A[15];
	while(x!=0)
	{
		rem = x%8;
		x = x/8;
		A[i++] = rem;
	}
	count = i;
	int n = count-1;
	for(i=0; i<count; i++)
		{
			oct[i] = A[n];
			n--;
		}
}

int octal::operator + (int k)
{
	int i, x=0, j=count-1;
	for(i=0;i<count;i++)
	{
		x+=oct[j]*pow(8,i);
		j--;
	}
	return (x+k);
}

ostream & operator << (ostream &out, octal &o)
{
	for(int i=0;i<o.count;i++)
	out<<o.oct[i];
	return out;
}

int main()
{
	int a, b, sum=0;
	cout<<"Enter an integer value: ";
	cin>>a;
	octal o = octal(a);
	cout<<"Corresponding octal value is: "<<o;
	cout<<"Enter integer to be added: ";
	cin>>b;
	sum = a+b;
	cout<<"Sum is: "<<sum<<endl;
}
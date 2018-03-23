#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	cout<<"Enter a number: ";
	cin>>a;
	float b = sqrt(a);
	cout.precision(4);
	cout<<b<<endl;

	char x = '#';
	cout.width(10);
	cout.fill(x);
	cout<<b<<endl;
	
  return 0;
}
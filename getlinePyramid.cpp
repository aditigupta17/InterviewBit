#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[100];
	int i;
	cout<<"Enter some data: ";
	cin.getline(s, 100);
	printf("Your text goes here: ");
	for(i=0;i<=strlen(s);i++)
	{
		cout.write(s, i);
		printf("\n");
	}	
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[100];
	cout<<"Enter some data: ";
	cin.getline(s, 100);
	printf("Your text goes here: ");
	cout.write(s, strlen(s));
	printf("\n");		
}
#include <bits/stdc++.h>
using namespace std;
#define N 100

int main()
{
	ifstream f1, f2;
	char line[N];
	f1.open("country.txt");
	f2.open("capital.txt");
	for(int i=0;i<5;i++)
	{
		if(f1.eof()) exit(1);
		else {
			f1.getline(line, N);
			cout.write(line, strlen(line));
		}
		printf("\t");
		if(f2.eof()) exit(1);
		else {
			f2.getline(line, N);
			cout.write(line, strlen(line));
		}
		printf("\n");
	}
}


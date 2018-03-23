#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	ofstream file1;
	file1.open("f1.txt");
	file1<<"What does the fox say?\n";
	file1.close();

	ifstream file2("f1.txt");
	if(file2.is_open())
	{
		while(!file2.eof())
		{
			getline(file2, s);
			cout<<s<<endl;
		}
	}
	else cout<<"Unable to open file";

	cout<<s;
	cin>>s;
	file2.open ("f1.txt");
	if (file2.is_open())
	{
		while (!file2.eof())
		{
			getline (file2,s);
			cout << s<< endl;
		}
		file2.close();
	}
	else cout << "unable to open file";
	return 0;
}
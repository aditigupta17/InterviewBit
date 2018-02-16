#include <bits/stdc++.h>
using namespace std;

class Time
{
public:
	int hr, min, sec;
	Time()
	{
		hr = 0;
		min = 0;
		sec =0;
	}
	Time(int h, int m, int s)
	{
		hr = h;
		min = m;
		sec = s;
	}
	void display()
	{
		cout<<hr<<":"<<min<<":"<<sec<<endl;
	}
	Time operator++()
	{
		sec += 1;
		if(sec>59)
		{
			sec = 0;
			min+=1;
			if(min>59)
			{
				min = 0;
				hr+=1;
				if(hr>23)
					hr=0;
			}
		}
		return Time(hr, min, sec);
	}
};

int main()
{
	Time T;
	cout<<"Enter a random time (Constraints: 0<=hr<=23, 0<=min<=59, 0<=sec<=59): ";
	cin>>T.hr>>T.min>>T.sec;
	for(int i=0; i<30; i++)
	{
		++T;
		T.display();
	}
	return 0;
}
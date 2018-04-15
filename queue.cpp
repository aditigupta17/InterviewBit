#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
	int a[5], front, rear, x, result;
	void enq();
	void deq();
	void disp();
	Queue()
	{
		front =0;
		rear =0;
	}
};

void Queue::enq()
{
	if(rear>=5) printf("Queue overflow.\n");
	else
	{
		printf("Enter number to be inserted: ");
		cin>>x;
		rear++;
		a[rear] = x;
		printf("Element added = %d.\n", a[rear]);
	}
}

void Queue::deq()
{
	if(rear==0) printf("Queue underflow.\n");
	else 
	{
		if(front==rear)
		{
			front=0;
			rear=0;
		}
		else front++;
	}
	printf("Deleted element = %d.\n", a[front]);
}

void Queue::disp()
{
	if(rear==0) printf("Queue underflow.\n");
	else
	{
		for(int i=front+1; i<=rear; i++)
			printf("%d ", a[i]);
	}
}

int main()
{
	Queue Q;
	int ch;
	do
	{
		cout<<"1. Insertion 2. Deletion 3. Display Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: 
				Q.enq();
				break;
			case 2:
				Q.deq();
				break;
			case 3:
				Q.disp();
				break;
		}
	}
	while(ch<4);
}
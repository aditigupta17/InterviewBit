#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n, head, i;
	printf("Enter number of requests: ");
	scanf("%d", &n);
	int A[n];
	printf("Enter the head location: ");
	scanf("%d", &head);
	printf("Enter %d seek positions: ", n);
	
	for(i=0;i<n;i++)
		scanf("%d", &A[i]);

	int cur = head, t = n, index, sum=0;
	printf("Sequence: %d --> ", head);
	while(t--)
	{
		int min = 9999;
		for(i=0;i<n;i++)
		{
				if(A[i]>=0 && abs(A[i]-cur)<=min)
				{
					min = abs(A[i]-cur);
					index = i;
				}
		}
		printf("%d --> ", A[index]);
		sum += min;
		cur = A[index];
		A[index] = -1;
	}
	
	printf("\nTotal distance travelled is %d.\n", sum);

}

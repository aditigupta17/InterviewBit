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

	printf("Order:\n%d to %d\n", head, A[0]);
	for(i=0;i<n-1;i++)
		printf("%d to %d\n", A[i], A[i+1]);
	
	int seekTime = abs(head-A[0]);

	for(i=1;i<n;i++)		
		seekTime += abs(A[i]-A[i-1]);

	printf("Total distance travelled is %d.\n", seekTime);

}

//MFT Best Fit
#include <stdio.h>

int main()
{
	int size, n, m, i;
	printf("Enter the memory size: ");
	scanf("%d", &size);

	printf("Enter the number of partitions: ");
	scanf("%d", &n);

	int A[n][2], B[n][2];
	printf("Enter the sizes of partitions: ");
	for(i=0;i<n;i++){
		scanf("%d", &A[i][0]);
		A[i][1] = 0;
	}
	printf("Enter the number of processes: ");
	scanf("%d", &m);
	for(i=0;i<m;i++)
	{
		int flag = 0, temp;
		printf("Enter memory required by process %d: ", i+1);
		scanf("%d", &B[i][0]);
		B[i][1] = 0;
		int j, min = 99999;
		for(j=0;j<n;j++)
		{
			if(A[j][0]>=B[i][0] && A[j][0]<=min)
			{
				min = A[j][0];
				temp = j;
				B[i][1] = j+1;
				flag = 1;
			}
		}
		A[temp][0] = A[temp][0] - B[i][0];
		A[temp][1] = 1;
		for(j=0;j<n;j++)
			printf("%d ", A[j][1]);
		printf("\n");
		if(flag==1)
		{
			printf("Process allocated in fragment %d.\n", B[i][1]);
		}
		if(flag==0)
		{
			int sum=0;
		
			for(i=0;i<n;i++)
			{
				if(A[i][1]==0) sum+=A[i][0];
			}
			printf("External fragment= %d\n", sum);
			if(sum>=B[i][0]) printf("External fragmentation. Enough memory size but not contiguous.\n");
			else printf("Insufficient Memory. Process cannot be allocated memory.\n");
		}

	}

}
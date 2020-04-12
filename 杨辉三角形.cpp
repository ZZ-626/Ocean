#include <stdio.h>
void main()
{
	int i;
	int j;
	int a[10][10];
	a[0][0]=1;
	for(i=0;i<10;i++)
	{
		a[i][0]=1;
		for(j=0;j<10;j++)
		{
			if(j==0)
				a[i][j]=a[0][0];
			else if(i>=1&&j>=1&&i!=j)
				a[i][j]=a[i-1][j]+a[i-1][j-1];
			else if(i==j)
			a[i][j]=a[i-1][j-1];
		}
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<=i;j++)
			printf("%4d ",a[i][j]);

		printf("\n");
		}
	}

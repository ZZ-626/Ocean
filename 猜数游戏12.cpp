#include <stdlib.h>
#include <stdio.h>
int main()
{
	int a = rand();
	int	b, i = 1;
	printf("请输入0~100的数：");
	for (i = 1; i < 11; i++)
	{
		scanf_s("%d", &b);
		if (a == b) {
			printf("恭喜你答对了");
			break;
		}
		else if (a < b && 0 < b < 100)
			printf("猜大了\n");
		else if (a > b && 0 < b < 100)
			printf("猜小了\n");
	}
	return 0;

}
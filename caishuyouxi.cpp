#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
	int a;
	srand((unsigned)time(NULL));
	a = rand() % 101;
	int	b, i = 1, flag = 1;
	printf("������0~100������");
	for (i = 1; flag; i++)
	{
		scanf_s("%d", &b);
		if (a == b) {
			printf("��ϲ������");
			flag = 0;
			break;
		}
		else if (a < b && 0 < b < 100)
			printf("�´���\n");
		else if (a > b && 0 < b < 100)
			printf("��С��\n");
	}
	return 0;

}
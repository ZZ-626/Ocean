#include <stdlib.h>
#include <stdio.h>
int main()
{
	int a = rand();
	int	b, i = 1;
	printf("������0~100������");
	for (i = 1; i < 11; i++)
	{
		scanf_s("%d", &b);
		if (a == b) {
			printf("��ϲ������");
			break;
		}
		else if (a < b && 0 < b < 100)
			printf("�´���\n");
		else if (a > b && 0 < b < 100)
			printf("��С��\n");
	}
	return 0;

}
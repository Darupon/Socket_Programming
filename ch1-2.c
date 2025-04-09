#include <stdio.h>

int gugudan(int, int);

int main()
{
	int num1 = 0;
	int num2 = 0;
	int temp = 0;

	printf("숫자 2개를 입력해주세요: ");
	scanf("%d %d", &num1, &num2);
	
	if(num1 > num2) // 무조건 num1이 num2보다 작게 만들기
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	gugudan(num1, num2);

	return 0;
}

int gugudan(int num1, int num2)
{
	int i = num1;
	for(; i <= num2; ++i)
	{
		int j = 1;
		for(; j < 10; ++j)
		{
			printf("%d x %d = %d \n", i, j, i * j);
		}
	}
}

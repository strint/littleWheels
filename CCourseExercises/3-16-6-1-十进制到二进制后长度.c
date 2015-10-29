#include<stdio.h>
#include<stdlib.h>

int f(int,int);

main()
{
	int m,n;
	int num[20]={0};//声明数组 

	printf("请输入要处理整数的个数\n");
    
    scanf("%d",&m);

	printf("请输入正整数:\n");

	for(n=1;n<=m;n++)//输入 
	{
		scanf("%d",&num[n-1]);
	}
		
	printf("转换后的长度是:\n");
		
	for(n=1;n<=m;n++)//调用函数并打印结果 
		{
			int a=1;

			printf("%5d",f(num[n-1],a));
		}
		system("pause");
		return 0;
}


int f(int num,int i)//求位数的递归函数 
{
	if(num/2==0)
		return 1;
	else
		return (1+f(num/2,i++));
}

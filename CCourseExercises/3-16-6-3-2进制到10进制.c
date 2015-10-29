#include <stdio.h>
#include<stdlib.h> 
void turn(int,int,int);

main()
{
	int num;
	
	printf("请输入2进制数:\n");
    scanf("%d",&num);

	turn(num,0,0);
}


void turn(int num,int i,int result)//数组处理 
{
	int a,b,j;

	if(num==0)
	{
        printf("十进制为%d\n",result);
        system("pause");
	}
	else
	{
		a=num%10;
		i++;
		b=1;
		for(j=2;j<=i;j++)//2的n次幂 
		{
			b=2*b;
		}
		result=a*b+result;
		
		turn(num/10,i,result);
	}
}

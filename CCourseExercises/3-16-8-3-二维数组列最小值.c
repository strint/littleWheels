#include<stdio.h>
void fun(int tt[][4],int pp[]);

main()
{
	int tt[3][4]={{22,45,56,30},
	{19,33,45,38},
	{20,22,66,40}};//数组初始化
	int pp[4]={0};
	
  
	fun(tt,pp);

	system("pause");
     
    return 0;
}

void fun(int tt[][4],int pp[])//比较后打印
{
	int min,i,j;

    printf("the original data is:\n");

	for(i=0;i<=2;i++)
	{   
		for(j=0;j<=3;j++)
		{
			printf("%5d",tt[i][j]);
		}
		printf("\n");
	}//打印原数组
			
    for(j=0;j<=3;j++)
	{   
		min=100;

		for(i=0;i<=2;i++)
		{
			if(tt[i][j]<min)
				min=tt[i][j];
		}
		pp[j]=min;
	}
	
	printf("the result is:\n");

	for(j=0;j<=3;j++)
	{
		printf("%5d",pp[j]);
	}
    	printf("\n");
}


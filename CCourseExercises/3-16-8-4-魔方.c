/*魔方--每行或每列的和都相等*/
#include<stdio.h>
#include<stdlib.h> 

main()
{
	int n,m,i,j,si=0,sj=0;
	int a [16][16]={0};//数组声明 
	
    printf("enter n(从1到15的任一奇数):");
	
	scanf("%d",&n);

	i=1;
	j=n/2 + 1;

	a [i][j]=1;//1的赋值 

	for(m=2;m<=n*n;m++)
	{
		si=i;
		sj=j;//复制i,j的值，方便再次使用 

		if(i==1&&j==n)//1行n列 
		{
			i=2;
		}
		else
		{
			if(i==1)//1行 
				i=n;
			else
				i--;
			if(j==n)//n列 
				j=1;
			else
				j++;
		}
		if(a[i][j]==0)//判断是否是空位 
			a[i][j]=m;
		else
		{
			i=si+1;
		    j=sj;
			a[i][j]=m;
		}

	
	}
		
	for(i=1;i<=n;i++)//打印 
	{   
		for(j=1;j<=n;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
		
	}
    system("pause");
    return 0;
}















































































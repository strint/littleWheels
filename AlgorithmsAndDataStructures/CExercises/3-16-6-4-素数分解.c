/*素数分解*/ 
#include<stdio.h>
#include<stdlib.h>

void divide(int,int,int);//函数原型 

int main()
{
	int n1,n2,m;
	/*键入范围*/ 
	printf("请输入范围(from,to)\n:");
	scanf("%d",&n1);
	scanf("%d",&n2);
    
    printf("素数分解结果为：\n");
    /*调用递归函数逐数分解打印*/ 
	for(m=n1;m<=n2;m++)
	{
		divide(m,2,0);
		printf("\n");
        
	}
    
    system("pause");
	return 0;
}

/*函数*/ 
void divide(int num,int a,int i)
{
		if(num%a==0)
		{

				i++;
				if(i>1)
				{
					printf("*%d",a);//第二及以上的质因数 
				}
				else
                {
			        printf("%d=%d",num,a);//第一个质因数 
				}
       
                divide(num/a,a,i);//递归 
		}
		else
		{
            if(num!=1)
            {
                        a++;
			  divide(num,a,i);//不能用a++？//递归 
            }
            /*else
              {
                                //printf(".");
                                //return;
              }没用*/              
		}
}



 

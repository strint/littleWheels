/*猜数字*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void matchNumber(int, int);
void start(void);//函数原型

main()
{
    printf("Here is a number between 1 and 1000.\n");
    printf("Can you guss my number?\n");
    
    start();//调用开始函数
}

/*产生随机数*/
void start(void)
{   
	int num,count;//随机数,次数

	srand(time(NULL));//产生随机数

	num=rand()%1000 + 1;//限定范围
    
    printf("Please type your first guss.\n");

	count=1;

    matchNumber(num,count);//调用判断函数
	
}

/*判断是否match*/
void matchNumber(int num,int count)
{
	int guss_num;
	char ch;

    scanf("%d",&guss_num);
        
	    //猜对
		if(guss_num==num)
		{
			if(count<10)     //不到10次
			{
				printf("Excellent!You guss it! \n ");
				printf("Either you know the secret or you got lucky!\n");

            }
			else
			{
				if(count==10)//10次
				{
					printf("Ahah!You know the secret!\n");
					printf("You guss the number!\n");
				}
				else        //超过10次
				{
					printf("You guss the number!\n");
					printf("You should be able to do better.\n");
				}
			}
			    //重新开始游戏？
                printf("Do you want to try again?(y/n)");

				getchar();//中断函数
				scanf("%c",&ch);
				
                if(ch=='y')
				{
                   start();//回到start()
				}
				
		}
		//猜错
		else
		{
			if(guss_num<num)//偏小
			{
				printf("Too low .Try again.\n");
				
				
			}
			else            //偏大
			{
				printf("Too high .Try again.\n");
			}
			
			count=count++;//计次数
			num=num;

			matchNumber(num,count);//返回match再猜一次
			
			
			
		}
		
	
}


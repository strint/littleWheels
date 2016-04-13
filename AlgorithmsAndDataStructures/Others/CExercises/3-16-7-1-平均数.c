#include<stdio.h>
#include<stdlib.h> 
main()
{
    #define num 5
    
    float score[num],a=0;
	int i;
	
    printf("please input 5 score:\n ");

	for(i=0;i<=num-1;i++)
	{
        printf("\ninput one score:\n ");
		scanf("%f,",&score[i]);
	}
	for(i=0;i<=num-1;i++)
	{
        a=a+score[i];
    }                 
	
    printf("the everage score is:%f",a/5);
	
    system("pause");
}
     


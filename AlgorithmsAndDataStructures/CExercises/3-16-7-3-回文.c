/*判断是否是回文字符串*/
#include<stdio.h>
#include<stdlib.h>
int main() 
{
    int i=0,j,k=0;
    char string[20];
    
    printf("请输入字符串:\n");
    gets(string);
    /*字符个数统计*/ 
    while(string[i]!='\0')
    {
                          i++; 
    }
    /*判断是否对称*/ 
    for(j=0;j<=(i-1)/2;j++)
    {
                           if(string[j]!=string[i-1-j])
                           {
                                                       k++;
                           }
    }
    /*打印结果*/ 
    if(k==0)
    {
            printf("\n是回文字符串。");
    }
    else
    {
            printf("\n不是回文字符串。");
    }
         
    system("pause");
    return 0;
}
































 

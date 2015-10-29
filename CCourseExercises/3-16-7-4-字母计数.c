/*字母计数*/
#include<stdio.h>
#include<stdlib.h>
void tongji(char [],int);
void printResult(char,int);//函数原型 

int main()
{
    char str[51]; 
    int i=0;
    
    printf("输入字符串（以“#”结束）：\n");
    gets(str);
    
    while(str[i]!='#')
    {
               if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')//除去字母外字符 
               {
                 tongji(str,i);//计数 
               }
               i++;
    }
    
    printf("\n");
    system("pause");
    return 0;
}
/*计数函数*/        
void tongji(char str[],int i)
{
     int k=i+1,j=1;
     char ch;
     
     while(str[k]!='#')
    {
                       if(str[k]==str[i])
                       {
                                          j++;
                                          str[k]='0';
                       }
                       k++;
    }
    ch=str[i];
    printResult(ch,j);//打印 
}
/*打印*/ 
void printResult(char ch,int j)
{
           printf("\n%d个%c",j,ch);
} 
                        
                       
                      
               
               
                                                                           
    
     
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

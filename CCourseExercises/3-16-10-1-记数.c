/*指针计数*/
#include<stdio.h>
#include<stdlib.h>
void Statistics(char *str,int*lcount,int*ncount,int*scount,int*ocount);//函数原型 

main()
{
      char string[50];
      int l=0,n=0,s=0,o=0;
      
      printf("enter a string:\n");
      gets(string);
      
      printf("String:\n%s \n",string);
      
      Statistics(string,&l,&n,&s,&o);//传递地址 
      
      printf("Letter:%d\nNumber:%d\nSpace:%d\nOthers:%d\n",l,n,s,o);//打印结果 
      
      system("pause");
      
      return 0;
}

void Statistics(char *str,int*lcount,int*ncount,int*scount,int*ocount)
{
     int i=0;
     
     while(str[i]!='\0')//循环判断计数 
     {
                        if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
                          (*lcount)++;//注意括号 
                           else if(str[i]>='0'&&str[i]<='9')
                                (*ncount)++;
                                else if(str[i]==' ')
                                       (*scount)++;
                                       else
                                       (*ocount)++;
                                       
                        i++;
     }
}

























      

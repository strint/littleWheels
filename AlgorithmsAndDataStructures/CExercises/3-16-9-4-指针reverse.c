/*×Ö·û´®reverse*/ 
#include<stdio.h>
#include<stdlib.h>

 void reverse(char *);

int main()
{
      char string[100];
      
      printf("ÇëÊäÈë×Ö·û´®£º\n"); 
      gets(string);
      
      printf("µ¹ÖÃºóµÄ×Ö·û´®£º\n");
      reverse(string);
      
      system("pause");
      return 0;
}

void reverse(char *str) //µİ¹é´òÓ¡ 
{
     if(str[0]=='\0')
       return;
     else
     {
         reverse(&str[1]);
         putchar(str[0]);
     } 
}  

#include<stdio.h>
#include<stdlib.h>

int main()
{
    char sentence[100],longest[20];
    int L=0,l=0,j=0,i=0,n,end,I=0;
    
    printf("inpute the string ('#'to end)");
    gets(sentence);
    
    while(sentence[i]!='#')
    {
                           while(sentence[i]!=' ')
                           {
                                                l++;
                                                i++;
                           }
                           
                           if(L<l)
                           {
                                  L=l;
                                  end=i-1;
                           }
                           
                           i++;
                           l=0;
    }
    
    for(n=end-L;n<=end;n++)
    {
                         longest[I]=sentence[n];
                         I++;
    }
    printf("%s",longest);
    //puts(longest);
    
    system("pause");
    return 0;
}
                         
                                               
                                                 
                           

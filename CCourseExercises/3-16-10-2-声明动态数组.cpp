#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 

char **inputName(int);
void sort(char**,int);
void printName(char **,int);
void Free(char **,int);

int main()
{
    int size,i;
    char **p; 
   
    printf("请输入要排序的人数：\n");
    scanf("%d",&size);
    printf("请输入%d个学生的姓名，每输入一个以回车键结束:\n",size); 
    p=inputName(size);
    
    sort(p,size);
    
    printName(p,size);
    
    Free(p,size);
    p=NULL;
     
    system("pause");
    return 0;
}     
                                     
char **inputName(int size)
{
     int i,j;
     char **aptr;
     char str[100];
     
     aptr=(char**)malloc(sizeof(char *)*size);
     for(i=0;i<=size-1;i++)
     {
           scanf("%s",str);    
           aptr[i]=(char*)malloc(sizeof(char)*strlen(str)); 
           for (j=0;j<=strlen(str)-1;j++)
           {
               aptr[i][j]=str[j];
           }
     }
     return aptr;
}

void sort(char**array,int size)
{
     int i,j,min;
     char *temptr;
     for (i=0;i<=size-2;i++)
     {
         min=i;
         for (j=min+1;j<=size-1;j++)
             if (strcmp(array[min],array[j])>0)
                 min=j;
         if (min!=i)
         {
              temptr=array[min];
              array[min]=array[i];
              array[i]=temptr;      
         }               
     }   
} 

void printName(char **array,int size)
{
     int i;
     printf("从小到大，这%d个学生的姓名为:\n",size);
     for (i=0;i<=size-1;i++)
        printf("%s\n",array[i]);
}
void Free(char **array,int size)
{
     int i;
     for (i=0;i<=size-1;i++)
     {
         free(array[i]);
         array[i]=NULL;
     }
     free(array);
}


















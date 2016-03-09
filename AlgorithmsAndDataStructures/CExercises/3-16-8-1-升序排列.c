#include<stdio.h>
#include<stdlib.h>
int findPosition(int[],int,int,int);
int insertElement(int[],int,int,int,int);
 

int main()
{
    #define arraysize 5
    int array[arraysize]={0};
    int i,elementsize=1,position,j,element;
    
    printf("请输入5个整数：\n");
    scanf("%d",&array[0]);
    
    for(i=0;i<arraysize;i++)
    {
                            scanf("%d",&element);
                            position=findPosition(array,arraysize,elementsize,element);
                             
                            j=insertElement(array,arraysize,elementsize,position,element);
                            //加[]有问题
                            elementsize++;
                            
                            if(j==1)
                            {
                                    printf("\n成功插入\n");
                            }
                            
                            if(elementsize==5)
                            {
                                    printf("\n成功插入\n");
                            }   
    }
    for(i=0;i<arraysize;i++)
    {
                            printf("%d\t",array[i]);
    }
}

int findPosition(int data[],int arraysize,int elementsize,int element)
{
    int k=0;
    
    if(element>data[elementsize-1])
     {
                                     return elementsize;
     }
        while(element>data[k])
        {
                               k++;
        }
        return k;
}
  
int insertElement(int data[],int arraysize,int elementsize,int position,int element);        
{
    int l;
    
    if(position==elementsize)
    {
                      data[position]=element;
    }
    else
    {
        for(l=element-1;l>=position;l--)
        {
                                        data[l+1]=data[l];
        }
    data[position]=element;
    return 1;
}
                                











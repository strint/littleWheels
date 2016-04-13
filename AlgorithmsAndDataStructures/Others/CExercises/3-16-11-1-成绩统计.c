/*成绩统计*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct inf* Getinput();//创建并将学生信息存放到链表
void Getcount(int [],struct inf*);//统计各分数段人数
void Getprint(int []);//输出统计结果
void Getfree(struct inf*);//释放链表

struct inf{
	char *name;
	int number;
	float grade;
	struct inf *nextptr;
};//存放学生信息结构
main()
{
	int shu[5]={0};//存放各分数段的人数
    struct inf *headptr;//链表的头结点
	
	printf("请依次输入学生的姓名，学号，成绩:\n");
    headptr=Getinput();//创建并将学生信息存放到链表，然后输出链表的头结点
	Getcount(shu,headptr);//统计各分数段人数
	Getprint(shu);//输出统计结果
	Getfree(headptr);//读入姓名
}
struct inf* Getinput()//创建并将学生信息存放到链表，然后输出链表的头结点
{
    int i,j,num;//学号
	char str[20]={0};//暂时存放学生的姓名
	struct inf *headptr=NULL,*countptr=NULL,*lastptr=NULL;
    float gra;//成绩    
    scanf("%s",str);//将姓名读入数组str中
	for (i=0;str[0]!='#';i++)//创建链表
	{
		
		countptr=(struct inf*)malloc(sizeof(struct inf));//为每一个结点申请内存空间
		if(countptr!=NULL)
		{
			countptr->name=(char *)malloc(sizeof(strlen(str)));//为姓名申请内存空间
			for (j=0;j<=strlen(str)-1;j++)//将数组str中的名字传给countptr->name
                (countptr->name)[j]=str[j];
			scanf("%d",&num);//读入学号
            countptr->number=num;
			scanf("%f",&gra);//读入分数
            countptr->grade=gra;  
		}
		if (headptr==NULL)
		{
			headptr=countptr;
			lastptr=countptr;
		}
		else
		{
			lastptr->nextptr=countptr;
			lastptr=countptr;
		}
        scanf("%s",str);
	}
    lastptr->nextptr=NULL;
	return headptr;
}
/*统计各分数段人数*/
void Getcount(int shu[],struct inf*headptr)
{
	struct inf*countptr;
    countptr=headptr;
	
	while (countptr!=NULL)
	{
		if (countptr->grade<60.0)
			shu[0]++;
		else
		{
			if ((countptr->grade>=60.0)&&(countptr->grade<70.0))
				shu[1]++;
			else{
				if ((countptr->grade>=70.0)&&(countptr->grade<80.0))
                    shu[2]++;
				else{
					if ((countptr->grade>=80.0)&&(countptr->grade<90.0))
						shu[3]++;
					else
						shu[4]++;
				}
			}
		}
		countptr=countptr->nextptr;//到下一个结点
	}//按照每个分数所处的分数段，增加相应分数段
}
/*输出统计结果*/
void Getprint(int shu[])
{
	int i;
	printf("%d以下的学生人数:%d\n",60,shu[0]);
	for (i=0;i<=2;i++)
	{
		printf("%d到%d之间的人数:%d\n",60+i*10,60+(i+1)*10,shu[i+1]);
	}
	printf("%d以上的人数:%d\n",90,shu[4]);
}
/*释放链表*/
void Getfree(struct inf*headptr)
{
    struct inf* countptr;
	while (headptr!=NULL)
	{
	    countptr=headptr;
	    headptr=headptr->nextptr;
	    free(countptr->name);//先释放为姓名申请的内存空间
        countptr->name=NULL;
	    free(countptr);//释放为结点申请的内存空间
	}
}

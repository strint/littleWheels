/*万年历（公元后）*/

#include<stdio.h>
#include<stdio.h>
int GetWeekDay (int,int,int);//该月第一天星期几
int GetMonthDay (int,int,int);//该月有多少天
void PrintMonthCalender (int,int);//打印日历
int CheckLeap (int);//是否是闰年


main()
{
	int year,month,startDay,days,yes_no;//年，月，该月第一天星期几，该月有多少天，是否是闰年

	printf("input the year and month<YYYY-MM>:");
	scanf("%d-%d",&year,&month);
	printf("                     %d年-%d月\n",year,month);//打印标题YYYY-MM

    /*调用函数*/
	yes_no=CheckLeap ( year);
	startDay=GetWeekDay (year,month,yes_no);
	days=GetMonthDay (year,month,yes_no);//值传递和处理

	PrintMonthCalender (startDay,days);
    
    system("pause");
	return 0;
}

/*函数 是否是闰年*/
int CheckLeap (int year)
{
	if((year%4==0&&year%100!=0)||year%400==0)
		return 1;
	else
		return 0;
}

/*该月第一天星期几*/
int GetWeekDay (int year,int month,int yes_no)
{
	int day,days1,days2;
	switch(month)//用switch处理不规则，有限的数据
	{
		  case 1:
			  days1=0;
			  break;
          case 2:
			  days1=31;
			  break;
		  case 3:
			  days1=59;
			  break;
		  case 4:
			  days1=90;
			  break;
		  case 5:
              days1=120;
			  break;
          case 6:
			  days1=151;
			  break;
          case 7:
			  days1=181;
			  break;
		  case 8:
			  days1=212;
			  break;
		  case 9:
			  days1=243;
			  break;
		  case 10:
              days1=273;
			  break;
          case 11:
			  days1=304;
			  break;
		  case 12:
              days1=334;
			  break;
	}
	if(yes_no==1&&month>2)//是否是闰年
	{
		days1=days1+1;
	}
	days2=(year-1)*365 + (year-1)/400 + (year-1)/4 - (year-1)/100 + days1 + 1; 
	day=days2%7;
	return day;
}

/*该月有多少天*/
int GetMonthDay (int year,int month,int yes_no)
{
	int days3;
	switch(month)//用switch处理不规则，有限的数据
	{
		  case 1:
			  days3=31;
			  break;
          case 2:
			  days3=28;
			  break;
		  case 3:
			  days3=31;
			  break;
		  case 4:
			  days3=30;
			  break;
		  case 5:
              days3=31;
			  break;
          case 6:
			  days3=30;
			  break;
          case 7:
			  days3=31;
			  break;
		  case 8:
			  days3=31;
			  break;
		  case 9:
			  days3=30;
			  break;
		  case 10:
              days3=31;
			  break;
          case 11:
			  days3=30;
			  break;
		  case 12:
              days3=31;
			  break;
	}
	if(yes_no==1&&month==2)//是否是闰年
	{
		days3=days3+1;
	}
	return days3;
}

/*打印日历*/
void PrintMonthCalender (int startDay,int days)
{
	int n1,n2;

    printf("Sun.    Mon.    Tue.    Wed.    Thu.    Fri.    Sat.    \n");//8位制表

	for(n1=1;n1<=startDay;n1++)//开头打空格
	{
		printf(" \t");
	}
	for(n2=1;n2<=days;n2++)//打日期
	{
		if((n2+startDay)%7==0)
		{
			printf("%d\n",n2);//星期日后换行
		}
		else
		{
			printf("%d\t",n2);
		}
	}
}
/*
1、函数的值传递---结构，顺序
2、制表---8位
3、switch---处理不规则，有限的数据
4、N-S图
5、注释
6、格式
*/

	




	
	



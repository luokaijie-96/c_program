#include <stdio.h>
#include <stdlib.h>
int week(int year, int month); // 返回当前月份的第一天是星期几
int days(int year, int month); // 返回当前月有几天
int isLeap(int year); //判断是不是闰年
int preMonthDaysFunc(int year, int month); //获取上一个月的天数

int main()
{
    int arr[42];
    int year;
    int month;
    printf("请输入年份和月份:");
    scanf("%d%d", &year , &month);
    printf("                          \n");

    //当月有多少天
    int monthDays = days(year, month);

    //当前月的第一天是星期几
    int weekDays = week(year, month);

    printf("  %d年%d月\n", year ,month);
    printf("                          \n");
    printf("  日  一  二  三  四  五  六\n");
    printf("                          \n");

    int preMonthDays = preMonthDaysFunc(year, month);

    //存入上月的数据
    for(int x=0;x<weekDays;x++)
    {
        arr[x] = preMonthDays - (weekDays - x - 1);
    }

    //存入当月的数据
    for(int y=0;y<monthDays;y++)
    {
        arr[weekDays+y] = y + 1;
    }

    //存入下月的暑假
    int count = weekDays + monthDays;
    for(int z=0;z<(42-count);z++)
    {
        arr[count+z] = z + 1;
    }


    for(int s=0;s<42;s++)
    {
        printf("%4d",arr[s]);
        if(s % 7 == 6)
        {
            printf("\n");
            printf("                          \n");
        }

    }

    system("pause");
    return 0;
}

int week(int year,int month)
{
    int sum = 0;
    for(int i=1970;i<year;i++)
    {
        int yDay = 0;
        for(int j=1;j<13;j++)
        {
            yDay += days(i, j);
        }

        sum += yDay;
    }

    for(int z=1;z<month;z++)
    {
        sum += days(year, z);
    }

    //1970年1月1日 是星期四
    return (sum + 4) % 7;
}


int days(int year, int month)
{
     // 返回当前月的天数
     // 1,3,5,7,8,10,12 ---- 31
     // 4, 6, 9, 11 ------30
     // 2 ---- 闰年有29天，平年有28天

    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            // 闰年判断 能被4整除并且不能被100整除或者能被400整除的就是闰年
            if(!isLeap(year))
            {
                return 28;
            }
            else
            {
                return 29;
            }

    }

}


int isLeap(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 ==0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int preMonthDaysFunc(int year, int month)
{
    if(month == 1)
    {
        year--;
        month = 12;
    }
    else
    {
        month--;
    }

    return days(year, month);
}



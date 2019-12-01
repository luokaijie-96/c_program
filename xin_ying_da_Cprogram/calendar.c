#include <stdio.h>
#include <stdlib.h>
int week(int year, int month); // ���ص�ǰ�·ݵĵ�һ�������ڼ�
int days(int year, int month); // ���ص�ǰ���м���
int isLeap(int year); //�ж��ǲ�������
int preMonthDaysFunc(int year, int month); //��ȡ��һ���µ�����

int main()
{
    int arr[42];
    int year;
    int month;
    printf("��������ݺ��·�:");
    scanf("%d%d", &year , &month);
    printf("                          \n");

    //�����ж�����
    int monthDays = days(year, month);

    //��ǰ�µĵ�һ�������ڼ�
    int weekDays = week(year, month);

    printf("  %d��%d��\n", year ,month);
    printf("                          \n");
    printf("  ��  һ  ��  ��  ��  ��  ��\n");
    printf("                          \n");

    int preMonthDays = preMonthDaysFunc(year, month);

    //�������µ�����
    for(int x=0;x<weekDays;x++)
    {
        arr[x] = preMonthDays - (weekDays - x - 1);
    }

    //���뵱�µ�����
    for(int y=0;y<monthDays;y++)
    {
        arr[weekDays+y] = y + 1;
    }

    //�������µ����
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

    //1970��1��1�� ��������
    return (sum + 4) % 7;
}


int days(int year, int month)
{
     // ���ص�ǰ�µ�����
     // 1,3,5,7,8,10,12 ---- 31
     // 4, 6, 9, 11 ------30
     // 2 ---- ������29�죬ƽ����28��

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
            // �����ж� �ܱ�4�������Ҳ��ܱ�100���������ܱ�400�����ľ�������
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



#include "mystring.h"


/*���ַ�������*/
unsigned int mystrlen(char char_buff[])
{
	unsigned int length = 0;
	
	for(length = 0; char_buff[length] != '\0'; length++)
	{
		;
	}
	
	return length;
}



/*�ַ�����С�Ƚ�*/
int mystrcmp(char char_buff1[], char char_buff2[])
{
	unsigned int length = 0;
	
	for(length = 0; char_buff1[length] != '\0' || char_buff2[length] != '\0'; length++)
	{
		if(char_buff1[length] > char_buff2[length])
		{
			return 1;
		}
		else if(char_buff1[length] < char_buff2[length])
		{
			return -1;
		}
	}
	
	return 0;
}


/*�ַ�������*/
int mystrcpy(char char_buff1[], char char_buff2[])
{
	unsigned int length = 0;
	
	for(length = 0; char_buff2[length] != '\0'; length++)
	{
		char_buff1[length] = char_buff2[length];
	}
	char_buff1[length] = char_buff2[length];//����������
	
	return length;
}


/*�ַ���ƴ��*/
int mystrcat(char char_buff1[], char char_buff2[])
{
	unsigned int length1 = 0, length2 = 0;
	
	for(length1 = 0; char_buff1[length1] != '\0'; length1++)
	{
		
	}
	
	for(length2 = 0; char_buff2[length2] != '\0'; length2++)
	{
		char_buff1[length1] = char_buff2[length2];
		length1++;
	}
	char_buff1[length1] = char_buff2[length2];//������
	
	return length1;
}







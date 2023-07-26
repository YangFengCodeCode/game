#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include"Contact.h"
void menu()
{
	printf("***************************\n");
	printf("*****1. add      2.del*****\n");
	printf("*****3. search   4. modify*\n");
	printf("*****5. show     6. sort***\n");
	printf("*****0. exit     **********\n");
	printf("***************************\n");
}
void test()
{
	int input = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		defaut:
			printf("选择错误，重新选择\n");
			break;

		}
	} while (input);

}
int main()
{
	test();
	return 0;
}
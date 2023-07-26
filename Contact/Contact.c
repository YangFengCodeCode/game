#define _CRT_SECURE_NO_WARNINGS 

#include"Contact.h"

void InitContact(Contact* pc)
{
	memset(pc->data, 0, sizeof(pc->data));
	pc->sz = 0;
}


void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入名字\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄\n");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话\n");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址\n");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("成功增加联系人");
}

void ShowContact(const Contact* pc)
{
	int i = 0;
	//打印列标题
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	//打印数据
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n", 
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr
			);
	}
}


 static int FindByName(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DelContact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录已空，无法删除\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	assert(pc);
	//删除
	printf("请输入要删除的人名字\n");
	scanf("%s", name);
	////找到要删除的人
	//int i = 0;
	//int del = 0;
	//int flag = 0;
	//for (i = 0; i < pc->sz; i++)
	//{
	//	if (strcmp(pc->data[i].name, name) == 0)
	//	{
	//		del = i;
	//		flag = 1;
	//		break;
	//	}
	//}
	//if (flag == 0)
	//{
	//	printf("要删除的人不存在\n");
	//	return;
	//}
	int del = FindByName(pc, name);
	if (del == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//删除下标为del的联系人
	int i = 0;
	for (i = del; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("成功删除联系人\n");
}



void SearchContact(const Contact* pc)
{
	assert(pc);

	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
		//打印数据
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}



void ModifyContact(Contact* pc)
{
	assert(pc);

	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("请输入名字\n");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄\n");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入性别\n");
		scanf("%s", pc->data[pos].sex);
		printf("请输入电话\n");
		scanf("%s", pc->data[pos].tele);
		printf("请输入地址\n");
		scanf("%s", pc->data[pos].addr);
		printf("修改成功\n");
	}
}
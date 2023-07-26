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
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	printf("����������\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������\n");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰\n");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ\n");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("�ɹ�������ϵ��");
}

void ShowContact(const Contact* pc)
{
	int i = 0;
	//��ӡ�б���
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	//��ӡ����
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
		printf("ͨѶ¼�ѿգ��޷�ɾ��\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	assert(pc);
	//ɾ��
	printf("������Ҫɾ����������\n");
	scanf("%s", name);
	////�ҵ�Ҫɾ������
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
	//	printf("Ҫɾ�����˲�����\n");
	//	return;
	//}
	int del = FindByName(pc, name);
	if (del == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//ɾ���±�Ϊdel����ϵ��
	int i = 0;
	for (i = del; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("�ɹ�ɾ����ϵ��\n");
}



void SearchContact(const Contact* pc)
{
	assert(pc);

	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		//��ӡ����
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
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("����������\n");
		scanf("%s", pc->data[pos].name);
		printf("����������\n");
		scanf("%d", &(pc->data[pos].age));
		printf("�������Ա�\n");
		scanf("%s", pc->data[pos].sex);
		printf("������绰\n");
		scanf("%s", pc->data[pos].tele);
		printf("�������ַ\n");
		scanf("%s", pc->data[pos].addr);
		printf("�޸ĳɹ�\n");
	}
}
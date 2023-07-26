#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#include<string.h>
#include<stdio.h>
enum OPTION
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
//类型的声明

typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
} PeoInfo;


//通讯录

typedef struct Contact
{
	PeoInfo data[MAX];
	int sz;
}Contact;

//函数声明

//初始化通讯录
void InitContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//显示所有联系人的信息
void ShowContact(const Contact* pc);

//删除指定联系人
void DelContact(Contact* pc);

//查找联系人
void SearchContact(const Contact* pc);

//修改指定联系人
void ModifyContact(Contact* pc);
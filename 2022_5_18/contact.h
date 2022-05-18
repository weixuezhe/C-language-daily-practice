#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//#define MAX 101
#define Cap 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDER 30

enum Potion {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
};

struct people {
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char adder[MAX_ADDER];
};

struct cont {
	
	int capacity;
	int size;
	struct people* data;
};
//初始化通讯录数据
void InitContact(struct cont* ps);
//添加通讯录数据
void AddContact(struct cont* ps);
//删除通讯录数据
void DelContact(struct cont* ps);
//显示通讯录信息
void ShowContact(struct cont* ps);
//查找指定人的信息
void SearchContact(struct cont* ps);
//修改联系人的信息
void ModifyContact(struct cont* ps);
//对通讯录数据排序
void SortContact(struct cont* pa);
//保存通讯录数据到本地文件
void SaveContact(struct cont* ps);
//加载通讯录文件中的信息到程序
void LoadContact(struct cont* ps);
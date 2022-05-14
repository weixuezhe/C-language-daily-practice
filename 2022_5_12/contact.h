#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

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
	struct people data[MAX];
	int size;
};
//��ʼ��ͨѶ¼����
void InitContact(struct cont* ps);
//���ͨѶ¼����
void AddContact(struct cont* ps);
//ɾ��ͨѶ¼����
void DelContact(struct cont* ps);
//��ʾͨѶ¼��Ϣ
void ShowContact(struct cont* ps);
//����ָ���˵���Ϣ
void SearchContact(struct cont* ps);
//�޸���ϵ�˵���Ϣ
void ModifyContact(struct cont* ps);
//��ͨѶ¼��������
void SortContact(struct cont* pa);
#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//初始化通讯录数据
void InitContact(struct cont* ps) {
	ps->data = (struct cont*)malloc(Cap * sizeof(struct people));
	if (ps == NULL) {
		return;
	}
	ps->capacity = 3;
	ps->size = 0;
}
//查找函数
int FindByName(struct cont* dest, char* src) {
	int i = 0;
	for (i = 0; i < dest->size; i++) {
		if (0 == strcmp(dest->data[i].name, src)) {
			return i;
		}
	}
	return -1;
}
//扩容函数
void AddCapacity(struct cont* ps) {
	struct cont* one;
	one = realloc(ps->data, (ps->size+2) * sizeof(struct people));
	if (one != NULL) {
		ps->data = one;
		ps->capacity += 2;
		printf("扩容成功\n");
	}
	else {
		printf("扩容失败\n");
		return;
	}
}
//添加通讯录信息
void AddContact(struct cont* ps) {
	if (ps->size == ps->capacity) {
		AddCapacity(ps);
	}
	printf("请输入姓名->");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄->");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别->");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话->");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址->");
	scanf("%s", ps->data[ps->size].adder);
	ps->size++;
	printf("添加成功\n");
	
	
	
}
//删除通讯录数据
void DelContact(struct cont* ps) {
	int i = 0;
	int j = 0;
	char input[MAX_NAME] = {0};
	if (ps->size == 0) {
		printf("当前没有数据\n");
	}
	else {
		printf("请输入要删除人的姓名->");
		scanf("%s", input);
		int ret = FindByName(ps,input);
		if (ret == -1) {
			printf("没有找到此人信息\n");
		}
		else {
			for (i = ret; i < ps->size; i++) {
				ps->data[ret] = ps->data[ret + 1];
			}
			printf("删除成功\n");
			ps->size--;
		}
	}
}
//显示通讯录信息
void ShowContact(struct cont* ps) {
	int i = 0;
	if (ps->size == 0) {
		printf("通讯录没有信息\n");
	}
	else {
		printf("%-8s%-5s%-5s%-15s%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++) {
			printf("%-8s%-5d%-5s%-15s%-30s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].adder
				);
		}
	}
}
//查找指定人的信息
void SearchContact(struct cont* ps) {
	if (ps->size == 0) {
		printf("通讯录没有信息\n");
	}
	else {
		char input[MAX_NAME];
		printf("请输入要查找人的姓名->");
		scanf("%s", input);
		int ret = FindByName(ps, input);
		if (ret == -1) {
			printf("没有找到此人信息\n");
		}
		else {
			printf("%-8s%-5s%-5s%-15s%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
			printf("%-8s%-5d%-5s%-15s%-30s\n",
				ps->data[ret].name,
				ps->data[ret].age,
				ps->data[ret].sex,
				ps->data[ret].tele,
				ps->data[ret].adder
			);
		}
	}
}
//修改联系人的信息
void ModifyContact(struct cont*ps) {
	if (ps->size == 0) {
		printf("通讯录没有数据\n");
	}
	else {
		char input[MAX_NAME];
		printf("请输入要修改人的姓名->");
		scanf("%s", input);
		int ret = FindByName(ps, input);
		if (ret == -1) {
			printf("没有找到此人信息\n");
		}
		else {
			printf("修改姓名->");
			scanf("%s", ps->data[ret].name);
			printf("修改年龄->");
			scanf("%d", &(ps->data[ret].age));
			printf("修改性别->");
			scanf("%s", ps->data[ret].sex);
			printf("修改电话->");
			scanf("%s", ps->data[ret].tele);
			printf("修改地址->");
			scanf("%s", ps->data[ret].adder);


			printf("%-8s%-5s%-5s%-15s%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
			printf("%-8s%-5d%-5s%-15s%-30s\n",
				ps->data[ret].name,
				ps->data[ret].age,
				ps->data[ret].sex,
				ps->data[ret].tele,
				ps->data[ret].adder
			);
			printf("修改成功\n");
		}
	}
	
}
//对通讯录数据排序
void SortContact(struct cont* ps) {
	int i = 0;
	int j = 0;
	struct people tmp = {"zhangsan",20,"nan","222222","guangzhou"};
	for (i = 0; i < ps->size-1; i++) {
		for (j = 0; j < ps->size - i - 1; j++) {
			if (ps->data[j].age > ps->data[j + 1].age) {
				tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
			}
		}
	}
	printf("排序成功\n");
}
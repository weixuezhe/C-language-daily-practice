#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//��ʼ��ͨѶ¼����
void InitContact(struct cont* ps) {
	ps->data = (struct cont*)malloc(Cap * sizeof(struct people));
	if (ps == NULL) {
		return;
	}
	ps->capacity = 3;
	ps->size = 0;
	LoadContact(ps);
}
//���ݺ�������
void AddCapacity(struct cont* ps);
//����ͨѶ¼�ļ��е���Ϣ������
void LoadContact(struct cont* ps) {
	struct people tmp = { 0 };
	FILE* pfread = fopen("contact.txt", "rb");
	if (pfread == NULL) {
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(struct people), 1, pfread)) {
		AddCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}
	fclose(pfread);
	pfread == NULL;
}
//���Һ���
int FindByName(struct cont* dest, char* src) {
	int i = 0;
	for (i = 0; i < dest->size; i++) {
		if (0 == strcmp(dest->data[i].name, src)) {
			return i;
		}
	}
	return -1;
}
//���ݺ���
void AddCapacity(struct cont* ps) {
	if (ps->size == ps->capacity) {
		struct cont* one;
		one = realloc(ps->data, (ps->size + 2) * sizeof(struct people));
		if (one != NULL) {
			ps->data = one;
			ps->capacity += 2;
		}
		else {
			printf("����ʧ��\n");
			return;
		}
	}
	else {
		return;
	}
}
//���ͨѶ¼��Ϣ
void AddContact(struct cont* ps) {
	AddCapacity(ps);
	printf("����������->");
	scanf("%s", ps->data[ps->size].name);
	printf("����������->");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�->");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰->");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ->");
	scanf("%s", ps->data[ps->size].adder);
	ps->size++;
	printf("��ӳɹ�\n");
	
	
	
}
//ɾ��ͨѶ¼����
void DelContact(struct cont* ps) {
	int i = 0;
	int j = 0;
	char input[MAX_NAME] = {0};
	if (ps->size == 0) {
		printf("��ǰû������\n");
	}
	else {
		printf("������Ҫɾ���˵�����->");
		scanf("%s", input);
		int ret = FindByName(ps,input);
		if (ret == -1) {
			printf("û���ҵ�������Ϣ\n");
		}
		else {
			for (i = ret; i < ps->size; i++) {
				ps->data[ret] = ps->data[ret + 1];
			}
			printf("ɾ���ɹ�\n");
			ps->size--;
		}
	}
}
//��ʾͨѶ¼��Ϣ
void ShowContact(struct cont* ps) {
	int i = 0;
	if (ps->size == 0) {
		printf("ͨѶ¼û����Ϣ\n");
	}
	else {
		printf("%-8s%-5s%-5s%-15s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
//����ָ���˵���Ϣ
void SearchContact(struct cont* ps) {
	if (ps->size == 0) {
		printf("ͨѶ¼û����Ϣ\n");
	}
	else {
		char input[MAX_NAME];
		printf("������Ҫ�����˵�����->");
		scanf("%s", input);
		int ret = FindByName(ps, input);
		if (ret == -1) {
			printf("û���ҵ�������Ϣ\n");
		}
		else {
			printf("%-8s%-5s%-5s%-15s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
//�޸���ϵ�˵���Ϣ
void ModifyContact(struct cont*ps) {
	if (ps->size == 0) {
		printf("ͨѶ¼û������\n");
	}
	else {
		char input[MAX_NAME];
		printf("������Ҫ�޸��˵�����->");
		scanf("%s", input);
		int ret = FindByName(ps, input);
		if (ret == -1) {
			printf("û���ҵ�������Ϣ\n");
		}
		else {
			printf("�޸�����->");
			scanf("%s", ps->data[ret].name);
			printf("�޸�����->");
			scanf("%d", &(ps->data[ret].age));
			printf("�޸��Ա�->");
			scanf("%s", ps->data[ret].sex);
			printf("�޸ĵ绰->");
			scanf("%s", ps->data[ret].tele);
			printf("�޸ĵ�ַ->");
			scanf("%s", ps->data[ret].adder);


			printf("%-8s%-5s%-5s%-15s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
			printf("%-8s%-5d%-5s%-15s%-30s\n",
				ps->data[ret].name,
				ps->data[ret].age,
				ps->data[ret].sex,
				ps->data[ret].tele,
				ps->data[ret].adder
			);
			printf("�޸ĳɹ�\n");
		}
	}
	
}
//��ͨѶ¼��������
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
	printf("����ɹ�\n");
}
//����ͨѶ¼���ݵ������ļ�
void SaveContact(struct cont* ps) {
	FILE* pfwrite = fopen("contact.txt", "wb");
	if (pfwrite == NULL) {
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		fwrite(&ps->data[i], sizeof(struct people), 1, pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
}

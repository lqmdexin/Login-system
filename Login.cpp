#define use_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account
{
	char id[20];
	char password[20];
};
int main()
{
	int n;
	struct account Account;
	printf("�������˺ź����룺\n");
	scanf_s("%s", Account.id,20);
	scanf_s("%s", Account.password,20);
	if (strcmp(Account.id, "admin") == 0 && strcmp(Account.password, "123456") == 0)
	{
		printf("��¼�ɹ���\n");
	}
	else
	{
		printf("�˺Ż��������\n");
	}

	return 0;
}
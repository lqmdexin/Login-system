#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account
{
	char id[20];
	char password[20];
};
//这是一个优化点，其实数组可以改为动态数组
int main()
{
	printf("此处为菜单界面\n");
	printf("欢迎使用登录系统！\n");
	printf("在这里你可以选择1.注册 2.登录\n");
	int choice;
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:
	{
		struct account Account;
		printf("请输入注册的账号和密码：\n");
		scanf_s("%s", Account.id, 20);
		scanf_s("%s", Account.password, 20);
		FILE* fp;
		if (fopen_s(&fp, "account.txt", "a+") != 0)
		{
			printf("文件打开失败！\n");
			break;
		}
		
		fprintf_s(fp, "\n%s\n%s\n", Account.id, Account.password);
		//原先用的fputs函数，但是无法将字符串换行，所以改成fprintf_s函数
		//fputs(Account.id, fp);
		//fputs(Account.password, fp);
		fclose(fp);
		printf("注册成功！\n");
		break;
	}
	
	case 2:
	{

		char input_id[20], input_pwd[20];
		struct account Account;
		printf("请输入账号和密码：\n");
		scanf_s("%s", input_id, 20);
		scanf_s("%s", input_pwd, 20);
		FILE* fp;
		if (fopen_s(&fp, "account.txt", "r") != 0)
		{
			printf("文件打开失败！\n");
			break;
		}
		char file_id[20], file_pwd[20];
		int login_success = 0;
		while (fscanf_s(fp, "%s\n%s\n", file_id, 20, file_pwd, 20) == 2) // 按行读取账号和密码
		{ 
			if (strcmp(input_id, file_id) == 0 && strcmp(input_pwd, file_pwd) == 0) 
			{
				login_success = 1;
				break; 
			}
		}
		fclose(fp);

		if (login_success) {
			printf("登录成功！\n");
		}
		else {
			printf("账号或密码错误！\n");
		}
		break;
		return 0;
	}
	default:
		printf("输入错误！\n");
		break;
	}
}

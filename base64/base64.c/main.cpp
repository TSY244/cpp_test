#define _CRT_SECURE_NO_WARNINGS 1



#include"lei.h"



extern char zidian[];
extern union base64;


void menu()
{
	cout << "************************" << endl;
	cout << "**********0.exit********" << endl;
	cout << "********1.文件解密******" << endl;
	cout << "********2.文件加密******" << endl;
	cout << "********3.线上解密******" << endl;
	cout << "********4.线上加密******" << endl;
	cout << "************************" << endl;
	cout << "请选择:";
}

void keybody()
{
	int a;//选择
	base64_jiema jiema;
	base64_bianma bianma;
	do
	{
		menu();
		scanf("%d",&a);
		switch (a)
		{
		case 0:
		{
			cout << "退出成功！" << endl;
			break;
		}
		case 1:
		{
			system("cls");
			jiema.jiema();
			break;
		}
		case 2:
		{
			system("cls");
			bianma.bianma();
			break;
		}
		case 3:
		{
			system("cls");
			bianma.x_bianma();
			break;
		}
		case 4:
		{
			system("cls");
			jiema.x_jiema();
			break;
		}
		default:
		{
			system("cls");
			cout << "输入错误,请重新输入:" << endl;
			break;
		}
		}
	} while (a);
}


int main()
{
	keybody();
	return 0;
}
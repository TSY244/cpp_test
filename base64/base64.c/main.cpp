#define _CRT_SECURE_NO_WARNINGS 1



#include"lei.h"



extern char zidian[];
extern union base64;


void menu()
{
	cout << "************************" << endl;
	cout << "**********0.exit********" << endl;
	cout << "********1.�ļ�����******" << endl;
	cout << "********2.�ļ�����******" << endl;
	cout << "********3.���Ͻ���******" << endl;
	cout << "********4.���ϼ���******" << endl;
	cout << "************************" << endl;
	cout << "��ѡ��:";
}

void keybody()
{
	int a;//ѡ��
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
			cout << "�˳��ɹ���" << endl;
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
			cout << "�������,����������:" << endl;
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
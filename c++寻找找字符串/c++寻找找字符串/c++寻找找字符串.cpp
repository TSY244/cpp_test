#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

int main()
{
	char arr[105][85] = { 0 };
	int i = 0, j = 0;//i�����жϸ�����j���ڴ�ӡ
	int a;
	cout << "�����뼸���ַ���\n" << endl;
	cin>>i;
	cout << "����������\n" << endl;
	for (j = 0; j < i; j++)
	{
		cin >> arr[j];
	}
	cout << "��������Ҫ���ҵ�����" << endl;
	cin>> arr[i + 1];
	for (a = 0; a < i; a++)
	{
		if (strcmp(arr[i + 1], arr[a]) == 0)
		{
			cout << a+1<<"\t" << arr[i + 1] << endl;
			break;
		}
	}
	if (a == i)
	{
		cout << "û���ҵ�" << endl;
	}

	return 0;
}
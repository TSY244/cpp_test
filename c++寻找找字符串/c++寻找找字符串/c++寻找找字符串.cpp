#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

int main()
{
	char arr[105][85] = { 0 };
	int i = 0, j = 0;//i用于判断个数，j用于打印
	int a;
	cout << "请输入几组字符串\n" << endl;
	cin>>i;
	cout << "请输入数组\n" << endl;
	for (j = 0; j < i; j++)
	{
		cin >> arr[j];
	}
	cout << "请输入需要查找的数组" << endl;
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
		cout << "没有找到" << endl;
	}

	return 0;
}
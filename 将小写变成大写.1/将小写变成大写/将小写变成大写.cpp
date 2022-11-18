#define _CRT_SECURE_NO_WARNINGS 1


#include<string>
#include<iostream>
using namespace std;

int main()
{
	char arr[10];
	int i;
	cin >> arr;
	for (i = 0; i < sizeof(arr); i++)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			arr[i] = arr[i] - 'a' + 'A';
		}
	}
	cout << arr << endl;
	return 0;
}
#include"lei.h"



//导入字典
char zidian[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
		'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X','Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
		'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u', 'v',
		'w', 'x', 'y', 'z', '0', '1', '2', '3','4', '5', '6', '7', '8', '9', '+', '/' };




//构建共用体，因为共用体利用位域可将3个字节，也就是24比特，不需要手动切割达到4组6bit
union base64
{
	struct//8位
	{
		unsigned int three_8 : 8;
		unsigned int  two_8 : 8;
		unsigned int  one_8 : 8;
	};
	struct//6位
	{
		unsigned int  four_6 : 6;
		unsigned int  three_6 : 6;
		unsigned int  two_6 : 6;
		unsigned int  one_6 : 6;
	};
};




/// <summary>
/// ////////////////////解码区
/// </summary>
/// 
/// //文件解码
void base64_jiema::jiema()
{
	union base64 temp = { 0 };//利用共用体切割
	string tem;//将文件里面的导入进tem
	string File_address;//保存文件地址
	fstream file;//文件操作
	vector<unsigned char> jie_ma;
	int n = 0;//1.用于等号处理2.用于vector导入文件
	cout << "请输入文件名：" << endl;
	cin >> File_address;//输入文件名
	file.open(File_address);//打开文件
	if (file.fail())//判断文件是否打开成功
	{
		cout << "文件打开失败" << endl;
		return;
	}
	file >> tem;//文件里的到入到tem
	file.close();//关闭文件

	//处理等号
	n = tem.length();
	if (tem[n - 2] == '=')
	{
		tem[n - 2] = 'A';
		tem[n - 1] = 'A';
	}
	else if (tem[n - 1] == '=')
	{
		tem[n - 1] = 'A';
	}

	//4的倍数
	while (tem.length() % 4 != 0)
	{
		tem.push_back('A');
	}

	for (int i = 0; i < tem.length(); i += 4)//将tem数据放进联合体切割
	{
		//将编码与字典一一对应
		int tem1 = find(tem[i]);
		int tem2 = find(tem[i+1]);
		int tem3 = find(tem[i+2]);
		int tem4 = find(tem[i+3]);

		//将char放进共用体，途中发生强制类型转变
		temp.one_6 = tem1;
		temp.two_6 = tem2;
		temp.three_6 = tem3;
		temp.four_6 = tem4;
		//切割
		jie_ma.push_back(temp.one_8);
		jie_ma.push_back(temp.two_8);
		jie_ma.push_back(temp.three_8);
	}
	//导入文件
	ofstream out_file;
	out_file.open("outfile.txt");
	vector<unsigned char>::iterator p = jie_ma.begin();
	n = 0;
	while (p < jie_ma.end())
	{
		out_file << jie_ma[n];
		n++;
		p++;
	}

	//关闭文件
	out_file.close();

}

//线上解码
void base64_jiema::x_jiema()
{
	union base64 temp = { 0 };//利用共用体切割
	string tem;//将编码存储于tem
	int n;
	vector<unsigned char> jie_ma;
	cout << "请输入解密的base64编码:";
	cin >> tem;
	//处理等号
	n = tem.length();
	if (tem[n - 2] == '=')
	{
		tem[n - 2] = 'A';
		tem[n - 1] = 'A';
	}
	else if (tem[n - 1] == '=')
	{
		tem[n - 1] = 'A';
	}
	//4的倍数
	while (tem.length() % 4 != 0)
	{
		tem.push_back('A');
	}

	for (int i = 0; i < tem.length(); i += 4)//将tem数据放进联合体切割
	{
		//将编码与字典一一对应
		int tem1 = find(tem[i]);
		int tem2 = find(tem[i + 1]);
		int tem3 = find(tem[i + 2]);
		int tem4 = find(tem[i + 3]);

		//将char放进共用体，途中发生强制类型转变
		temp.one_6 = tem1;
		temp.two_6 = tem2;
		temp.three_6 = tem3;
		temp.four_6 = tem4;
		//切割
		jie_ma.push_back(temp.one_8);
		jie_ma.push_back(temp.two_8);
		jie_ma.push_back(temp.three_8);
	}
	cout << "解密完成！" << endl << "解密后：";
	vector<unsigned char>::iterator p = jie_ma.begin();
	for (int i = 0; p < jie_ma.end(); i++, p++)
	{
		cout << jie_ma[i];
	}
	cout << endl;
	system("pause");
	system("cls");
}



int base64_jiema::find(char tem)
{
	int i = 0;
	while (tem != zidian[i])
	{
		i++;
	}
	return i;
}




/// <summary>
/// ////////////////////编码区
/// </summary>
/// 
/// 


void base64_bianma::bianma()
{
	union base64 temp = { 0 };//利用共用体切割
	string tem;//将文件里面的导入进tem
	string File_address;//保存文件地址
	fstream file;//文件操作
	vector<unsigned char> bian_ma;
	int n=0;//将vector放进文件
	int count = 0;
	cout << "请输入文件名："  << endl;
	cin >> File_address;//输入文件名
	file.open(File_address);//打开文件
	if (file.fail())//判断文件是否打开成功
	{
		cout << "文件打开失败" << endl;
		return;
	}
	file >> tem;//将文件内容导入到tem
	file.close();
	while ( tem.length() % 3 != 0)//补齐成3的倍数
	{
		tem.push_back(0);
		count++;
	}
	for (int i = 0; i < tem.length(); i += 3)
	{
		////将tem存储进入共用体
		temp.one_8 = tem.at(i);
		temp.two_8 = tem.at(i+1);
		temp.three_8 = tem.at(i + 2);
		//将共用体的取出来
		bian_ma.push_back(zidian[temp.one_6]);
		bian_ma.push_back(zidian[temp.two_6]);
		bian_ma.push_back(zidian[temp.three_6]);
		bian_ma.push_back(zidian[temp.four_6]);
	}



	//将0换成=
	n=bian_ma.size();

	if (count==2)
	{
		bian_ma[n - 2] = '=';
		bian_ma[n - 1] = '=';
	}
	else if (count==1)
	{
		bian_ma[n - 1] = '=';
	}
	
	//导入文件
	ofstream out_file;
	out_file.open("outfile.txt");
	vector<unsigned char>::iterator p = bian_ma.begin();
	n = 0;
	while (p < bian_ma.end())
	{
		out_file << bian_ma[n];
		n++;
		p++;
	}

	//关闭文件
	out_file.close();
}




void base64_bianma::x_bianma()
{
	union base64 temp = { 0 };//利用共用体切割
	string input = "0";
	vector<unsigned char> bian_ma;
	int n;
	int count=0;
	cout << "请输入需要解密的base64编码：";
	cin >> input;
	while (input.length() % 3 != 0)//补齐3位方便循环
	{
		input.push_back('0');
		count++;
	}
	for (int i = 0; i < input.length(); i+=3)
	{
		////将tem存储进入共用体
		temp.one_8 = input.at(i);
		temp.two_8 = input.at(i + 1);
		temp.three_8 = input.at(i + 2);
		//将共用体的取出来
		bian_ma.push_back(zidian[temp.one_6]);
		bian_ma.push_back(zidian[temp.two_6]);
		bian_ma.push_back(zidian[temp.three_6]);
		bian_ma.push_back(zidian[temp.four_6]);
	}

	//将0换成=
	n = bian_ma.size();

	if (count == 2)
	{
		bian_ma[n - 2] = '=';
		bian_ma[n - 1] = '=';
	}
	else if (count == 1)
	{
		bian_ma[n - 1] = '=';
	}

	cout <<"编码完成！"<<endl << "加密后：";
	vector<unsigned char>::iterator p = bian_ma.begin();
	for (int i = 0; p < bian_ma.end(); i++,p++)
	{
		cout << bian_ma[i];
	}
	cout << endl;
	system("pause");
	system("cls");
}

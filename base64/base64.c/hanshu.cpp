#include"lei.h"



//�����ֵ�
char zidian[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
		'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X','Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
		'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u', 'v',
		'w', 'x', 'y', 'z', '0', '1', '2', '3','4', '5', '6', '7', '8', '9', '+', '/' };




//���������壬��Ϊ����������λ��ɽ�3���ֽڣ�Ҳ����24���أ�����Ҫ�ֶ��и�ﵽ4��6bit
union base64
{
	struct//8λ
	{
		unsigned int three_8 : 8;
		unsigned int  two_8 : 8;
		unsigned int  one_8 : 8;
	};
	struct//6λ
	{
		unsigned int  four_6 : 6;
		unsigned int  three_6 : 6;
		unsigned int  two_6 : 6;
		unsigned int  one_6 : 6;
	};
};




/// <summary>
/// ////////////////////������
/// </summary>
/// 
/// //�ļ�����
void base64_jiema::jiema()
{
	union base64 temp = { 0 };//���ù������и�
	string tem;//���ļ�����ĵ����tem
	string File_address;//�����ļ���ַ
	fstream file;//�ļ�����
	vector<unsigned char> jie_ma;
	int n = 0;//1.���ڵȺŴ���2.����vector�����ļ�
	cout << "�������ļ�����" << endl;
	cin >> File_address;//�����ļ���
	file.open(File_address);//���ļ�
	if (file.fail())//�ж��ļ��Ƿ�򿪳ɹ�
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	file >> tem;//�ļ���ĵ��뵽tem
	file.close();//�ر��ļ�

	//����Ⱥ�
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

	//4�ı���
	while (tem.length() % 4 != 0)
	{
		tem.push_back('A');
	}

	for (int i = 0; i < tem.length(); i += 4)//��tem���ݷŽ��������и�
	{
		//���������ֵ�һһ��Ӧ
		int tem1 = find(tem[i]);
		int tem2 = find(tem[i+1]);
		int tem3 = find(tem[i+2]);
		int tem4 = find(tem[i+3]);

		//��char�Ž������壬;�з���ǿ������ת��
		temp.one_6 = tem1;
		temp.two_6 = tem2;
		temp.three_6 = tem3;
		temp.four_6 = tem4;
		//�и�
		jie_ma.push_back(temp.one_8);
		jie_ma.push_back(temp.two_8);
		jie_ma.push_back(temp.three_8);
	}
	//�����ļ�
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

	//�ر��ļ�
	out_file.close();

}

//���Ͻ���
void base64_jiema::x_jiema()
{
	union base64 temp = { 0 };//���ù������и�
	string tem;//������洢��tem
	int n;
	vector<unsigned char> jie_ma;
	cout << "��������ܵ�base64����:";
	cin >> tem;
	//����Ⱥ�
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
	//4�ı���
	while (tem.length() % 4 != 0)
	{
		tem.push_back('A');
	}

	for (int i = 0; i < tem.length(); i += 4)//��tem���ݷŽ��������и�
	{
		//���������ֵ�һһ��Ӧ
		int tem1 = find(tem[i]);
		int tem2 = find(tem[i + 1]);
		int tem3 = find(tem[i + 2]);
		int tem4 = find(tem[i + 3]);

		//��char�Ž������壬;�з���ǿ������ת��
		temp.one_6 = tem1;
		temp.two_6 = tem2;
		temp.three_6 = tem3;
		temp.four_6 = tem4;
		//�и�
		jie_ma.push_back(temp.one_8);
		jie_ma.push_back(temp.two_8);
		jie_ma.push_back(temp.three_8);
	}
	cout << "������ɣ�" << endl << "���ܺ�";
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
/// ////////////////////������
/// </summary>
/// 
/// 


void base64_bianma::bianma()
{
	union base64 temp = { 0 };//���ù������и�
	string tem;//���ļ�����ĵ����tem
	string File_address;//�����ļ���ַ
	fstream file;//�ļ�����
	vector<unsigned char> bian_ma;
	int n=0;//��vector�Ž��ļ�
	int count = 0;
	cout << "�������ļ�����"  << endl;
	cin >> File_address;//�����ļ���
	file.open(File_address);//���ļ�
	if (file.fail())//�ж��ļ��Ƿ�򿪳ɹ�
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	file >> tem;//���ļ����ݵ��뵽tem
	file.close();
	while ( tem.length() % 3 != 0)//�����3�ı���
	{
		tem.push_back(0);
		count++;
	}
	for (int i = 0; i < tem.length(); i += 3)
	{
		////��tem�洢���빲����
		temp.one_8 = tem.at(i);
		temp.two_8 = tem.at(i+1);
		temp.three_8 = tem.at(i + 2);
		//���������ȡ����
		bian_ma.push_back(zidian[temp.one_6]);
		bian_ma.push_back(zidian[temp.two_6]);
		bian_ma.push_back(zidian[temp.three_6]);
		bian_ma.push_back(zidian[temp.four_6]);
	}



	//��0����=
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
	
	//�����ļ�
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

	//�ر��ļ�
	out_file.close();
}




void base64_bianma::x_bianma()
{
	union base64 temp = { 0 };//���ù������и�
	string input = "0";
	vector<unsigned char> bian_ma;
	int n;
	int count=0;
	cout << "��������Ҫ���ܵ�base64���룺";
	cin >> input;
	while (input.length() % 3 != 0)//����3λ����ѭ��
	{
		input.push_back('0');
		count++;
	}
	for (int i = 0; i < input.length(); i+=3)
	{
		////��tem�洢���빲����
		temp.one_8 = input.at(i);
		temp.two_8 = input.at(i + 1);
		temp.three_8 = input.at(i + 2);
		//���������ȡ����
		bian_ma.push_back(zidian[temp.one_6]);
		bian_ma.push_back(zidian[temp.two_6]);
		bian_ma.push_back(zidian[temp.three_6]);
		bian_ma.push_back(zidian[temp.four_6]);
	}

	//��0����=
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

	cout <<"������ɣ�"<<endl << "���ܺ�";
	vector<unsigned char>::iterator p = bian_ma.begin();
	for (int i = 0; p < bian_ma.end(); i++,p++)
	{
		cout << bian_ma[i];
	}
	cout << endl;
	system("pause");
	system("cls");
}

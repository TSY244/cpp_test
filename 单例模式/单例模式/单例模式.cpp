#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;

//����ģʽʵ��
class My_class
{
public:
	static My_class* set_My_class();
	~My_class();
	static int count;//����public�ܴ���߷���
private:
	//�����캯����ʵ����private,��My_class�Ĺ���ֻ�ܴ����й���_
	My_class();//���캯��
	My_class(My_class& obj);//�������캯��
	static My_class* pMy_class;
};
//static ��Ա�ĳ�ʼ��
My_class* My_class::pMy_class = NULL;
int My_class::count=0;

/// <summary>
/// ///////////////////////////////////////////////////////////////////////////////
/// </summary>
/// <returns></returns>
int main()
{
	//����һ����������
	//����3����ԭ����Ϊ����֤����ģʽ�ĳɹ�
	My_class* p1 = NULL;
	p1 = My_class::set_My_class();
	My_class* p2 = NULL;
	p2 = My_class::set_My_class();
	My_class* p3 = NULL;
	p3 = My_class::set_My_class();

	//��֤����ģʽ
	cout << hex << "p1=" << p1 << endl;
	cout << hex << "p2=" << p2 << endl;
	cout << hex << "p3=" << p3 << endl;
	cout << "������" << My_class::count <<"����My_class��"<< endl;
	return 0;
}


//�Լ��Ĺ��캯��
My_class* My_class::set_My_class()
{
	if (My_class::pMy_class == NULL)
	{
		pMy_class = new My_class;
	}
	return pMy_class;
}
//��������

My_class::~My_class()
{
	cout << "��������" << endl;
	delete pMy_class;
}


//���캯��
My_class::My_class()
{
	cout << "����ģʽ����" << endl;
	count++;
}

My_class::My_class(My_class& obj)
{
	cout << "����ģʽ����" << endl;
	count++;
}

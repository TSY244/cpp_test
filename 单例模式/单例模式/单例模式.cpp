#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;

//单例模式实现
class My_class
{
public:
	static My_class* set_My_class();
	~My_class();
	static int count;//放在public能从外边访问
private:
	//将构造函数，实现在private,让My_class的构建只能从类中构建_
	My_class();//构造函数
	My_class(My_class& obj);//拷贝构造函数
	static My_class* pMy_class;
};
//static 成员的初始化
My_class* My_class::pMy_class = NULL;
int My_class::count=0;

/// <summary>
/// ///////////////////////////////////////////////////////////////////////////////
/// </summary>
/// <returns></returns>
int main()
{
	//创建一个析构函数
	//创建3个的原因因为，验证单例模式的成功
	My_class* p1 = NULL;
	p1 = My_class::set_My_class();
	My_class* p2 = NULL;
	p2 = My_class::set_My_class();
	My_class* p3 = NULL;
	p3 = My_class::set_My_class();

	//验证单例模式
	cout << hex << "p1=" << p1 << endl;
	cout << hex << "p2=" << p2 << endl;
	cout << hex << "p3=" << p3 << endl;
	cout << "创建了" << My_class::count <<"个类My_class类"<< endl;
	return 0;
}


//自己的构造函数
My_class* My_class::set_My_class()
{
	if (My_class::pMy_class == NULL)
	{
		pMy_class = new My_class;
	}
	return pMy_class;
}
//析构函数

My_class::~My_class()
{
	cout << "析构函数" << endl;
	delete pMy_class;
}


//构造函数
My_class::My_class()
{
	cout << "单例模式构造" << endl;
	count++;
}

My_class::My_class(My_class& obj)
{
	cout << "单例模式构造" << endl;
	count++;
}

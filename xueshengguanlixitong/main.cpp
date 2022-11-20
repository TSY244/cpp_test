#include <iostream>
#include<string>
#include <iomanip>
#include <fstream>


using namespace std;
//全局变量
int all_value=0;//判断是否已经进行数据录取


//出生日期
typedef struct date_of_birth
{
    int day;
    int month;
    int year;
}birth;

/////////////////////////////////
//学生类
class manage
{
public:
    int stu_create();//信息创建
    void display();//打印函数
    int all_stu_infom();//学生信息
    int search();//通过姓名查找
    void display2(int i);//打印单个
    int averageScore();//计算平均值
    int pass_rate();//计算及格率
    int comparemin();//找出最小
    int stu_storage();//学生信息存储
    void keydown();//主体函数
    void menu();//菜单函数
    int stu_delete();//学生信息删除
    void my_delete();//摧毁内存
    int stu_change();//学生信息修改
    int stu_sort();//排序
    int stu_import();//学生信息录用

private:
    string name,number,gender;
    int grade[3]={0};
    birth stu_date;
    manage*p;//储存学生信息
    int count=0;//学生个数

};
//学生信息录用
int manage::stu_import()
{
    ifstream file;
    int i;
    int j=0;//用于文件
    file.open("chg.txt",ios::in);
    cout<<"请输入导入几个人的数据:";
    cin>>i;getchar();
    p=new manage[count+i+1];
    while(j<i)
    {
        if(file.fail())
        {
            break;
        }
        file>>p[count+j].number>>p[count+j].name>>p[count+j].gender
        >>p[count+j].stu_date.year>>p[count+j].stu_date.month
        >>p[count+j].stu_date.day>>p[count+j].grade[0]
        >>p[count+j].grade[1]>>p[count+j].grade[2];
    }
    count+=i;
    file.close();
    cout<<"录入成功！";
}
////学生信息修改
int manage::stu_change()
{
    string ch_name;
    int i=0;//用于增加学生
    if(count==0)
    {
        cout << "请输入学生数据" << endl;
        return 0;
    }
    cout<<"请输入学生姓名：";
    cin>>ch_name;getchar();
    for(i=0;i<count;i++)
    {
        if(p[i].name==ch_name)
        {
            break;
        }
    }
    cout<<"请重新输入学生信息"<<endl;
    cout<<"请输入学号：";
    cin>>p[i].number;getchar();
    cout<<"性别：";
    while (1)
    {
        cin>>p[i].gender;getchar();
        if (p[i].gender.compare("man") == 0 || p[i].gender.compare("woman" )== 0)
        {
            break;
        }
        else
        {
            printf("输入错误，请重新输入：");
        }
    }
    cout<<"请输入语文成绩：";
    cin>>p[i].grade[0];getchar();
    cout<<"请输入数学成绩：";
    cin>>p[i].grade[1];getchar();
    cout<<"请输入英语成绩：";
    cin>>p[i].grade[2];getchar();

    cout<<"请输入出生日期\nyear:";
    while (1)
    {
        cin>>p[i].stu_date.year;
        if ((p[i].stu_date.year> 0 )&& (p[i].stu_date.year < 2022))
        {
            break;
        }
        else
        {
            cout<<"输入错误，请重新输入：";
        }
    }
    cout<<"month：";
    while(1)
    {
        cin>>p[i].stu_date.month;
        getchar();
        if ((p[i].stu_date.month> 0 )&& (p[i].stu_date.month < 13))
        {
            break;
        }
        else
        {
            cout << "输入错误，请重新输入：";
        }
    }
    cout<<"day";
    while(1)
    {
        cin>>p[i].stu_date.day;
        getchar();
        if ((p[i].stu_date.day> 0 )&& (p[i].stu_date.day < 32))
        {
            break;
        }
        else
        {
            cout << "输入错误，请重新输入：";
        }
    }
}

////学生排序
int manage::stu_sort()
{
    if(count==0)
    {
        cout << "请输入学生数据" << endl;
        return 0;
    }
    int option;//用于科目的选择
    int option2;//用于顺序的选择
    if(count==0)
    {
        cout << "请输入学生数据" << endl;
        return 0;
    }
    cout<<"选择学科!"<<endl;
    cout<<"选择科目："<<endl<<"1.语文成绩\t2.数学成绩\t3.英语成绩"<<endl;

    while(1)
    {
        cin>>option;
        if(option!=1&&option!=2&&option!=3)
        {
            cout<<"选择错误,请重新选择:";
            continue;
        }
        break;
    }
    cout<<"请选择:1.升序 2.降序"<<endl;
    while(1)
    {
        cin>>option2;
        if(option2!=1&&option2!=2)
        {
            cout<<"选择错误,请重新选择：";
            continue;
        }
        break;
    }
    p[count]=p[1];//当初多创建的临时变量
    if(option2==1)
    {
        for(int i=0;i<count;i++)
        {
            for(int j=1;j<count-i;j++)
            {
                if(p[j-1].grade[option]>p[j].grade[option])
                {
                    p[count]=p[j-1];
                    p[j-1]=p[j];
                    p[j]=p[count];
                }
            }
        }
    }
    else
    {
        for(int i=0;i<count;i++)
        {
            for(int j=1;j<count-i;j++)
            {
                if(p[j-1].grade[option]<p[j].grade[option])
                {
                    p[count]=p[j-1];
                    p[j-1]=p[j];
                    p[j]=p[count];
                }
            }
        }
    }
    display();
}

////学生信息摧毁
int manage::stu_delete()
{
    string a;//用于选择删除的人
    int i=0;
    if(count==0)
    {
        cout << "请输入学生数据" << endl;
        return 0;
    }
    cout<<"请输入需要删除的人的学号"<<endl;
    cin>>a;getchar();
    for(i=0;i<count;i++)
    {
        if(p[i].number==a)
        {
            break;
        }
    }
    if(i==count)
    {
        cout<<"输入错误！"<<endl;
        return 0;
    }
    while(i<count)
    {
        p[i]=p[i+1];
        i++;
    }
    count--;
    cout<<"删除完成!"<<endl;
}

////内存摧毁
void manage::my_delete()
{
    delete[] p;
}

////学生信息存储
int manage::stu_storage()
{
    ofstream file;//用于文件操作
    if(count==0)
    {
        cout << "请输入学生数据" << endl;
        return 0;
    }
    file.open("chg.txt");
    for(int i=0;i<count;i++)
    {
        file<<p[i].name<<endl<<p[i].number<<endl<<p[i].gender<<endl<<p[i].grade[0]
            <<endl<<p[i].grade[1]<<endl<<p[i].grade[2]<<endl<<p[i].stu_date.year<<endl
            <<p[i].stu_date.month<<endl<<p[i].stu_date.day<<endl<<endl;
    }
    file.close();
    cout<<"存储成功!"<<endl;
    return 0;
}

////找出最小
int manage::comparemin()
{
    cout<<"******现在是找出最小的学生******"<<endl;
    int i=0;
    while(1)
    {
        if(count==0)
        {
            cout << "请输入学生数据" << endl;
            return 0;
        }
        int i=0;
        p[count]=p[0];
        while (i<count)
        {
            if(p[count].stu_date.year>p[i].stu_date.year)
            {
                p[count]=p[i];
                continue;
            }
            else if(p[count].stu_date.year==p[i].stu_date.year)
            {
                if(p[count].stu_date.month>p[i].stu_date.month)
                {
                    p[count]=p[i];
                    continue;
                }
                else if(p[count].stu_date.month==p[i].stu_date.month)
                {
                    if(p[count].stu_date.day>p[i].stu_date.day)
                    {
                        p[count]=p[i];
                        continue;
                    }
                }
            }
            i++;

        }
        if(i==count)
        {
            display2(count);
            break;
        }
    }
}


////及格率
int manage::pass_rate()
{
    int option,rate;//选择成绩，及格率
    int i;//循环变量
    int a=0;//计数器
    cout<<"*****现在是计算及格率******"<<endl;
    if(count==0)
    {
        cout<<"请输入学生数据"<<endl;
        return 0;
    }
    cout<<"\n\n是否计算该班的及格率?\n1.计算\tt0.退出\n"<<endl;
    cin>>option;getchar();
    if(option==0)
    {
        cout<<"推出成功！";
        return 0;
    }
    cout<<"请选择哪个科目："<<endl;
    cout<<"选择科目："<<endl<<"1.语文成绩\t2.数学成绩\t3.英语成绩"<<endl;
    cin>>option;
    cout<<"请输入及格分数:";
    cin>>rate;getchar();
    for(i=0;i<count;i++)
    {
        if(p[i].grade[option]>=rate)
        {
            a++;
        }
    }
    cout<<"及格人数为："<<a<<"\t及格率为:"<<setprecision(9)<<a/count<<"%"<<endl;
}


////平均成绩
int manage::averageScore()
{
    int option;
    int i=0;//判断循环
    int sum=0;
    if(count==0)
    {
        cout<<"请输入学生数据"<<endl;
        return 0;
    }
    cout<<"******现在是计算平均成绩！******";
    while(1)
    {
        cout<<"\n\n是否计算该班的平均分数?\n1.计算\t0.退出\n"<<endl;
        cin>>option;getchar();
        if(option==0)
        {
            cout<<"退出成功！";
            return 0;
        }
        cout<<"选择科目："<<endl<<"1.语文成绩\t2.数学成绩\t3.英语成绩"<<endl;
        while(1)
        {
            cin>>option;
            if(option<0||option>3)
            {
                cout << "输入错误,请重新输入:";
                continue;
            }
            for(sum=0,i=0;i<count;i++)
            {
                sum+=p[i].grade[option-1];
            }
            cout<<"平均成绩是："<<sum/count<<endl;
            if(i==count)
            {
                break;
            }
        }
    }
}



////通过姓名查找
int manage::search()
{
    string tem;//用于临时比较
    int i;//控制循环次数
    if(count==0)
    {
        cout<<"请输入学生数据"<<endl;
        return 0;
    }
    cout<<"请输入查找人的姓名";
    cin>>tem;getchar();
    for(i=0;i<count;i++)
    {
        if(tem==p[i].name)
        {
            display2(i);
            break;
        }
    }
    if(i==count)
    {
        cout<<"查无此人"<<endl;
    }
}
////打印函数2//这里有点愚蠢
void manage::display2(int i)
{
    cout<<"学号为："<<p[i].number<<"\t";
    cout<<"姓名是："<<p[i].name<<"\t";
    cout<<"性别是:"<<p[i].gender<<endl;
    cout<<"出生日期为：";
    cout<<p[i].stu_date.year<<"|" << p[i].stu_date.month<<"|"<<p[i].stu_date.day<<endl;
    cout<<"语文成绩："<<p[i].grade[0]<<"\t"<<"数学成绩："<<p[i].grade[1]<<"\t"<<"英语成绩："<<p[i].grade[2]<<endl<<endl;
}


////打印函数
void manage::display()
{
    int i=0;
    cout<<"******现在是打印所有学生信息模块******"<<endl;
    while(1)
    {
        if(count==0)
        {
            cout<<"请输入数据";
            break;
        }
        for(i=0;i<count;i++)
        {
            cout<<"第"<<i+1<<"个学生数据"<<endl;
            cout<<"学号为："<<p[i].number<<"\t";
            cout<<"姓名是："<<p[i].name<<"\t";
            cout<<"性别是:"<<p[i].gender<<endl;
            cout<<"出生日期为：";
            cout<<p[i].stu_date.year<<"|" << p[i].stu_date.month<<"|"<<p[i].stu_date.day<<endl;
            cout<<"语文成绩："<<p[i].grade[0]<<"\t"<<"数学成绩："<<p[i].grade[1]<<"\t"<<"英语成绩："<<p[i].grade[2]<<endl<<endl;
        }
        if(i==count)
        {
            break;
        }
    }
}



////打印所有人的信息
int manage::all_stu_infom()
{
    int i;
    if(count==0)
    {
        cout<<"请输入学生数据"<<endl;
        return 0;
    }
    for(i=0;i<count;i++)
    {
        display();
    }
}


////信息创建
int  manage::stu_create()
{
    int a=0;//option
    cout<<"是否进行数据录取？\n0.exit\t1.continue"<<endl;
    cin>>a;
    if(a==0)
    {
        return 1;
    }
    if(all_value!=0)
    {
        int option;
        cout<<"是否选择覆盖数据?\n0.exit\t1.yes\n请选择:"<<endl;
        cin>>option;getchar();
        if(option==0)
        {
            return 0;
        }
    }
    cout<<"请问学生个数：";
    cin>>count;
    getchar();
    p=new manage[count+1];//多创建一个，用于信息存储
    for(int i=0;i<count;i++)
    {
        cout<<"请输入第"<<i+1<<"个学生数据"<<endl;
        cout<<"请输入姓名：";
        cin>>p[i].name;getchar();
        cout<<"请输入学号：";
        cin>>p[i].number;getchar();
        cout<<"性别：";
        while (1)
        {
            cin>>p[i].gender;getchar();
            if (p[i].gender.compare("man") == 0 || p[i].gender.compare("woman" )== 0)
            {
                break;
            }
            else
            {
                printf("输入错误，请重新输入：");
            }
        }
        cout<<"请输入语文成绩：";
        cin>>p[i].grade[0];getchar();
        cout<<"请输入数学成绩：";
        cin>>p[i].grade[1];getchar();
        cout<<"请输入英语成绩：";
        cin>>p[i].grade[2];getchar();

        cout<<"请输入出生日期\nyear:";
        while (1)
        {
            cin>>p[i].stu_date.year;
            if ((p[i].stu_date.year> 0 )&& (p[i].stu_date.year < 2022))
            {
                break;
            }
            else
            {
                cout<<"输入错误，请重新输入：";
            }
        }
        cout<<"month：";
        while(1)
        {
            cin>>p[i].stu_date.month;
            getchar();
            if ((p[i].stu_date.month> 0 )&& (p[i].stu_date.month < 13))
            {
                break;
            }
            else
            {
                cout << "输入错误，请重新输入：";
            }
        }
        cout<<"day";
        while(1)
        {
            cin>>p[i].stu_date.day;
            getchar();
            if ((p[i].stu_date.day> 0 )&& (p[i].stu_date.day < 32))
            {
                break;
            }
            else
            {
                cout << "输入错误，请重新输入：";
            }
        }
        cout<<endl<<endl<<endl;
    }
    all_value++;
}


////主体函数
void manage::keydown()
{
    int choose;
    do
    {
        menu();
        cin>>choose;
        getchar();
        switch (choose)
        {
            case 0:
            {
                printf("退出成功！\n");
                break;
            }
            case 1:
            {
                stu_create();
                break;
            }
            case 2:
            {
                all_stu_infom();
                break;
            }
            case 3:
            {
                search();
                break;
            }
            case 4:
            {
                averageScore();
                break;
            }
            case 5:
            {
                pass_rate();
                break;
            }
            case 6:
            {
                comparemin();
                break;
            }
            case 7:
            {
                stu_storage();
                break;
            }
            case 8:
            {
                stu_delete();
                break;
            }
            case 9:
            {
                stu_sort();
                break;
            }
            case 10:
            {
                stu_change();
                break;
            }
            case 11:
            {
                stu_import();
                break;
            }
            default:
            {
                printf("输入错误，请重新输入：");
                break;
            }
        }
    } while (choose);
    getchar();
}


////菜单函数
void manage::menu()
{
    cout<<"欢迎使用学生管理系统！\n出品人：chg\n"
        <<"\n\n--------0.退出系统--------\n"
          "--------1.录入学生信息--------\n"
          "--------2.查看所有学生信息--------\n"
          "--------3.通过姓名查找学生--------\n"
          "--------4.统计输出平均成绩--------\n"
          "--------5.计算及格率--------\n"
          "--------6.找出年纪最小的学生--------\n"
          "--------7.学生信息存储--------\n"
          "--------8.学生信息删除--------\n"
          "--------9.学生信息排序--------\n"
          "--------10.学生信息修改--------\n"
          "--------11.学生信息导入--------\n"<<endl;
    cout<<"请选择:";

}

/////////////////////////////////




int main()
{
    manage way;
    way.keydown();
    way.my_delete();
    return 0;
}


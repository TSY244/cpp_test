#include <iostream>
#include<string>
#include <iomanip>
#include <fstream>


using namespace std;
//ȫ�ֱ���
int all_value=0;//�ж��Ƿ��Ѿ���������¼ȡ


//��������
typedef struct date_of_birth
{
    int day;
    int month;
    int year;
}birth;

/////////////////////////////////
//ѧ����
class manage
{
public:
    int stu_create();//��Ϣ����
    void display();//��ӡ����
    int all_stu_infom();//ѧ����Ϣ
    int search();//ͨ����������
    void display2(int i);//��ӡ����
    int averageScore();//����ƽ��ֵ
    int pass_rate();//���㼰����
    int comparemin();//�ҳ���С
    int stu_storage();//ѧ����Ϣ�洢
    void keydown();//���庯��
    void menu();//�˵�����
    int stu_delete();//ѧ����Ϣɾ��
    void my_delete();//�ݻ��ڴ�
    int stu_change();//ѧ����Ϣ�޸�
    int stu_sort();//����
    int stu_import();//ѧ����Ϣ¼��

private:
    string name,number,gender;
    int grade[3]={0};
    birth stu_date;
    manage*p;//����ѧ����Ϣ
    int count=0;//ѧ������

};
//ѧ����Ϣ¼��
int manage::stu_import()
{
    ifstream file;
    int i;
    int j=0;//�����ļ�
    file.open("chg.txt",ios::in);
    cout<<"�����뵼�뼸���˵�����:";
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
    cout<<"¼��ɹ���";
}
////ѧ����Ϣ�޸�
int manage::stu_change()
{
    string ch_name;
    int i=0;//��������ѧ��
    if(count==0)
    {
        cout << "������ѧ������" << endl;
        return 0;
    }
    cout<<"������ѧ��������";
    cin>>ch_name;getchar();
    for(i=0;i<count;i++)
    {
        if(p[i].name==ch_name)
        {
            break;
        }
    }
    cout<<"����������ѧ����Ϣ"<<endl;
    cout<<"������ѧ�ţ�";
    cin>>p[i].number;getchar();
    cout<<"�Ա�";
    while (1)
    {
        cin>>p[i].gender;getchar();
        if (p[i].gender.compare("man") == 0 || p[i].gender.compare("woman" )== 0)
        {
            break;
        }
        else
        {
            printf("����������������룺");
        }
    }
    cout<<"���������ĳɼ���";
    cin>>p[i].grade[0];getchar();
    cout<<"��������ѧ�ɼ���";
    cin>>p[i].grade[1];getchar();
    cout<<"������Ӣ��ɼ���";
    cin>>p[i].grade[2];getchar();

    cout<<"�������������\nyear:";
    while (1)
    {
        cin>>p[i].stu_date.year;
        if ((p[i].stu_date.year> 0 )&& (p[i].stu_date.year < 2022))
        {
            break;
        }
        else
        {
            cout<<"����������������룺";
        }
    }
    cout<<"month��";
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
            cout << "����������������룺";
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
            cout << "����������������룺";
        }
    }
}

////ѧ������
int manage::stu_sort()
{
    if(count==0)
    {
        cout << "������ѧ������" << endl;
        return 0;
    }
    int option;//���ڿ�Ŀ��ѡ��
    int option2;//����˳���ѡ��
    if(count==0)
    {
        cout << "������ѧ������" << endl;
        return 0;
    }
    cout<<"ѡ��ѧ��!"<<endl;
    cout<<"ѡ���Ŀ��"<<endl<<"1.���ĳɼ�\t2.��ѧ�ɼ�\t3.Ӣ��ɼ�"<<endl;

    while(1)
    {
        cin>>option;
        if(option!=1&&option!=2&&option!=3)
        {
            cout<<"ѡ�����,������ѡ��:";
            continue;
        }
        break;
    }
    cout<<"��ѡ��:1.���� 2.����"<<endl;
    while(1)
    {
        cin>>option2;
        if(option2!=1&&option2!=2)
        {
            cout<<"ѡ�����,������ѡ��";
            continue;
        }
        break;
    }
    p[count]=p[1];//�����ഴ������ʱ����
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

////ѧ����Ϣ�ݻ�
int manage::stu_delete()
{
    string a;//����ѡ��ɾ������
    int i=0;
    if(count==0)
    {
        cout << "������ѧ������" << endl;
        return 0;
    }
    cout<<"��������Ҫɾ�����˵�ѧ��"<<endl;
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
        cout<<"�������"<<endl;
        return 0;
    }
    while(i<count)
    {
        p[i]=p[i+1];
        i++;
    }
    count--;
    cout<<"ɾ�����!"<<endl;
}

////�ڴ�ݻ�
void manage::my_delete()
{
    delete[] p;
}

////ѧ����Ϣ�洢
int manage::stu_storage()
{
    ofstream file;//�����ļ�����
    if(count==0)
    {
        cout << "������ѧ������" << endl;
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
    cout<<"�洢�ɹ�!"<<endl;
    return 0;
}

////�ҳ���С
int manage::comparemin()
{
    cout<<"******�������ҳ���С��ѧ��******"<<endl;
    int i=0;
    while(1)
    {
        if(count==0)
        {
            cout << "������ѧ������" << endl;
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


////������
int manage::pass_rate()
{
    int option,rate;//ѡ��ɼ���������
    int i;//ѭ������
    int a=0;//������
    cout<<"*****�����Ǽ��㼰����******"<<endl;
    if(count==0)
    {
        cout<<"������ѧ������"<<endl;
        return 0;
    }
    cout<<"\n\n�Ƿ����ð�ļ�����?\n1.����\tt0.�˳�\n"<<endl;
    cin>>option;getchar();
    if(option==0)
    {
        cout<<"�Ƴ��ɹ���";
        return 0;
    }
    cout<<"��ѡ���ĸ���Ŀ��"<<endl;
    cout<<"ѡ���Ŀ��"<<endl<<"1.���ĳɼ�\t2.��ѧ�ɼ�\t3.Ӣ��ɼ�"<<endl;
    cin>>option;
    cout<<"�����뼰�����:";
    cin>>rate;getchar();
    for(i=0;i<count;i++)
    {
        if(p[i].grade[option]>=rate)
        {
            a++;
        }
    }
    cout<<"��������Ϊ��"<<a<<"\t������Ϊ:"<<setprecision(9)<<a/count<<"%"<<endl;
}


////ƽ���ɼ�
int manage::averageScore()
{
    int option;
    int i=0;//�ж�ѭ��
    int sum=0;
    if(count==0)
    {
        cout<<"������ѧ������"<<endl;
        return 0;
    }
    cout<<"******�����Ǽ���ƽ���ɼ���******";
    while(1)
    {
        cout<<"\n\n�Ƿ����ð��ƽ������?\n1.����\t0.�˳�\n"<<endl;
        cin>>option;getchar();
        if(option==0)
        {
            cout<<"�˳��ɹ���";
            return 0;
        }
        cout<<"ѡ���Ŀ��"<<endl<<"1.���ĳɼ�\t2.��ѧ�ɼ�\t3.Ӣ��ɼ�"<<endl;
        while(1)
        {
            cin>>option;
            if(option<0||option>3)
            {
                cout << "�������,����������:";
                continue;
            }
            for(sum=0,i=0;i<count;i++)
            {
                sum+=p[i].grade[option-1];
            }
            cout<<"ƽ���ɼ��ǣ�"<<sum/count<<endl;
            if(i==count)
            {
                break;
            }
        }
    }
}



////ͨ����������
int manage::search()
{
    string tem;//������ʱ�Ƚ�
    int i;//����ѭ������
    if(count==0)
    {
        cout<<"������ѧ������"<<endl;
        return 0;
    }
    cout<<"����������˵�����";
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
        cout<<"���޴���"<<endl;
    }
}
////��ӡ����2//�����е��޴�
void manage::display2(int i)
{
    cout<<"ѧ��Ϊ��"<<p[i].number<<"\t";
    cout<<"�����ǣ�"<<p[i].name<<"\t";
    cout<<"�Ա���:"<<p[i].gender<<endl;
    cout<<"��������Ϊ��";
    cout<<p[i].stu_date.year<<"|" << p[i].stu_date.month<<"|"<<p[i].stu_date.day<<endl;
    cout<<"���ĳɼ���"<<p[i].grade[0]<<"\t"<<"��ѧ�ɼ���"<<p[i].grade[1]<<"\t"<<"Ӣ��ɼ���"<<p[i].grade[2]<<endl<<endl;
}


////��ӡ����
void manage::display()
{
    int i=0;
    cout<<"******�����Ǵ�ӡ����ѧ����Ϣģ��******"<<endl;
    while(1)
    {
        if(count==0)
        {
            cout<<"����������";
            break;
        }
        for(i=0;i<count;i++)
        {
            cout<<"��"<<i+1<<"��ѧ������"<<endl;
            cout<<"ѧ��Ϊ��"<<p[i].number<<"\t";
            cout<<"�����ǣ�"<<p[i].name<<"\t";
            cout<<"�Ա���:"<<p[i].gender<<endl;
            cout<<"��������Ϊ��";
            cout<<p[i].stu_date.year<<"|" << p[i].stu_date.month<<"|"<<p[i].stu_date.day<<endl;
            cout<<"���ĳɼ���"<<p[i].grade[0]<<"\t"<<"��ѧ�ɼ���"<<p[i].grade[1]<<"\t"<<"Ӣ��ɼ���"<<p[i].grade[2]<<endl<<endl;
        }
        if(i==count)
        {
            break;
        }
    }
}



////��ӡ�����˵���Ϣ
int manage::all_stu_infom()
{
    int i;
    if(count==0)
    {
        cout<<"������ѧ������"<<endl;
        return 0;
    }
    for(i=0;i<count;i++)
    {
        display();
    }
}


////��Ϣ����
int  manage::stu_create()
{
    int a=0;//option
    cout<<"�Ƿ��������¼ȡ��\n0.exit\t1.continue"<<endl;
    cin>>a;
    if(a==0)
    {
        return 1;
    }
    if(all_value!=0)
    {
        int option;
        cout<<"�Ƿ�ѡ�񸲸�����?\n0.exit\t1.yes\n��ѡ��:"<<endl;
        cin>>option;getchar();
        if(option==0)
        {
            return 0;
        }
    }
    cout<<"����ѧ��������";
    cin>>count;
    getchar();
    p=new manage[count+1];//�ഴ��һ����������Ϣ�洢
    for(int i=0;i<count;i++)
    {
        cout<<"�������"<<i+1<<"��ѧ������"<<endl;
        cout<<"������������";
        cin>>p[i].name;getchar();
        cout<<"������ѧ�ţ�";
        cin>>p[i].number;getchar();
        cout<<"�Ա�";
        while (1)
        {
            cin>>p[i].gender;getchar();
            if (p[i].gender.compare("man") == 0 || p[i].gender.compare("woman" )== 0)
            {
                break;
            }
            else
            {
                printf("����������������룺");
            }
        }
        cout<<"���������ĳɼ���";
        cin>>p[i].grade[0];getchar();
        cout<<"��������ѧ�ɼ���";
        cin>>p[i].grade[1];getchar();
        cout<<"������Ӣ��ɼ���";
        cin>>p[i].grade[2];getchar();

        cout<<"�������������\nyear:";
        while (1)
        {
            cin>>p[i].stu_date.year;
            if ((p[i].stu_date.year> 0 )&& (p[i].stu_date.year < 2022))
            {
                break;
            }
            else
            {
                cout<<"����������������룺";
            }
        }
        cout<<"month��";
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
                cout << "����������������룺";
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
                cout << "����������������룺";
            }
        }
        cout<<endl<<endl<<endl;
    }
    all_value++;
}


////���庯��
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
                printf("�˳��ɹ���\n");
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
                printf("����������������룺");
                break;
            }
        }
    } while (choose);
    getchar();
}


////�˵�����
void manage::menu()
{
    cout<<"��ӭʹ��ѧ������ϵͳ��\n��Ʒ�ˣ�chg\n"
        <<"\n\n--------0.�˳�ϵͳ--------\n"
          "--------1.¼��ѧ����Ϣ--------\n"
          "--------2.�鿴����ѧ����Ϣ--------\n"
          "--------3.ͨ����������ѧ��--------\n"
          "--------4.ͳ�����ƽ���ɼ�--------\n"
          "--------5.���㼰����--------\n"
          "--------6.�ҳ������С��ѧ��--------\n"
          "--------7.ѧ����Ϣ�洢--------\n"
          "--------8.ѧ����Ϣɾ��--------\n"
          "--------9.ѧ����Ϣ����--------\n"
          "--------10.ѧ����Ϣ�޸�--------\n"
          "--------11.ѧ����Ϣ����--------\n"<<endl;
    cout<<"��ѡ��:";

}

/////////////////////////////////




int main()
{
    manage way;
    way.keydown();
    way.my_delete();
    return 0;
}


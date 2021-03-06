// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<string>
#include<string.h>
#include<cmath>

struct Equ//用结点来表示一个设备
{
    char no[12];//设备编号
    char name[40];//名称
    float dj;//单价
    int num;//数量
    float jine;//金额
};
struct Node//结点表示一个设备
{
    Equ data;//计算机设备
    struct Node * next;//指向下一个结点的指针
};
void print0()
{
    cout<<"\t\t-------------主程序-------------\t\t"<<endl;
    cout<<"\t\t\t1.用牛顿迭代法解方程\t\t\t"<<endl;
    cout<<"\t\t\t2.埃及分数\t\t\t"<<endl;
    cout<<"\t\t\t3.计算机设备管理系统\t\t\t"<<endl;
    cout<<"\t\t\t0.退出主程序\t\t\t"<<endl;
    cout<<"\t\t---------------------------------\t\t"<<endl;
}
void print()//输出计算机设备管理系统界面信息
{
    cout<<"\t\t--------计算机设备管理系统--------\t\t"<<endl;
    cout<<"\t\t\t1.查看计算机设备信息\t\t\t"<<endl;
    cout<<"\t\t\t2.录入计算机设备信息\t\t\t"<<endl;
    cout<<"\t\t\t3.查找计算机设备信息\t\t\t"<<endl;
    cout<<"\t\t\t4.修改计算机设备信息\t\t\t"<<endl;
    cout<<"\t\t\t5.删除计算机设备信息\t\t\t"<<endl;
    cout<<"\t\t\t6.计算每个设备金额\t\t\t"<<endl;
    cout<<"\t\t\t7.计算设备总数量总金额\t\t\t"<<endl;
    cout<<"\t\t\t0.退出计算机设备管理系统\t\t\t"<<endl;
    // cout<<"\t\t\t8.排序\t\t\t"<<endl;
    cout<<"\t\t---------------------------------\t\t"<<endl;
}
void print1()//输出计算机设备更改界面
{
    cout<<"\t\t--------计算机设备更改系统--------\t\t"<<endl;
    cout<<"\t\t\t1.更改计算机设备编号\t\t\t"<<endl;
    cout<<"\t\t\t2.更改计算机设备名称\t\t\t"<<endl;
    cout<<"\t\t\t3.更改计算机设备单价\t\t\t"<<endl;
    cout<<"\t\t\t4.更改计算机设备数量\t\t\t"<<endl;
    cout<<"\t\t\t0.退出计算机设备更改系统\t\t\t"<<endl;
    cout<<"\t\t---------------------------------\t\t"<<endl;
}
void ReadFile(Node*&H)//读取文件建立设备单链表
{
    FILE*fp;
    Equ equ1;
    Node *p,*r;//r一直指向尾结点，p为新建结点
    int n=0;
    H=new Node;
    r=H;//开始r指向头结点
    if((fp=fopen("equ.dat","rb"))==NULL)
    {
        if((fp=fopen("equ.dat","wb"))==NULL)
            cout<<"不能创建dat文件"<<endl;
    }
    else
    {
        while(fread(&equ1,sizeof(Equ),1,fp)==1)
        {
            p=new Node;
            p->data=equ1;
            r->next=p;
            r=p;
            n++;
        }
    }
    r->next=NULL;
    cout<<"\t\t设备单链表创建成功共"<<n<<"个设备"<<endl;
    fclose(fp);
}
void SaveFile(Node*H)//将单链表数据存储在dat文件中
{
    Node*p=H->next;
    int n=0;
    FILE*fp;
    fp=fopen("equ.dat","wb");
    while(p!=NULL)
    {
        fwrite(&p->data,sizeof(Equ),1,fp);
        p=p->next;
        n++;
    }
    cout<<"\t\t存储了"<<n<<"个设备信息"<<endl;
    fclose(fp);

}
void InputNode(Node*&H)//链表添加一个结点
{
    Node*s;//新存储的结点信息
    Equ equ1;
    s=new Node;
    printf("请输入新添加设备编号\n");
    scanf("%s",&equ1.no);
    printf("请输入新添加设备的名称 单价 数量\n");
    scanf("%s %f %d",&equ1.name,&equ1.dj,&equ1.num);
    // cin>>equ1.name>>equ1.dj>>equ1.num;
    equ1.jine=equ1.dj*equ1.num;
    s->data=equ1;
    s->next=H->next;//头插法
    H->next=s;
    cout<<"添加成功"<<endl;
}
void DestroyAllNode(Node*&H)//销毁所有链表结点
{
    Node*pre=H,*p=pre->next;
    while(p!=NULL)
    {
        delete pre;
        pre=p;
        p=pre->next;
    }
    delete pre;
}
void DelFile(Node*&H)//删除dat文件中所有信息
{
    FILE*fp;
    fp=fopen("equ.dat","wb");
    fclose(fp);
    DestroyAllNode(H);
    H=new Node;
    H->next=NULL;
}
void DispAllEqu(Node*H)//显示所有设备具体信息
{
    Node*p=H->next;
    if(p==NULL)
        printf("没有任何计算机设备信息\n");
    else
    {
        printf("\t设备编号\t名称\t单价\t数量\t金额\n");
        printf("-------------------------------------------------------------\n");
        while(p!=NULL)
        {
            printf("\t%s\t\t%s\t%0.1f\t%d\t%0.1f\n",p->data.no,p->data.name,p->data.dj,p->data.num,p->data.jine);
            p=p->next;
        }
        printf("-------------------------------------------------------------\n");
    }
}
void DispOneEqu(Node*p)//显示一个设备信息
{
    printf("\t设备编号\t名称\t单价\t数量\t金额\n");
    printf("-------------------------------------------------------------\n");
    printf("\t%s\t\t%s\t%0.1f\t%d\t%0.1f\n",p->data.no,p->data.name,p->data.dj,p->data.num,p->data.jine);
    printf("-------------------------------------------------------------\n");
}
void SortAllEquNo(Node*&H)//将所有结点按照no递增排序
{
    Node*p,*pre,*q,*prel;
    p=H->next->next;
    if(p!=NULL)
    {
        H->next->next=NULL;
        while(p!=NULL)
        {
            q=p->next;
            pre=H;
            int flag;
            while(pre->next!=NULL&&((flag=strcmp(pre->next->data.no,p->data.no))<0?1:0))
            {
                pre=pre->next;
            }
            p->next=pre->next;
            pre->next=p;
            p=q;
        }
    }
    printf("设备信息按no递增排序完毕\n");

}
void FindOneEqu(Node*H)//查找一个计算机设备
{
    printf(">>>请输入要查找的计算机设备编号:\n");
    char st[12];
    scanf("%s",st);
    Node*p=H->next;
    while(p!=NULL)
    {
        int flag=strcmp(p->data.no,st);
        if (flag==0)
        {
            printf("查找到了该设备\n");
            DispOneEqu(p);
            break;
        }
        p=p->next;
    }
    if(p==NULL)
        printf("该计算机设备不存在\n");
}
void ChangeOneEqu(Node*&H)//改变一个计算机设备的信息
{
    printf(">>>请输入要更改的计算机设备编号:\n");
    char st[12];
    scanf("%s",st);
    Node*p=H->next;
    while(p!=NULL)
    {
        int flag=strcmp(p->data.no,st);
        if (flag==0)
        {
            printf("查找到了要更改的设备\n");
            print1();
            int x;
            while(1)
            {
                printf(">>>请输入要实现功能前序号:\n");
                scanf("%d",&x);
                switch (x)
                {
                case 0:
                    printf("计算机设备更改系统退出成功，进入计算机设备管理系统\n");
                    print();
                    break;
                case 1:
                    printf(">>>请输入新的设备编号:\n");
                    char st0[12];
                    scanf("%s",&st0);
                    strcpy(p->data.no,st0);
                    printf("设备编号更改成功\n");
                    break;
                case 2:
                    printf(">>>请输入新的设备名称:\n");
                    char st1[40];
                    scanf("%s",&st1);
                    strcpy(p->data.name,st1);
                    printf("设备名称更改成功\n");
                    break;
                case 3:
                    printf(">>>请输入新的设备单价:\n");
                    int n2;
                    scanf("%d",&n2);
                    p->data.dj=n2;
                    printf("设备单价更改成功\n");
                    break;
                case 4:
                    printf(">>>请输入新的设备数量:\n");
                    int n3;
                    scanf("%d",&n3);
                    p->data.num=n3;
                    printf("设备数量更改成功\n");
                    break;
                default:
                    printf("您输入的序号有误，请重新输入！\n");
                    break;
                }
                if(x==0)
                {
                    break;
                }
                    
            }
            break;
        }
        p=p->next;
    }
    if(p==NULL)
        printf("要更改的计算机设备不存在\n");
}
void DelOneEqu(Node*&H)//删除一个计算机设备
{
    printf(">>>请输入要删除的计算机设备编号:\n");
    char st[12];
    scanf("%s",st);
    Node*p=H->next;
    Node*pre=H;
    while(p!=NULL)
    {
        int flag=strcmp(p->data.no,st);
        if (flag==0)
        {
            printf("查找到了要删除的设备\n");
            pre->next=p->next;
            delete p;
            printf("设备信息删除成功\n");
            break;
        }
        pre=pre->next;
        p=p->next;
    }
    if(p==NULL)
        printf("要删除的计算机设备不存在\n");
}
void ConutJine(Node*&H)//计算计算机设备的金额(更新)
{
    Node*p=H->next;
    while(p!=NULL)
    {
        p->data.jine=p->data.num*p->data.dj;
        p=p->next;
    }
    printf("计算机设备金额计算成功\n");
}
void ConutAllEqu(Node*H)//计算计算机设备总金额、总数量
{
    int sum_num=0;
    float sum_jine=0;
    ConutJine(H);
    Node*p=H->next;
    while(p!=NULL)
    {
        int x1=p->data.num;
        float x2=p->data.jine;
        // printf("%d %f\n",x1,x2);
        sum_num+=x1;
        sum_jine+=x2;
        p=p->next;
        
    }
    printf("计算机设备总金额、总数量计算成功\n");
    printf("总数量为：%d\n",sum_num);
    printf("总金额为：%0.1f\n",sum_jine);
    
}
double fun(double a,double b,double c,double d,double x)//方程导函数
{
    double ans=a*pow(x,3)+b*pow(x,2)+c*x+d;
    return ans;
}
double fun1(double a,double b,double c,double d,double x)//方程原函数
{
    double ans=(3*a*x+2*b)*x+c;
    return ans;
}
void printJFC()//输出牛顿迭代法解方程的界面
{
    cout<<"\t\t---------牛顿迭代法解方程---------\t\t"<<endl;
    cout<<"\t\t\t1.开始求解方程\t\t\t"<<endl;
    cout<<"\t\t\t0.退出\t\t\t"<<endl;
    cout<<"\t\t---------------------------------\t\t"<<endl;
}
void JFC()//牛顿迭代法解方程
{
    printJFC();
    int H;
    while(1)
    {
        printf(">>>请输入要实现功能前序号:\n");
        scanf("%d",&H);
        if(H==1)
        {
            double a,b,c,d,x,x0;
            x=rand()%10+1;
            printf(">>>请输入方程三次方程前面的系数a,b,c,d(用空格分开):\n");
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            do
            {
                x0=x;
                x=x0-fun(a,b,c,d,x0)/fun1(a,b,c,d,x0);
            }while(fabs(x-x0)>=1e-5);
            printf("三次方程为%.0fx^3+%.0fx^2+%.0fx+%.0f\n",a,b,c,d);
            printf("其解为%f\n",x);
            continue;
        }
        else
        {
            printf("牛顿迭代法解方程退出成功，进入主程序\n");
            print0();
            break;
        }
    }
    
}
void printFS()//输出埃及分数的界面
{
    cout<<"\t\t------------埃及分数------------\t\t"<<endl;
    cout<<"\t\t\t1.开始求解埃及分数\t\t\t"<<endl;
    cout<<"\t\t\t0.退出\t\t\t"<<endl;
    cout<<"\t\t---------------------------------\t\t"<<endl;
}
void FS()
{
    printFS();
    int H;
    while(1)
    {
        printf(">>>请输入要实现功能前序号:\n");
        scanf("%d",&H);
        if(H==1)
        {
            int a,b,c;
            printf(">>>请输入埃及分数的分子a和分母b(用空格分开):\n");
            scanf("%d%d",&a,&b);
            printf("分解后的埃及分数为:\n");
            printf("%d/%d=",a,b);
            if(a==1||b%a==0)//分子为一或者可以化简为分子为一的形式
            {
                printf("1/%d",b/a);
                // a=1;
            }
            while(a!=1)
            {
                c=b/a+1;
                printf("1/%d",c);
                a=a*c-b;//先a后b
                b=b*c;
                if(a>=1)
                printf("+");
                if(a==3&&b%2==0)//循环终点,分子为3，分母为偶数
                {
                    printf("1/%d+1/%d",b/2,b);
                    break;
                }
                else if(a==1||b%a==0)//循环终点
                {
                    printf("1/%d",b/a);
                    a=1;//b%a==0情况
                }
            }
            printf("\n");
            continue;
        }
        else
        {
            printf("埃及分数退出成功，进入主程序\n");
            print0();
            break;
        }
    }

}
int main()
{
    int M;
    print0();
    while(1)
    {
        printf(">>>请输入要实现功能前序号:\n");
        scanf("%d",&M);
        switch (M)
        {
        case 0:
            break;
        case 1:
            JFC();
            break;
        case 2:
            FS();
            break;
        case 3:
            Node *H;//头结点H
            ReadFile(H);
            // DelFile(H);
            // InputNode(H);
            int I;
            print();
            while(1)
            {
                printf(">>>请输入要实现功能前序号:\n");
                scanf("%d",&I);
                switch (I)
                {
                case 0:
                    printf("计算机设备管理系统退出成功，进入主程序\n");
                    print0();
                    break;
                case 1:
                    SortAllEquNo(H);
                    DispAllEqu(H);
                    break;
                case 2:
                    InputNode(H);
                    break;
                case 3:
                    FindOneEqu(H);
                    break;
                case 4:
                    DispAllEqu(H);
                    ChangeOneEqu(H);
                    break;
                case 5:
                    DelOneEqu(H);
                    break;
                case 6:
                    ConutJine(H);
                    break;
                case 7:
                    ConutAllEqu(H);
                    break;
                
                // case 8:
                //     SortAllEquNo(H);
                default:
                    printf("您输入的序号有误，请重新输入！\n");
                    break;
                }
                if(I==0)
                {
                    break;
                }
                    
            }
            SaveFile(H);
            // DelFile(H);
            break;
        default: 
            printf("您输入的序号有误，请重新输入！\n");
            break;
        }
        if(M==0)
        {
            break;
        }
            
    }
    
    system("pause");
    return 0;
}

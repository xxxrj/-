// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<string>
#include<string.h>
#include<cmath>

struct Equ//�ý������ʾһ���豸
{
    char no[12];//�豸���
    char name[40];//����
    float dj;//����
    int num;//����
    float jine;//���
};
struct Node//����ʾһ���豸
{
    Equ data;//������豸
    struct Node * next;//ָ����һ������ָ��
};
void print0()
{
    cout<<"\t\t-------------������-------------\t\t"<<endl;
    cout<<"\t\t\t1.��ţ�ٵ������ⷽ��\t\t\t"<<endl;
    cout<<"\t\t\t2.��������\t\t\t"<<endl;
    cout<<"\t\t\t3.������豸����ϵͳ\t\t\t"<<endl;
    cout<<"\t\t\t0.�˳�������\t\t\t"<<endl;
    cout<<"\t\t---------------------------------\t\t"<<endl;
}
void print()//���������豸����ϵͳ������Ϣ
{
    cout<<"\t\t--------������豸����ϵͳ--------\t\t"<<endl;
    cout<<"\t\t\t1.�鿴������豸��Ϣ\t\t\t"<<endl;
    cout<<"\t\t\t2.¼�������豸��Ϣ\t\t\t"<<endl;
    cout<<"\t\t\t3.���Ҽ�����豸��Ϣ\t\t\t"<<endl;
    cout<<"\t\t\t4.�޸ļ�����豸��Ϣ\t\t\t"<<endl;
    cout<<"\t\t\t5.ɾ��������豸��Ϣ\t\t\t"<<endl;
    cout<<"\t\t\t6.����ÿ���豸���\t\t\t"<<endl;
    cout<<"\t\t\t7.�����豸�������ܽ��\t\t\t"<<endl;
    cout<<"\t\t\t0.�˳�������豸����ϵͳ\t\t\t"<<endl;
    // cout<<"\t\t\t8.����\t\t\t"<<endl;
    cout<<"\t\t---------------------------------\t\t"<<endl;
}
void print1()//���������豸���Ľ���
{
    cout<<"\t\t--------������豸����ϵͳ--------\t\t"<<endl;
    cout<<"\t\t\t1.���ļ�����豸���\t\t\t"<<endl;
    cout<<"\t\t\t2.���ļ�����豸����\t\t\t"<<endl;
    cout<<"\t\t\t3.���ļ�����豸����\t\t\t"<<endl;
    cout<<"\t\t\t4.���ļ�����豸����\t\t\t"<<endl;
    cout<<"\t\t\t0.�˳�������豸����ϵͳ\t\t\t"<<endl;
    cout<<"\t\t---------------------------------\t\t"<<endl;
}
void ReadFile(Node*&H)//��ȡ�ļ������豸������
{
    FILE*fp;
    Equ equ1;
    Node *p,*r;//rһֱָ��β��㣬pΪ�½����
    int n=0;
    H=new Node;
    r=H;//��ʼrָ��ͷ���
    if((fp=fopen("equ.dat","rb"))==NULL)
    {
        if((fp=fopen("equ.dat","wb"))==NULL)
            cout<<"���ܴ���dat�ļ�"<<endl;
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
    cout<<"\t\t�豸���������ɹ���"<<n<<"���豸"<<endl;
    fclose(fp);
}
void SaveFile(Node*H)//�����������ݴ洢��dat�ļ���
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
    cout<<"\t\t�洢��"<<n<<"���豸��Ϣ"<<endl;
    fclose(fp);

}
void InputNode(Node*&H)//�������һ�����
{
    Node*s;//�´洢�Ľ����Ϣ
    Equ equ1;
    s=new Node;
    printf("������������豸���\n");
    scanf("%s",&equ1.no);
    printf("������������豸������ ���� ����\n");
    scanf("%s %f %d",&equ1.name,&equ1.dj,&equ1.num);
    // cin>>equ1.name>>equ1.dj>>equ1.num;
    equ1.jine=equ1.dj*equ1.num;
    s->data=equ1;
    s->next=H->next;//ͷ�巨
    H->next=s;
    cout<<"��ӳɹ�"<<endl;
}
void DestroyAllNode(Node*&H)//��������������
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
void DelFile(Node*&H)//ɾ��dat�ļ���������Ϣ
{
    FILE*fp;
    fp=fopen("equ.dat","wb");
    fclose(fp);
    DestroyAllNode(H);
    H=new Node;
    H->next=NULL;
}
void DispAllEqu(Node*H)//��ʾ�����豸������Ϣ
{
    Node*p=H->next;
    if(p==NULL)
        printf("û���κμ�����豸��Ϣ\n");
    else
    {
        printf("\t�豸���\t����\t����\t����\t���\n");
        printf("-------------------------------------------------------------\n");
        while(p!=NULL)
        {
            printf("\t%s\t\t%s\t%0.1f\t%d\t%0.1f\n",p->data.no,p->data.name,p->data.dj,p->data.num,p->data.jine);
            p=p->next;
        }
        printf("-------------------------------------------------------------\n");
    }
}
void DispOneEqu(Node*p)//��ʾһ���豸��Ϣ
{
    printf("\t�豸���\t����\t����\t����\t���\n");
    printf("-------------------------------------------------------------\n");
    printf("\t%s\t\t%s\t%0.1f\t%d\t%0.1f\n",p->data.no,p->data.name,p->data.dj,p->data.num,p->data.jine);
    printf("-------------------------------------------------------------\n");
}
void SortAllEquNo(Node*&H)//�����н�㰴��no��������
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
    printf("�豸��Ϣ��no�����������\n");

}
void FindOneEqu(Node*H)//����һ��������豸
{
    printf(">>>������Ҫ���ҵļ�����豸���:\n");
    char st[12];
    scanf("%s",st);
    Node*p=H->next;
    while(p!=NULL)
    {
        int flag=strcmp(p->data.no,st);
        if (flag==0)
        {
            printf("���ҵ��˸��豸\n");
            DispOneEqu(p);
            break;
        }
        p=p->next;
    }
    if(p==NULL)
        printf("�ü�����豸������\n");
}
void ChangeOneEqu(Node*&H)//�ı�һ��������豸����Ϣ
{
    printf(">>>������Ҫ���ĵļ�����豸���:\n");
    char st[12];
    scanf("%s",st);
    Node*p=H->next;
    while(p!=NULL)
    {
        int flag=strcmp(p->data.no,st);
        if (flag==0)
        {
            printf("���ҵ���Ҫ���ĵ��豸\n");
            print1();
            int x;
            while(1)
            {
                printf(">>>������Ҫʵ�ֹ���ǰ���:\n");
                scanf("%d",&x);
                switch (x)
                {
                case 0:
                    printf("������豸����ϵͳ�˳��ɹ������������豸����ϵͳ\n");
                    print();
                    break;
                case 1:
                    printf(">>>�������µ��豸���:\n");
                    char st0[12];
                    scanf("%s",&st0);
                    strcpy(p->data.no,st0);
                    printf("�豸��Ÿ��ĳɹ�\n");
                    break;
                case 2:
                    printf(">>>�������µ��豸����:\n");
                    char st1[40];
                    scanf("%s",&st1);
                    strcpy(p->data.name,st1);
                    printf("�豸���Ƹ��ĳɹ�\n");
                    break;
                case 3:
                    printf(">>>�������µ��豸����:\n");
                    int n2;
                    scanf("%d",&n2);
                    p->data.dj=n2;
                    printf("�豸���۸��ĳɹ�\n");
                    break;
                case 4:
                    printf(">>>�������µ��豸����:\n");
                    int n3;
                    scanf("%d",&n3);
                    p->data.num=n3;
                    printf("�豸�������ĳɹ�\n");
                    break;
                default:
                    printf("�����������������������룡\n");
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
        printf("Ҫ���ĵļ�����豸������\n");
}
void DelOneEqu(Node*&H)//ɾ��һ��������豸
{
    printf(">>>������Ҫɾ���ļ�����豸���:\n");
    char st[12];
    scanf("%s",st);
    Node*p=H->next;
    Node*pre=H;
    while(p!=NULL)
    {
        int flag=strcmp(p->data.no,st);
        if (flag==0)
        {
            printf("���ҵ���Ҫɾ�����豸\n");
            pre->next=p->next;
            delete p;
            printf("�豸��Ϣɾ���ɹ�\n");
            break;
        }
        pre=pre->next;
        p=p->next;
    }
    if(p==NULL)
        printf("Ҫɾ���ļ�����豸������\n");
}
void ConutJine(Node*&H)//���������豸�Ľ��(����)
{
    Node*p=H->next;
    while(p!=NULL)
    {
        p->data.jine=p->data.num*p->data.dj;
        p=p->next;
    }
    printf("������豸������ɹ�\n");
}
void ConutAllEqu(Node*H)//���������豸�ܽ�������
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
    printf("������豸�ܽ�����������ɹ�\n");
    printf("������Ϊ��%d\n",sum_num);
    printf("�ܽ��Ϊ��%0.1f\n",sum_jine);
    
}
double fun(double a,double b,double c,double d,double x)//���̵�����
{
    double ans=a*pow(x,3)+b*pow(x,2)+c*x+d;
    return ans;
}
double fun1(double a,double b,double c,double d,double x)//����ԭ����
{
    double ans=(3*a*x+2*b)*x+c;
    return ans;
}
void printJFC()//���ţ�ٵ������ⷽ�̵Ľ���
{
    cout<<"\t\t---------ţ�ٵ������ⷽ��---------\t\t"<<endl;
    cout<<"\t\t\t1.��ʼ��ⷽ��\t\t\t"<<endl;
    cout<<"\t\t\t0.�˳�\t\t\t"<<endl;
    cout<<"\t\t---------------------------------\t\t"<<endl;
}
void JFC()//ţ�ٵ������ⷽ��
{
    printJFC();
    int H;
    while(1)
    {
        printf(">>>������Ҫʵ�ֹ���ǰ���:\n");
        scanf("%d",&H);
        if(H==1)
        {
            double a,b,c,d,x,x0;
            x=rand()%10+1;
            printf(">>>�����뷽�����η���ǰ���ϵ��a,b,c,d(�ÿո�ֿ�):\n");
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            do
            {
                x0=x;
                x=x0-fun(a,b,c,d,x0)/fun1(a,b,c,d,x0);
            }while(fabs(x-x0)>=1e-5);
            printf("���η���Ϊ%.0fx^3+%.0fx^2+%.0fx+%.0f\n",a,b,c,d);
            printf("���Ϊ%f\n",x);
            continue;
        }
        else
        {
            printf("ţ�ٵ������ⷽ���˳��ɹ�������������\n");
            print0();
            break;
        }
    }
    
}
void printFS()//������������Ľ���
{
    cout<<"\t\t------------��������------------\t\t"<<endl;
    cout<<"\t\t\t1.��ʼ��Ⱓ������\t\t\t"<<endl;
    cout<<"\t\t\t0.�˳�\t\t\t"<<endl;
    cout<<"\t\t---------------------------------\t\t"<<endl;
}
void FS()
{
    printFS();
    int H;
    while(1)
    {
        printf(">>>������Ҫʵ�ֹ���ǰ���:\n");
        scanf("%d",&H);
        if(H==1)
        {
            int a,b,c;
            printf(">>>�����밣�������ķ���a�ͷ�ĸb(�ÿո�ֿ�):\n");
            scanf("%d%d",&a,&b);
            printf("�ֽ��İ�������Ϊ:\n");
            printf("%d/%d=",a,b);
            if(a==1||b%a==0)//����Ϊһ���߿��Ի���Ϊ����Ϊһ����ʽ
            {
                printf("1/%d",b/a);
                // a=1;
            }
            while(a!=1)
            {
                c=b/a+1;
                printf("1/%d",c);
                a=a*c-b;//��a��b
                b=b*c;
                if(a>=1)
                printf("+");
                if(a==3&&b%2==0)//ѭ���յ�,����Ϊ3����ĸΪż��
                {
                    printf("1/%d+1/%d",b/2,b);
                    break;
                }
                else if(a==1||b%a==0)//ѭ���յ�
                {
                    printf("1/%d",b/a);
                    a=1;//b%a==0���
                }
            }
            printf("\n");
            continue;
        }
        else
        {
            printf("���������˳��ɹ�������������\n");
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
        printf(">>>������Ҫʵ�ֹ���ǰ���:\n");
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
            Node *H;//ͷ���H
            ReadFile(H);
            // DelFile(H);
            // InputNode(H);
            int I;
            print();
            while(1)
            {
                printf(">>>������Ҫʵ�ֹ���ǰ���:\n");
                scanf("%d",&I);
                switch (I)
                {
                case 0:
                    printf("������豸����ϵͳ�˳��ɹ�������������\n");
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
                    printf("�����������������������룡\n");
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
            printf("�����������������������룡\n");
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

#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 50
struct sqlist
{
    int date[MAXSIZE];
    int length;
};
bool insect(sqlist &a,int place,int number)
{
    if(a.length+1>MAXSIZE)return false;
    if(place<1||place>a.length+1)return false;
    //例如length有五个元素，所以可以插在第五第六个元素上，
    //则place可以=a.length+1
    for(int i=a.length-1;i>=place-1;i--)
    {
        a.date[i+1]=a.date[i];
    }
    a.date[place-1]=number;
    a.length++;
    return 1;
}
bool delet(sqlist &a,int place)
{
    if(place<1||place>a.length)return false;
    for(int j=place-1;j+1<=a.length-1;j++)
    {
        a.date[j]=a.date[j+1];
    }
    a.length--;
    return 1;
}
int main()
{
    cout<<"要有几个表?"<<endl;
    int m;cin>>m;
   sqlist *a=new sqlist[m];//申请(new) m个sqlist类型的无名参数
   //a为第1个无名参数的地址,&a[0]=a,a[0]为结构体本身;
    for(int i=0;i<m;)
    {
        printf("你要给第%d个顺序表存储几个数据:",i+1);
        cin>>a[i].length;
        if(a[i].length>MAXSIZE){cout<<"数组没那么大";continue;}
        for(int j=0;j<a[i].length;j++)
        {
            cin>>a[i].date[j];
        }
        i++;
    }
    cout<<"你要进行什么操作";
    string operato;
    cin>>operato;
    if(operato=="insect")
    {
        int i,place,number;
        cout<<"依次输入插入的表，插入的位置(1-length+1)和数字:";
        cin>>i>>place>>number;
        if(i>=1&&i<=m)
        {bool x=insect(a[i-1],place,number);cout<<x;}
        else cout<<"没有这个表";
    }
    else if(operato=="delet")
    {
        int i,place;
        cout<<"依次输入表，删除的位置(1-length+1):";
        cin>>i>>place;
        if(i>=1&&i<=m)
        {bool x=delet(a[i-1],place);cout<<x;}
        else cout<<"没有这个表";
    }
    delete[] a;
    return 0;
}

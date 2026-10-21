#include<bits/stdc++.h>
using namespace std;
struct sqlist
{
    int *date;
    int length;
};
bool insect(sqlist *&a,int place,int number)
{
    if(a->length<place)return false;
}
int main()
{
    cout<<"要建立几个表：";
    int m;cin>>m;
   sqlist *a=new sqlist[m];//申请(new) m个sqlist类型的无名参数
   //a为第1个无名参数的地址,&a[0]=a,a[0]为结构体本身; 
    int i=0;
    printf("你要给第几个顺序表存储几个数据:");
    int n;cin>>i>>n;
    printf("你要给第%d个顺序表存储%d个数据:",i,n);
    a[i].date=new int[n];
    for(int j=0;j<n;j++)
    {
        cin>>a[i].date[j];
    }
}


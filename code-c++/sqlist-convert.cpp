#include<bits/stdc++.h>
using namespace std;
struct sqlist
{
    int *date;
    int length;
};
int main()
{
    int m;cin>>m;
   sqlist *a=new sqlist[m];//申请(new) m个sqlist类型的无名参数
   //a为第1个无名参数的地址,&a[0]=a,a[0]为结构体本身;
   int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        a[i].date=new int[n];//a[i].date是指针，
        //new给这个指针分配一个地址,装int类型，可以装n个.
        cin>>a[i].date[i];//给第i+1个结构体，输入第i+1个数据.
        a[i].length++;
    }
}

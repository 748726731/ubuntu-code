#include<bits/stdc++.h>
using namespace std;
int a[1024][1024];
void shemian(int x,int y,int len)
{
    if(len==1)return;
    int half=len/2;
    for(int i=x;i<x+half;i++)
    {
        for(int j=y;j<y+half;j++)
        {
            a[i][j]=0;
        }
    }
    shemian(x,y+half,half);//右上
    shemian(x+half,y+half,half);//右下
    shemian(x+half,y,half);
}
int main()
{
    int n;cin>>n;
    int size=(int)pow(2,n);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            a[i][j]=1;
        }
    }
    shemian(0,0,size);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(void)
{ 
        int p,n,m=0;//n是当前同学的编号
        cin>>p>>m;//p是同学人数，m是传递次数
        vector<int> a(p);
          for(int i=0;i<p;i++)
    {
        cin>>a[i];
    }
        int cnt=a[0];//cnt是当前同学衣服上的数字
        for(int i=0;i<m;i++)
        {
            n = (n - cnt % (int)a.size() + (int)a.size()) % (int)a.size();
            // n-cnt本质:原来的位置，往前走多少步
            //%(int)a.size()本质:如果走了5个环，得到的余数为:在第6个环上 相较于 第6个环现在这个位置 多少步
            //+(int)a.size()%(int)a.size()本质：怕这个步是负数的，给他搞正来，例如是目的地为第六个环的-2步
            //就相当于第七个环的+4步
            cnt=a[n];
        }
        cout<<n+1<<endl;//输出当前同学的编号
        return 0;
    }
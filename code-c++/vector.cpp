#include <bits/stdc++.h>//包含了vector,sort
using namespace std;

int main() {
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a=0;
        cin>>a;
        if(a==1)
        {
            int a1=0;
            cin>>a1;
            v.push_back(a1);//数组后面补一个
        }
        else if(a==2)
        {
            v.pop_back();//数组后面删除一个
        }
        else if(a==3)
        {
            int a3=0;
            cin>>a3;
            cout<<v[a3]<<"\n";
        }
        else if(a==4)
        {
            int a4=0,a41=0;
            cin>>a4>>a41;
            v.insert(v.begin()+a4+1,a41);//把a41放在v[a4 + 1]的地方，不是v[a4 + 1]=a41,而是把原来的东西全部往后挪一位
        }
        else if(a==5)
        {
            sort(v.begin(),v.end());//从大到小排序数组 
        }
        else if(a==6)
        {
            sort(v.begin(),v.end());///从大到小排序数组 
            reverse(v.begin(),v.end());//反转数组
        }
        else if(a==7)
        {
            int a7=0;
            a7=v.size();//数组长度
            cout<<a7<<"\n";
        }
        else if(a==8)
        {
            for(auto a8=0;a8<v.size();a8++)//遍历输出
            {
                cout<<v[a8]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
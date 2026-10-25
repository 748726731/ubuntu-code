#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int,string>a={20,"cjx"};//=struct;
    pair<int,string>b;
    b=make_pair(5,"pm");
    cout<<a.first<<endl;
    vector<pair<int,int>>postion(5);
    for(int i=0;i<5;i++)
    {
        postion.push_back(make_pair(i,i));
    }
    for(auto i:postion)
    {
        cout<<i.first;
    }
}
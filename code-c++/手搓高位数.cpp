#include<bits/stdc++.h>
using namespace std;
vector<int> mulSmall(const vector<int>& a_point, int b)
//拿一个锁住的大数例如9876543,乘一个小数例如12
{
    vector<int>result;
    int cur,cur1=0;//进位数,//放cur的数
    //然后大数乘小数，个位数乘完以后把个位数推给vector
    for(int i=0;i<a_point.size();i++)//9876543有7个数字
    //乘七次。从3开始分别乘上12,是36，要36的6，3丢给下一位
    {
        cur=a_point[i]*b+cur1;
        result.push_back(cur%10);
        cur1=cur/10;//传给下一位
    }
    if(cur>0)
    {
        while(cur1!=0)
        {
            result.push_back(cur1%10);
            cur1/=10;
        }
    }
    return result;
}
vector<int>add(const vector<int>& b_point,const vector<int>&a_point)
{
    vector<int>result;
    int cnt=0,cnt1=0;
    for(int i=0;i<(int)max(a_point.size(),b_point.size());i++)
    {
        cnt=cnt1;
        if(i<a_point.size()) cnt+=a_point[i];
        if(i<b_point.size()) cnt+=b_point[i];
        result.push_back(cnt%10);
        cnt1=cnt/10;
    }
    if(cnt1>0)
    {
        while(cnt1!=0)
        {
            result.push_back(cnt1%10);
            cnt1/=10;
        }
    }
    return result;
}
int main()
{
    int n;
    cin >> n;

    vector<int>a{1};
    vector<int>sum;
    sum.push_back(0);
    for(int i=0;i<n;i++)
    {
        a=vector<int>{1};
        for(int j=1;j<=i+1;j++)
        {
            a=mulSmall(a,j);
        }
        sum=add(sum,a);
    }
    for(int i=sum.size()-1;i>=0;i--)
    {
        cout<<sum[i];
    }
    cout<<endl;
    return 0;
}

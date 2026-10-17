#include<bits/stdc++.h>
using namespace std;
bool judge(int sum,int zonghe)
{
    if(sum>140&&zonghe>=80)return true;
    else return false;
}
struct student
{
    int xuehao;
    double xueye,suzhi;
    int zonghe()
    {
        return xueye*0.7+suzhi*0.3;
    }
    int sum()
    {
        return xueye+suzhi;
    }
    string fanhui()
    {
        if(judge(sum(),zonghe())==true)return "Excellent";
        else return "Not excellent";
    }
};
int main()   
{
    int n;cin>>n;
    student a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].xuehao>>a[i].xueye>>a[i].suzhi;
        cout<<a[i].fanhui()<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
int feibo(int n)
{
    if(n==1||n==2)return 1;
    int f1,f2;
    f1=feibo(n-2);
    f2=feibo(n-1);
    return f1+f2;
}
int main()
{
    int n;cin>>n;
    int x=feibo(n);
    cout<<x;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    double a1,a2,sum;
    a1=pow(((1+sqrt(5))/2),n);
    a2=pow(((1-sqrt(5))/2),n);
    sum=(a1-a2)/sqrt(5);
    cout<<fixed<<setprecision(2)<<sum;
}
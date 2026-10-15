#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int i=a;
    if(i%2==0)i++;
    for(;i<=b;i=i+2)
    {
        if(i%10==5 && i!=5) continue;
        int x=i,rev=0;
        while(x){rev=rev*10+x%10;x/=10;}
        if(rev==i)
        {
            int check=1;
            for(int j=2;j*j<=i;j++)
            {
                if(i%j==0){check=2;break;}
            }
            if(check==1){cout<<i<<endl;}
        }
    }
    }
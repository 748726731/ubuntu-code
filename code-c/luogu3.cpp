#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;cin>>a>>b>>c;
    string s;cin>>s;s
    int p[3];
    p[0]=max(a,max(b,c));
    p[2]=min(a,min(b,c));
    if(a!=p[0]&&a!=p[2]){p[1]=a;}
    else if(b!=p[0]&&b!=p[2]){p[1]=b;}
    else{p[1]=c;}
    cout<<p['C'-s[0]]<<" "<<p['C'-s[1]]<<" "<<p['C'-s[2]];
}
//如果给CAB，即让我输入p[max],p[min],[p mid]
//我设p[min]=p[2],即让我输出p0 p2 p1
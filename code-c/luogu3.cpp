#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;cin>>a>>b>>c;
    string s;cin>>s;
    int p[3];
    p[0]=max(a,max(b,c));
    p[2]=min(a,min(b,c));
    if(a!=p[0]&&a!=p[2]){p[1]=a;}
    else if(b!=p[0]&&b!=p[2]){p[1]=b;}
    else{p[1]=c;}
    cout<<p[s[2]-'A']<<" "<<p[s[1]-'A']<<" "<<p[s[0]-'A'];
}//ABC映射
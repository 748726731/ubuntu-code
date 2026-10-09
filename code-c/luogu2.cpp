#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a,b,c;
   cin>>a>>b>>c;
   if(a>b)swap(a,b);//如果a>b,那么a指的就是b，b指的a
   if(a>c)swap(a,c);
    if(b>c)swap(b,c);
    cout<<a<<" "<<b<<" "<<c;
}

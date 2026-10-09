#include<bits/stdc++.h>
using namespace std;
int main()
{
 int h,r;cin>>h>>r;
 double V;
 V=3.14*r*r*h;
 if(fmod(20000.0,V)==0)
 {
  cout<<fixed<<setprecision(0)<<20000/V;
 }
 else
 {
  cout<<fixed<<setprecision(0)<<(int)20000/V+1;
 }
 return 0;
}
/*
int h,r;cin>>h>>r;
 double V;
 V=3.14*r*r*h;
 cout<<(int)ceil(20000.0/V);  
*/

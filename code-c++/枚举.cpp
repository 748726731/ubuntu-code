#include<bits/stdc++.h>
using namespace std;
enum weekday
{
    mon,tue,wed,thu,fri,sat,sun
};//默认mon=0.....sun=6;
enum booll
{
    falsee=1,truee
};
int main()
{
    weekday a,b;
    a=mon;b=tue;
    cout<<a<<" "<<b<<endl;
    booll x,y;
    x=falsee,y=truee;
    cout<<x<<" "<<y<<endl;
}
#include <iostream>
#include <string>
using namespace std;
int compete(string a)
{
    if(a=="elephant")
    {return 4;}
    if(a=="tiger")
    {return 3;}
    if(a=="cat")
    {return 2;}
    if(a=="mouse")
    {return 1;}
    return 0;
}

int main() {
    string niu,mei;
    cin>>niu>>mei;
    int a=compete(niu),b=compete(mei);
    if(a==0||b==0)
    {
        cout<<"只能输入elephant,tiger,cat,mouse";
    }
    if(a!=0&&b!=0)
    {
    if ((a-1)%4==b%4){cout<<"win";}
    else if((b-1)%4==a%4){cout<<"lose";}
    else cout<<"tie";
    return 0;
    }
}
//石头剪刀布解法，elephant→tiger→cat→mouse→elephant，是一个环，
//elephant吃tiger，于是elephant-1得到tiger，如果是是tiger就说明win了。
//环的大小为0123，无论给elephant tiger cat mouse什么连续的数字，只
//要-1以后不是负数，在(x-1)%4都是0123，就可以用(x-1)%4==y%4的模板，
//令mouse为x,(x(mouse)-1)%4==(x+3(elephant))%4 

#include <iostream>
using namespace std;
struct student
{
    string name;
    int chinese,math,english,sum;
    bool operator <(const student &x)//&是直接引用x，而非复制一个再用。//const为锁住不改(student)x.name/chinese...
    const{
        return sum<x.sum;
    }//此处const为不改(student)自己.name.chinese
    //例如a<b 前const不改b.name/chinese.. 后一个不改a.nane/chinese..
    student()
    {
        chinese=0,math=0,english=0,sum=0;
    }//构造函数1,当在main里设一个student类型的参数的时候，如果没有数据，给student.主参数.副参数 全部设为0
    student(string a,int b,int c,int d)
    {
        name = a;
        chinese = b; 
        math = c;
        english = d;
        sum = b+c+d;
    }//构造函数2，当在main里设一个student类型的参数的时候，把全部数据交出来，丢给副参数。
    
};
    int main(void) {
    string A;
    int B,C,D;
    int n;
    cin>>n;
    struct student a[2000];//无数据的student类型的参数
    for(int i=0;i<n;i++)
    {
        cin>>A>>B>>C>>D;
        a[i]=student(A,B,C,D);//把数据交给student类型的参数
    }
    int max=0;
    for(int i=1;i<n;i++)
    {
        if(a[max]<a[i])
        {
            max=i;
        }
    }
    cout << a[max].name << ' ' << a[max].chinese << ' '
         << a[max].math << ' ' << a[max].english << '\n';
         return 0;
}
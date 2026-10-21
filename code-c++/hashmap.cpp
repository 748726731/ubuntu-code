#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int>a;
    a["b"]=82,a["B"]=81;//'B'<'b',因此先输出a['B']
   
    if(a.find("b")!=a.end())cout<<"有b"<<endl;
    else cout<<"无b"<<endl;
    if(a.find("B")!=a.end())cout<<"有B"<<endl;
    else cout<<"无B"<<endl;
    //若找到了123的名字，返回123的迭代器,如果没找到返回a.end();
 
    for(auto i:a)//range-for遍历
    //i的类型是pair(const string,int)
    //因此i.first=const string 改不了
    //i.second=int 可以改(需要加引用符号&)
    {
        cout<<i.first<<i.second<<endl;
    }
    
    map<string,int>::iterator it;//定义map<>类型的迭代器it(指针)
    //(例如我a0,a1,a2都是map类型，我全都可以用a0.begin(),a1.begin)
    for(it=a.begin();it!=a.end();it++)//迭代器遍历
    {
        cout<<it->first<<(*it).second<<endl;
    }

   //map<string,int>a;a["a"]=82,a["A"]=81;
   //string,int是pair,map a里有两个元素，分别是a["b"],a["B"].

   //range-for的遍历,i是a的元素，元素只能用i.first

   //迭代器的遍历，也就是指针的遍历,指针和迭代器可以用->
   //因为指针和迭代器是地址，用了*就是指到元素，例如*it=a["b"]
   //用了->就是指到元素的pair,例如it->first就是a["b"]的first个pair;

    //map类型重构了[]这个符号,所以
    ////operator[] 的语义是「查找，找不到就默认构造并插入」——int 的默认值是0
 
}   

#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int>s={1,2,3,5};
    s.insert(0);//插入0这个数字，自动排序；
    //insert返回值为pair(iterator,bool)
    //因此可以设一个it迭代器
    set<int>::iterator set_it;
    set_it=s.insert(1).first;
    cout<<distance(s.begin(),set_it)<<endl;
    //因为集合里有1了，所以不做任何操作，直接返回pair(iterator,bool)
    //pair.first输出集合里的1的位置(迭代器)
    
    set_it=s.insert(4).first;
    cout<<distance(s.begin(),set_it)<<endl;
    //输出插入的4的位置.
    bool ok=s.erase(5);
    cout<<ok<<endl;
    //erase返回纯布尔类型
    ok=s.erase(4);
    cout<<ok<<endl;
    //初始化.

    vector<int>v={6,7,8};
    s.insert(v.begin(),v.end());//插入从v到v结束的三个数字，自动排序

    //此时s{0,1,2,3,5,6,7,8}
    set<int>::iterator it;//设一个it迭代器，是set类型的
    it=next(s.begin(),4);//it迭代器等于s.begin()往后走四步
    s.insert(it,4);//把4插入，自动排序，从it开始找位置

   /*[ 小于 x ]  [ 等于 x ]  [ 大于 x ]
               ↑          ↑
      lower_bound   upper_bound*/ 

      //例如集合135，我lower_bound(4)upper_bouud(4)
      //都是指的5
      //lower=集合里第一个不小于4的数，lower>=4 lower=5
      //lower_bound=下界，
      //upper=集合里第一个大于4的数,upper>4 upper=5

      /*
      [3]       [4]       [5]
            ↑          ↑
      lower_bound   upper_bound*/

    for(auto i:s)
    {
        cout<<i;
    }
}
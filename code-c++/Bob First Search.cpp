#include <iostream>
using namespace std;

int main() {
    string s;
    cin>>s;
    int cnt1,cnt2;
    for(auto p=s.begin();p!=s.end();p++)
    {
        cnt1=0;
        auto p1=p;
        if(p+2<s.end())
        {
            if(*p=='b'||*p=='B')
            {
                cnt1++;
                p1++;
                if(*p1=='o'||*p1=='O')
                {
                    cnt1++;
                    p1++;
                    if(*p1=='b'||*p1=='B')
                    {
                        cnt1++;
                    }
                }
            }
            if(cnt1==3)
            {
                cnt2=p-s.begin();//！！！！！！！！！！！！！！！！ 
                // (1012 - 1000) / sizeof(int) = 12 / 4 = 3
                //c++里，这个迭代器(指的p),指针，都以一个元素为单位 。 
                cout<<cnt2;
                break;
            }
        }
        else
        {
            cout<<"-1";
            break; 
        }
    }
}

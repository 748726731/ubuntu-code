#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    string a;
    cin>>a;
    stack<long long>st;
        long long num=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]>='0'&&a[i]<='9')
            {
            num=num*10+a[i]-'0';//若遇到数字,则把数字转化为整数
            }

            else if(a[i]=='#')
            {
                st.push(num);//若遇到#，则把num压入栈中
                num=0;
            }

            else   
            {
            long long b=st.top();st.pop();
            long long c=st.top();st.pop();
            if(a[i]=='+'){st.push(c+b);}//若遇到标点符号
            else if(a[i]=='-'){st.push(c-b);}
            else{st.push(c*b);}
            }
        }
        return st.top();
    return 0;

}
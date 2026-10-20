#include <iostream>
#include<string>
using namespace std;

int main() {
   string s;
   int n;
   cin>>s;
   for(int i=1;(int)s.size()<n;i++)
   {
    s+=to_string(i);//!!!!!!!!!!!!!!
    //"123"+"123"!="123123"
    //string有规则
    //string类型的字符串可以相加,string a=只能用"" 
    //前面password *p是password[1],非string类型，而是char类型 
    //*p 取出来的是 char（单个字符），不是 string。
	//所以凯撒题里 *p - 'a' 是两个整数在相减；而 s += to_string(i) 是往 string 上拼字符。
   }
   cout<<s[n-1];
}

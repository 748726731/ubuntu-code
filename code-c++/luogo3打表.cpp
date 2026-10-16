#include<bits/stdc++.h>
using namespace std;
string a[30] = {"" , "one" , "two" , 
    "three" , "four" , "five" , "six" ,
    "seven" , "eight" , "nine" , "ten" ,
    "eleven" , "twelve" , "thirteen" , 
    "fourteen" , "fifteen" , "sixteen" ,
    "seventeen" , "eighteen" , "nineteen" ,
    "twenty" , "a" , "both" , "another" ,
    "first" , "second" , "third"}; 
//打表 
int b[30] = {0 , 1 , 4 , 9 , 16 ,
    25 , 36 , 49 , 64 , 81 , 0 , 
    21 , 44 , 69 , 96 , 25 , 56 ,
    89 , 24 , 61 , 0 , 1 , 4 , 1 ,
    1 , 4 , 9};
int main()
{
    int cnt=0;int x[1000];
    for(int i=1;i<=6;i++)
    {
        string n;cin>>n;
        for(int j=1;j<=26;j++)
        {
            if(a[j]==n)
            {
                cnt++;
                x[cnt]=b[j];
                break;
            }
        }
    }//循环六次，一次拿一个单词，然后再循环26次找表里有没有一样的
    //如果有就找表里对应的数字丢到存储区.
        if(cnt==0){cout<<"0";return 0;}
        else 
        {
            sort(x+1,x+1+cnt);//数组传进函数,直接退化x[0]
            //依旧[ );
            int check=0;
            for(int i=1;i<=cnt;i++)
            {
                if(check==0)//测试 是 输出的第一个数字。
                {
                    if(x[i]==0)continue;
                    check=1;
                    cout<<x[i];
                }
                else{
                if(x[i]<=9)
                {
                    cout<<"0";
                }
                
                cout<<x[i];
                }
            }
        }      
    }


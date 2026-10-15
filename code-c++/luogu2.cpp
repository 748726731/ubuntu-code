#include<bits/stdc++.h>
using namespace std;
vector<string>turn90(int n,const vector<string>&a)
{
    vector<string>c(n,string(n,' '));
    for(int i=0;i<n;i++)//a[i][j],c[j][n-1-i]
    {
        for(int j=0;j<n;j++)
        {
            c[j][n-1-i]=a[i][j];
        }
    }
    return c;
}
vector<string>fanzhuan(int n,const vector<string>&b)
{
    vector<string>c=b;
    for(string &s:c)reverse(s.begin(),s.end());
    return c;
}
int main()
{
    int n;cin>>n;
    vector<string>a(n),b(n),c(n);//输入，输出，测试；

    for(string &s:a)cin>>s;
    //first cin:字符串s to a[0].
    //still a[n-1];循环n次
    for(string &s:b)cin>>s;
    c=turn90(n,a);
    if (c == b) { cout << 1; return 0; }       // string 版：直接 == 比较
    c = turn90(n,c);
    if (c == b) { cout << 2; return 0; }
    c = turn90(n,c);
    if (c == b) { cout << 3; return 0; }

    c = fanzhuan(n,a);
    if (c == b) { cout << 4; return 0; }

    c = turn90(n,c);
    if (c == b) { cout << 5; return 0; }
    c = turn90(n,c);
    if (c == b) { cout << 5; return 0; }
    c = turn90(n,c);
    if (c == b) { cout << 5; return 0; }

    if (a == b) { cout << 6; return 0; }
    cout << 7;
    return 0;
}
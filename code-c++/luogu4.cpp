#include<bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    int cnt[26]={};
    for(int i=0;i<4;i++)
    {
        string a;
        getline(cin,a);
        n=n+a;
    }
    for(int i=0;i<n.size();i++)
    {
        if(n[i]>='A'&&n[i]<='Z')
        {
            cnt[n[i]-'A']++;
        }
    }
    int h=0;
    for(int i=0;i<26;i++)h=max(h,cnt[i]);
    char output[h+1][26];
    for(int i=0;i<h+1;i++)
    {
        for(int j=0;j<26;j++)
        {
            output[i][j]=' ';
        }
    }
    for(int i=0;i<26;i++)
    {
        output[h][i]='A'+i;
        for(int j=1;j<=cnt[i];j++)
        {
            output[h-j][i]='*';
        }
    }
    for(int i=0;i<h+1;i++)
    {
        for(int j=0;j<26;j++)
        {
            cout<<output[i][j];
        }
        cout<<endl;
    }
}
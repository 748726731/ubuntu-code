#include<bits/stdc++.h>
using namespace std;
struct sstring{
    char cn[52];
    int length;
};
vector<int>getnxt(sstring c)
{
    vector<int>nxt(c.length+2,1);
    nxt[1]=0;
    for(int i=2;i<=c.length;i++)
    {
        int best=0;
        for(int len=(i-1)-1;len>=1;len--)//求子串相同前后缀最大值
        {
            int k = 0;
            while (k < len && c.cn[1 + k] == c.cn[((i-1)-len)+1+k])k++;
            if (k == len) { best = len; break; }    // 比到 len 个全等才算
        }
        nxt[i]=best+1;
    }
    return nxt;
}
int KMP(sstring s,sstring c)
{
    vector<int>nxt=getnxt(c);
    int i=1,j=1;
    while(i-j+c.length<=s.length&&j<=c.length)
    {
        if(s.cn[i]==c.cn[j]){i++;j++;}
        else if(s.cn[i]!=c.cn[j]&&j>1){j=nxt[j];}
        else if(j==1&&s.cn[i]!=c.cn[j]){i++;}
    }
    return (j>c.length)?i-j+1:-1;
}
int main()
{
    sstring s,c;
    cin>>&s.cn[1];
    cin>>&c.cn[1];
    s.length=strlen(s.cn+1);
    c.length=strlen(c.cn+1);
    cout<<KMP(s,c);
}
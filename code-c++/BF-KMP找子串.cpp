#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 52
typedef struct{
    char cn[MAXSIZE];
    int length;
}sstring;
//---------------------------------------------------------------------------
int BF2(sstring s,sstring c)
{
    int i=1,j=1;
    while(i<=s.length)
    {
        if(i==(j-1)+c.length-1>s.length)return -1;//超出了返回-1
        if(s.cn[i]==c.cn[j]){i++;j++;}
        else if(j==1){i++;}//子串首字符与i不匹配，i挪
        else//子串后续字符与i不匹配，子串挪一位
        {
            j--;//失配
            while(j>1&&i-(j-1)+c.length-1<=s.length)
            {
                int check=2;
                for(int jj=1,ii=i-j+1;jj<j&&ii<i;jj++,ii++)
                {
                    if(s.cn[ii]!=c.cn[jj]){check=3;break;}
                }
                if(check==2)break;
                j=j-1;//子串挪一格
            }
        }
        if(j>c.length)return i-(j-1);else return -1;
    }
}
//---------------------------------------------------------------------------------
vector<int> getnext(sstring c)
{
    vector<int>nxt(c.length+2,0);//
    nxt[1]=0;nxt[2]=1;
    for(int j=3;j<=c.length;j++)
    {
        int best=0;
        for(int len=j-2;len>=1;len--)//前后缀长度
        {
            int check=2;
            int head=1,tail=j-1;
            deque<char>head0,tail0;
            for(int x=head;x<=len;x++)
            {
                head0.push_back(c.cn[x]);
            }
             for(int x=tail;x>=(j-1)-len+1;x--)
            {
                tail0.push_front(c.cn[x]);
            }
            if(head0!=tail0)check=3;
            if(check==2){best=len;break;}
        }
        nxt[j]=1+best;
    }
    return nxt;
}
//-------------------------------------------------------------------------
int KMP(sstring s,sstring c)
{
    vector<int>nxt=getnext(c);
    int i=1,j=1;
    while(i-j+1+c.length-1<=s.length&&j<=c.length)
    {
        if(s.cn[i]==c.cn[j]){i++;j++;}
        else if(s.cn[i]!=c.cn[j]&&j>1){j=nxt[j];}
        else if(s.cn[i]!=c.cn[j]&&j==1){i++;}
    }
    return j>c.length?i-j+1:-1;
}
//----------------------------------------------------------------------
int main()
{
    sstring s,c;
    cin>>&s.cn[1];
    cin>>&c.cn[1];
    s.length=strlen(s.cn+1);
    c.length=strlen(c.cn+1);
    int i=KMP(s,c);
    cout<<i;
}
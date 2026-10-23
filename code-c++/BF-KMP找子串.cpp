#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 50
typedef struct
{
    char cn[MAXSIZE+2];//[0]不用，用[1]-[50]
    int length;
}SString;//顺序
//----------------------------BF-------------------------------------
int BFsubstring(SString s,SString c)
{
    int i=1,j=1;
    while(true)
    {
        if(s.cn[i]==c.cn[j])
        {
            i++;j++;
        }
        else
        {
            i=i-(j-1)+1;
            j=1;
            //j是1基,j=移动的次数+1,i应该等于i-移动的次数+1
        }
        if(j>c.length)return i-(j-1);
        if(i-(j-1)+c.length-1>s.length)return -1;
    }
}
//--------------------------next---------------------------------------------------------
vector<int> getNext(SString c)//引用直接改子串，加next数组进去
{
    vector<int>nxt(c.length+2,0);//下标0不用，要往后加一个格子,因此c.length个元素
    //要用1-c.length的格子，c.length+1为了防止匹配成功后崩溃
    nxt[1]=0;nxt[2]=1;
    for(int j=3;j<=c.length;j++)
    {
        int best=0;
        for(int len=(j-1)-1;len>=1;len--)//例如j=6,前面字符串有5个数,5=j-1,前后缀长度<字符串长度,=(j-1)-1
        {
            bool ok=true;
            for(int k=1;k<=len;k++)//k是前缀指针
            {
                if(c.cn[k]!=c.cn[(j-len)+(k-1)])
                //c[12345] 的尾，j指到5,长度 len=2，终点是 4
                //起点 = 4 - 2 + 1 = 3 = j - len
                //k-1=偏移长度,k=1时还是ababd(j指到d)k->a,未偏移
                {ok=false;break;}
            }
            if(ok==true){best=len;break;}
        }
        nxt[j]=best+1;
    } 
    return nxt;

}
//--------------------------KMP------------------------------
int KMPsubstring(SString s,SString c)
{
    vector<int>nxt=getNext(c);
    int i=1,j=1;
    while((i-(j-1)+c.length-1<=s.length)&&j<=c.length)
    {
        if(s.cn[i]==c.cn[j]){i++;j++;}
        else if(j>1)j=nxt[j];//不等且第一位匹配成功
        else i++;//不等且第一位匹配失败;
    }
    return j==c.length+1?i-j+1:-1;
    //i=起点+(c.length-1){i起点和j起点重叠因此-1}+1(又往后诺了一位)
    //j=c.length+1;
    //返回：判断是否全部匹配成功，
}
//-----------------------main---------------------------------
int main()
{
    SString s,c;
    cin>>&s.cn[1]>>&c.cn[1];
    s.length=strlen(s.cn+1);
    c.length=strlen(c.cn+1);
    cout<<BFsubstring(s,c)<<'\n';
    cout<<KMPsubstring(s,c)<<'\n';
}
//BF->O(s.length * c.length)
//KMP->O()
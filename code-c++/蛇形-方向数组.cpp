#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[12][12];
    int dr[4]={0,1,0,-1},dc[4]={1,0,-1,0};
    int j=0,cnt=0;
    a[1][1]=1;int r=1,c=1;
    for(int i=2;i<=n*n;i++)
    {
        if(r+dr[j]>4||c+dc[j]>4){j++;j%=4;}
        r=r+dr[j];c=c+dc[j];
        a[r][c]=i;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
        printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    
}
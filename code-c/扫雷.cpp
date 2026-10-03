#include <stdio.h>
int main() {
int n,m;
scanf("%d %d",&n,&m);
char a[n+2][m+2];        // ← 雷区是字符，必须用 char
int i=0,j=0;
while(i<=n+1)
{
a[i][0]=0;
a[i][m+1]=0;             // ← 补上 =0（左上一步就是漏了这个等号）
i++;
}
while(j<=m+1)
{
a[0][j]=0;
a[n+1][j]=0;
j++;
}
for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
{
scanf(" %c",&a[i][j]);   // ← %c 读字符，前面的空格用来跳过换行
}
}
int cnt=0;
for(i=1;i<=n;i++)        // ← 边界收到 n（原来 i<=n+2 会踩出数组外）
{
for(j=1;j<=m;j++)        // ← 边界收到 m
{
if(a[i][j]=='.')
{
if(a[i-1][j-1]=='*')
{
cnt++;
}
if(a[i-1][j+1]=='*')
{
cnt++;
}
if(a[i+1][j-1]=='*')
{
cnt++;
}
if(a[i+1][j+1]=='*')
{
cnt++;
}
if(a[i][j-1]=='*')
{
cnt++;
}
if(a[i][j+1]=='*')
{
cnt++;
}
if(a[i-1][j]=='*')
{
cnt++;
}
if(a[i+1][j]=='*')
{
cnt++;
}
a[i][j]=cnt;
cnt=0;
}
}
}
for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
{
if(a[i][j]=='*')     // ← 雷还是 '*'，不能当数字打
{
printf("*");
}
else
{
printf("%d",a[i][j]);
}
if(j<m)
{
printf(" ");
}
if(j==m)
{
printf("\n");
}
}
}
return 0;
}

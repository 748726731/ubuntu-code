#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 50
struct sqlist
{
    int data[MAXSIZE];
    int length;
};
int main()
{
    sqlist a;
    cin>>a.length;
    for(int i=0;i<a.length;i++)
    {
        cin>>a.data[i];
    }
    
}
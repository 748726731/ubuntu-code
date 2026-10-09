#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>students;
    vector<int>sandwiches;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        students.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        sandwiches.push_back(a);
    }
    queue<int>studentQueue;//学生队列
    for(int s:students){studentQueue.push(s);}
    //such as students=1 0 0 1
    //first s=1 second s=0 third s=0 last s=1;
    int fail=0;//失败计数器
    int i=0;//三明治下标
   while(studentQueue.empty()==0&&fail<=(int)studentQueue.size())
   {
    if(studentQueue.front()==sandwiches[i])
    {fail=0;studentQueue.pop();i++;}
    else{fail++;studentQueue.push(studentQueue.front());studentQueue.pop();}
   }
   cout<<studentQueue.size();
    return 0;
}
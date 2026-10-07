#include<bits/stdc++.h>
#include <iterator>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int n1;cin>>n1;
        vector<int>datebaseIn;
        for(int j=0;j<n1;j++)
        {
            int date;cin>>date;
            datebaseIn.push_back(date);
        }
        int LongIn=datebaseIn.size();
        vector<int>datebaseOut;
        for(int j=0;j<n1;j++)
        {
            int date;cin>>date;
            datebaseOut.push_back(date);
        }
        int LongOut=datebaseOut.size();
        stack<int>in;
        for(int k=0,j=0;k<LongOut||in.empty()==0;)
        {
            if(k<LongOut&&(in.empty()==1||in.top()!=datebaseOut[j]))//栈顶不是想要的,且只压五次进栈
            {
                in.push(datebaseIn[k]);
                k++;
            }
            else if(in.empty()==0&&in.top()==datebaseOut[j])//栈顶是想要的,不要求k<LongOut
            {
                in.pop();
                j++;
            }
            else break;
        }
        cout<<(in.empty()==1?"Yes":"No")<<endl;
    }
}
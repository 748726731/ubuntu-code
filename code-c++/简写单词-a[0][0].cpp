#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
string word;
vector<string>a;  
while(cin>>word)
{
    a.push_back(word);
    if(cin.get()=='\n')
    {
    	break;
	}
}
for(auto p=a.begin();p!=a.end();p++)
{
    char c=(*p)[0];//a[0][0]!!!!!!假设第一个单词为Bob，a[0]=Bob,a[0][0]=B
    if(c >= 'a' && c <= 'z')
    {
        c=c-'a'+'A';//c参与运算后就是int了
        
    }
    cout<<c<<" ";
}
return 0;
}


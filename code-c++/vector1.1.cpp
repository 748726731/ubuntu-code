#include<iostream>
using namespace std;
#include<vector>
int main(void)
{
	vector<int>v;
	v.resize(20);//==vector<int>v(10)==vector<int>v(10,0)
	v.push_back(1);
	for(auto p=v.begin();p!=v.end();p++)
	{
		cout<<*p;
	}
	return 0;
 } 

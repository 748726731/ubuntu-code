#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
	vector<int>v(10);
	v.push_back(11);
	for(auto p=v.begin();p!=v.end();p++)
	cout<<*p<<" ";
	return 0;
 } 

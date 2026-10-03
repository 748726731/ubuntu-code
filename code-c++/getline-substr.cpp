#include<iostream>
using namespace std;
int main(void)
{
	string s1="hello world";
	string s1_sub1=s1.substr(5);
	string s1_sub2=s1.substr(2,2);
	cout<<s1<<endl<<s1.length()<<s1_sub1<<s1_sub2;
	return 0;
}

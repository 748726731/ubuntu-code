#include<iostream>
using namespace std;
void hanshu1(int &a)
{
	a++;
}
int main()
{
	int a;
	cin>>a;
	hanshu1(a);
	cout<<a;
	return 0;
}

#include<iostream>
using namespace std;
struct student{
	string name;
	int age;
};
int main()
{
	student a[2];
	for(int i=0;i<2;i++)
	{
		cin>>a[i].name>>a[i].age;
	}
	for(int i=0;i<2;i++)
	{
		cout<<a[i].name<<" "<<a[i].age;
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
struct student{
	char name[20];
	int age;
};
int main(void)
{
	struct student a;
	struct student b;
	strcpy(a.name,"张三");
	a.age=18;
	strcpy(b.name,"陈俊熙");
	b.age=22;
	printf("%s %d\n%s %d",a.name,a.age,b.name,b.age);
	return 0;
 } 

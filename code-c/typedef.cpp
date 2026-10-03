#include<stdio.h>
#include<string.h>
typedef struct{
	char name[20];
	int age;
}profile;
int main()
{
	profile a;
	scanf("%s %d",a.name,&a.age);
	char b[100];
	snprintf(b,sizeof(b),"%s is %d sui",a.name,a.age);
	printf("%s",b);
	return 0;
}

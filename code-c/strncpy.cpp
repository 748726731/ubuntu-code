#include<stdio.h>
#include<string.h>
struct qq
{
char account[20];
char password[20];
char name[13];	
 }; 
 int main()
 {
 	struct qq a;
 	char a1[20],a2[20],b1[20],b2[20];
 	char a3[13],b3[13];
 	scanf("%s %s %s",a1,a2,a3);
 	snprintf(a.account,sizeof(a.account),"%s",a1);
 	a.account[19]='\0';
 	snprintf(a.password,sizeof(a.password),"%s",a2);
 	a.password[19]='\0';
 	snprintf(a.name,sizeof(a.name),"%s",a3);
 	a.name[12]='\0';
 	printf("%s %s %s",a.account,a.password,a.name);
 	struct qq b;
 	scanf("%s %s %s",b1,b2,b3);
 	strncpy(b.account,b1,19);
 	b.account[19]='\0';
 	strncpy(b.password,b2,19);
 	b.password[19]='\0';
 	strncpy(b.name,b3,12);
 	b.name[12]='\0';
 	printf("%s %s %s",b.account,b.password,b.name);
 	return 0;
 	
 }

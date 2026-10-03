#include<stdio.h>
int check_primer(int num)
{
	int b;//除数 
	for(b=2;b<num;b++)
	{
						
		if(num%b==0)
		{
		return 3;
		}
	}
	return 2;
}
int main()
{
	int is_primer;
	int count=0;
	int a;
	for(a=2;count<30;a++)
	{
		is_primer=check_primer(a);
		if(is_primer==2)
		{
			count++;
			printf("%d\n",a);
		}
	}
	return 0;
 } 

#include<stdio.h>
int main()
{
	int a;
	int b;
	int check;
	for(a=2;a<100;a++)
	{
	check=1;
		for(b=2;b<a;b++)
		{
			if(a%b==0)
			{
				check=2;
				break;
			}
		}
	
		if(check==1)
		{
			printf("%d\n",a);
		}

}
	return 0;
}
	

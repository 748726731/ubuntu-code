#include<stdio.h>
int main()
{
	int a;
	int b;
	int check=1;
	scanf("%d",&a);
	for(b=2;b<a;b++)
	{
		if(a%b==0)
		{
			check=2;
			break;
		}
	}
	switch(check){
	
	case 1:
		printf("是素数");
		break;
	case 2:
	printf("不是素数"); 
	break;}

return 0;
}

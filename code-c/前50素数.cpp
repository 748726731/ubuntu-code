#include<stdio.h>
int main()
{
	int is_primer=1;//工具数 
	int y=2;//除数 
	int x=2;//素数 
	int a;//1-50个素数 
	for (a=0;a<50;x++)
	{
		is_primer=1;
		for(y=2;y<x;y++)
		{
			if(x%y==0)
			{
				is_primer=2;
				break;
			}
		}
		if(is_primer==1)
		{
			printf("%d\n",x);
			a++;
		
		}
	}
	return 0;
}

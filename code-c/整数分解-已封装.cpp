#include<stdio.h>
	int hanshu1(int f)
	{
		int d=0;
		while(f>0)
		{
		f/=10;// 										找有几位数 
		d++;
		}
			int a=1;
			for(;d>1;)
			{
			a*=10;//						根据有几位数，来改变除数 
			d--;
			}
			return a;
	
	}
									int hanshu2(int a,int d)
									{
								
										for(a=1;d>1;)
										{
										a*=10;//						根据有几位数，来改变除数 
										d--;
										}
										return a;
									}
void hanshu3(int a,int b)
{
	int c;
	do
	{
		c=b/a;
		printf("%d",c);
		if(a>9)
		{
			printf(" ");  //						输出 
		}
		b%=a;
		a/=10;
	} 
		 while(a>0);
}

int main() 
{
	int a;//
	int b;//实际数
	scanf("%d",&b);
	int f=b;//工具数-复制实际数 

	a=hanshu1(f);//得除数 
	hanshu3(a,b);
	return 0;
}

 

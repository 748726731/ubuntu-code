#include<stdio.h>
int isPrime(int i,int prime[],int count)//判断是否为素数 
{
	int ret=3;
	int k;
	for(k=0;k<count;k++)
	{
	if(i%prime[k]==0)
		{
		ret=2;
		}
	}
	return ret;		
}
void printf1(int number,int prime[])
{
	int p=0;//从prime0开始把数组0-100输出出去 
	for(p=0;p<number;p++)
	{
		printf("%d\n",prime[p]);
	}
}

int main()
{
	int number=100;
	 int prime[number]={2};//来个100数组， 
	int count=1;//数组从prime1开始 
	int i=3;//从3开始测试是否为素数 
	while(count<number)
	{
		if(isPrime(i,prime,count)==3)//如果是素数，就放到prime数组里 
		{
			prime[count]=i;
			count++;
		}
		i++;
	}
	printf1(number,prime);
	return 0; 
}

#include<stdio.h>
int main()
{
	int group[10];
	int i;
	for(i=0;i<10;i++)
	{
		group[i]=0;
	}
	scanf("%d",&i);
	while(i!=-1)
	{
		if(i>=0&&i<=9)
		{
			group[i]++;
		}
		scanf("%d",&i);
	}
	for(i=0;i<=9;i++)
	{
		printf("%d\n",group[i]);
	}
	return 0;
}

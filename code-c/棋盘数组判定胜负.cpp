#include<stdio.h>
int check1(int board[][3],int size)
{
	int i,j,X1,X2,O1,O2,result=-1;
	for(i=0;i<size&&result==-1;i++)
	{
		X1=0;
		X2=0;
		O1=0;
		O2=0;
		for(j=0;j<size&&result==-1;j++)
		{
			if(board[i][j]==1)
			X1++;
			else if(board[i][j]==2)
			O1++;
			if(board[j][i]==1)
			X2++;
			else if(board[j][i]==2)
			O2++;
		}
		if(X1==3)
			{
				result=1;
				return 1;
			}
		else if(X2==3)
		{
			result=1;
			return 1;
		}
		else if(O1==3)
			{
				result=2;
				return 2;
			}
			else if(O2==3)
			{
				result=2;
				return 2;
			}
	}
	return -1;
}
int check2(int board[][3],int size)
{
	int i,result;
	int X1,X2,O1,O2;
	X1=X2=O1=O2=0;
	for(i=0;i<size;i++)
	{
		if(board[i][i]==1)
		{
			X1++;
		}
		else if(board[i][i]==2)
		{
			O1++;
		}
	 if(board[i][size-1-i]==1)
		{
			X2++;
		}
		else if(board[i][size-1-i]==2)
		{
			O2++;
		}
		if(X1==3||X2==3)
		{
			result=1;
			return 1;
		}
		else if(O1==3||O2==3)
		{
			result=2;
			return 2;
		}
	}
	result=-1;
	return result;
	} 
	
int main()
{
	int size=3;
	int board[3][3];
	int i,j;
	int X;
	int O;
	int result=-1;//-1 无人赢。1：Xwin。2：Owin。
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		scanf("%d",&board[i][j]);
	}
	result=check1(board,size);
	if(result==-1)
	{
		result=check2(board,size);
	}
	printf("%d",result);
	 return 0;
}

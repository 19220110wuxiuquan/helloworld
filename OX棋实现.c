#include<stdio.h>
int main()
{
	const int size=3;
	int board[size][size];
	int i,j;
	int numofx,numofo;
	int result=-1;//-1表示没人赢，1表示X赢，0表示O赢· 
	//读入矩阵	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			scanf("%d",&board[i][j]);
		}
	}
	//检查行 
	for(i=0;i<size&&result==-1;i++)
	{
		numofo=numofx=0;
		for(j=0;j<size;j++)
		{
			if(board[i][j]==1)
			{
				numofx++;
			}
			else
			{
				numofo++;
			}
		}
		if(numofo==size)
		{
			result=0;
		}
		else if(numofx==size)
		{
			result=1;
		}
	 } 
	 //检查列
	 if(result==-1)
	 for(j=0;j<size&&result==-1;j++)
	 {
	 	numofo=numofx=0;
	 	for(i=0;i<size;i++)
	 	{
	 		if(board[i][j]==1)
	 		{
	 			numofx++;
			}
			else
			{
				numofo++;
			}
		}
		if(numofo==size)
		{
			result=0;
		}
		else if(numofx==size)
		{
			result=1;
		}
	} 
	//检查对角线
	numofo=numofx=0;
	for(i=0;i<size;i++)
	{
		if(board[i][i]==1)
		{
			numofx++;
		}
		else
		{
			numofo++;
		}
	 } 
	 if(numofo==size)
	 {
	 	result=0;
	 }
	 else if(numofx==size)
	 {
	 	result=1;
	 }
	 numofo=numofx=0;
	 for(i=0;i<size;i++)
	 {
	 	if(board[i][size-i-1]==1)
	 	{
	 		numofx++;
		}
		else
		{
			numofo++;
		}
	 }
	printf("%d",result);
	return 0;
 } 

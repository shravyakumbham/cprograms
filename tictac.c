#include<stdio.h>
#include<stdlib.h>
void print();
int arr[3][3]={'*','*','*','*','*','*','*','*','*'};
int i,j;
int main()
{
	int res,count=0,index;
	char row1,col1;
	int row=0,col=0;

	while(1)
	{
		printf("player1 : X and player 2 : O\n");

		for(index=0;index<9;index++)
		{
			res = index%2;

			if(res==0)
				printf("Player1 enter row and col\n");
			else
				printf("Player2 enter row and col\n");
//			fflush(stdin);
			scanf(" %c %c",&row1,&col1);
			row = row1-48;
			col = col1-48;

			if(row<3 && col<3)
			{
				if(arr[row][col]=='*')
				{

					switch(res)
					{
						case 0 : count++;
							 arr[row][col]='X';
							 print();
							 break;

						case 1 : count++;
							 arr[row][col]='O';
							 print();
							 break;
						
					}

				}
				else
				{
					printf("The row and col you entered is already filled\n");
					index--;
				}
			}
			else
			{
				printf("Please enter in limit\n");
				index--;
			}

			if(count>=5)
			{
				row=0,col=0;
				if(arr[row][col]!='*' && arr[++row][++col]!='*' && arr[++row][++col]!='*')
				{
					row=0,col=0;
					if(arr[row][col]==arr[++row][++col] && arr[row][col]==arr[++row][++col])
					{
						if(res==0)
						{
							printf("player1 won the game\n");
							exit(0);
						}
						else
						{
							printf("player2 won the game\n");
							exit(0);
						}
					}
				}
				row=0,col=2;
				if(arr[row][col]!='*' && arr[++row][--col]!='*' && arr[++row][--col]!='*')
				{
					row=0,col=2;

					if(arr[row][col]==arr[++row][--col] && arr[row][col] == arr[++row][--col])
					{
						if(res==0)
						{
							printf("player1 won the game\n");
							exit(0);
						}
						else
						{
							printf("player2 won the game\n");
							exit(0);
						}
					}
				}

				row=0,col=0;

				while(row<3)
				{
					if(arr[row][col]!='*')
					{
						if(arr[row][col]==arr[row][++col] && arr[row][col]==arr[row][++col])
						{
							if(res==0)
							{
								printf("player1 won the game\n");
								exit(0);
							}
							else
							{
								printf("player2 won the game\n");
								exit(0);
							}
						}
					}
					row++;
					col=0;
				}

				row=0,col=0;
				while(col<3)
				{
					if(arr[row][col]!='*')
					{
						if(arr[row][col]==arr[++row][col] && arr[row][col]==arr[++row][col])
						{
							if(res==0)
							{
								printf("player1 won the game\n");
								exit(0);
							}
							else
							{
								printf("player2 won the game\n");
								exit(0);
							}

						}
					}
					col++;
					row=0;
				}
			}
		}
	}	

	printf("The game is tie\n");

}

void print()
{	
	system("clear");
	for(i=0;i<3;i++)
	{
		printf("\t\t\t");
		for(j=0;j<3;j++)
			printf("%c ",arr[i][j]);
		printf("\n");
	}
}

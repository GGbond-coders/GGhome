#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)//以空格填充二维数组
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}

void DisplayBoard(char board[ROW][COL], int row, int col)//打印棋盘
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印1、3、5行（棋子所在行）
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");

		}
		printf("\n");
		if (i < row - 1)//打印分隔行
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void playermove(char board[ROW][COL], int row, int col)//玩家下棋
{
	int x = 0;
	int y = 0;
	printf("玩家下棋>\n");
	while (1)
	{
		printf("请输入坐标>\n");
		scanf("%d,%d", &x, &y);//接收玩家下棋的位置
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断位置是否合法
		{
			
			if (board[x - 1][y - 1] == ' ')//判断所下位置是否被占用
			{
				board[x - 1][y - 1] = '*';//将玩家所下棋的数组位置上的空格改为*号
				break;
			}
			else
			{
				printf("坐标被占用，不能下棋，请选择其他位置");
			}
		}
		else
		{
			printf("坐标非法，请重新输入：\n");
		}
	}
}

void computermove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;//生成随机数坐标0、1、2
		y = rand() % col;
		if (board[x][y] == ' ')//将玩家所下棋的数组位置上的空格改为#号
		{
			board[x][y] = '#';
			break;
		}
	}
	
}

int isfull(char board[ROW][COL], int row, int col)//判断棋盘是否下满
	{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
	}
char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][1];
		}
	}
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1]&&board[0][0] !=' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]&&board[1][1] !=' ')
	{
		return board[1][1];
	}
	if (isfull(board, row, col))
	{
		return 'Q';
	}
	return 'c';
}
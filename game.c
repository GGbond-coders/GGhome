#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)//�Կո�����ά����
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

void DisplayBoard(char board[ROW][COL], int row, int col)//��ӡ����
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//��ӡ1��3��5�У����������У�
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");

		}
		printf("\n");
		if (i < row - 1)//��ӡ�ָ���
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
void playermove(char board[ROW][COL], int row, int col)//�������
{
	int x = 0;
	int y = 0;
	printf("�������>\n");
	while (1)
	{
		printf("����������>\n");
		scanf("%d,%d", &x, &y);//������������λ��
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж�λ���Ƿ�Ϸ�
		{
			
			if (board[x - 1][y - 1] == ' ')//�ж�����λ���Ƿ�ռ��
			{
				board[x - 1][y - 1] = '*';//����������������λ���ϵĿո��Ϊ*��
				break;
			}
			else
			{
				printf("���걻ռ�ã��������壬��ѡ������λ��");
			}
		}
		else
		{
			printf("����Ƿ������������룺\n");
		}
	}
}

void computermove(char board[ROW][COL], int row, int col)
{
	printf("��������>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;//�������������0��1��2
		y = rand() % col;
		if (board[x][y] == ' ')//����������������λ���ϵĿո��Ϊ#��
		{
			board[x][y] = '#';
			break;
		}
	}
	
}

int isfull(char board[ROW][COL], int row, int col)//�ж������Ƿ�����
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
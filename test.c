#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//打印菜单
menu()
{
	printf("*************************\n");
	printf("******1.play 0.exit******\n");
	printf("*************************\n");
}


void game()
{
	char ret = 'c';
	char board[ROW][COL] = { 0 };//生成二维数组，打印棋盘
	InitBoard(board, ROW, COL);//以空格填充二维数组
	DisplayBoard(board, ROW, COL);//打印棋盘
	while (ret == 'c')//游戏开始
	{
		playermove(board,ROW,COL);//玩家下棋
		ret = iswin(board, ROW, COL);//判断输赢
		if (ret != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);//打印棋盘
		computermove(board, ROW, COL);//电脑下棋
		ret = iswin(board, ROW, COL);//判断输赢
		
		if (ret != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);//打印棋盘

	}
	if (ret == '*')//显示谁输谁赢或平局
	{
		printf("玩家赢。\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢。\n");
	}
	else
	{
		printf("平局。\n");
	}
	DisplayBoard(board, ROW, COL);//打印棋盘
}


//主函数
int main()
{
	//设置随机数种子
	srand((unsigned int)time(NULL));
	//玩家选择是否进入游戏
	int input = 0;
	do
	{

		menu();//菜单
		printf("请选择：");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				//进入游戏
				game();
				break;
			case 0:
				printf("退出游戏。\n");
				break;
			default:
				printf("选择错误，请重新选择：\n");
				break;
		
		
		}
	} while (1>2);
	return 0;
}
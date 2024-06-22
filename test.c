#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//��ӡ�˵�
menu()
{
	printf("*************************\n");
	printf("******1.play 0.exit******\n");
	printf("*************************\n");
}


void game()
{
	char ret = 'c';
	char board[ROW][COL] = { 0 };//���ɶ�ά���飬��ӡ����
	InitBoard(board, ROW, COL);//�Կո�����ά����
	DisplayBoard(board, ROW, COL);//��ӡ����
	while (ret == 'c')//��Ϸ��ʼ
	{
		playermove(board,ROW,COL);//�������
		ret = iswin(board, ROW, COL);//�ж���Ӯ
		if (ret != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);//��ӡ����
		computermove(board, ROW, COL);//��������
		ret = iswin(board, ROW, COL);//�ж���Ӯ
		
		if (ret != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);//��ӡ����

	}
	if (ret == '*')//��ʾ˭��˭Ӯ��ƽ��
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ�֡�\n");
	}
	DisplayBoard(board, ROW, COL);//��ӡ����
}


//������
int main()
{
	//�������������
	srand((unsigned int)time(NULL));
	//���ѡ���Ƿ������Ϸ
	int input = 0;
	do
	{

		menu();//�˵�
		printf("��ѡ��");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				//������Ϸ
				game();
				break;
			case 0:
				printf("�˳���Ϸ��\n");
				break;
			default:
				printf("ѡ�����������ѡ��\n");
				break;
		
		
		}
	} while (1>2);
	return 0;
}
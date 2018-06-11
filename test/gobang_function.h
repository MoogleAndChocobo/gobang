#ifndef GOBANG_FUNTION_H_
#define GOBANG_FUNTION_H_

#include <cstdio>
#include <cstring>
#include "gobang_class.h"

// 构造函数
Chess::Chess()
{
	memset(map_, 0, sizeof(map_));
}

// 棋盘初始化
void Chess::Init()
{
	memset(map_, 0, sizeof(map_));
}	

// 打印菜单
void Chess::ShowMenu()
{
	puts(MENU_LINE);

	printf("%s\n", "             五子棋游戏");
	puts("");
	printf("%s\n", "         请选择一个模式以继续");
	puts("");
	printf("%s\n", "          1.Person to Person");
	printf("%s\n", "         2.Person to Computer");

	puts("");
	puts(MENU_LINE);
}

// 模式选择
void Chess::Select(bool flag)
{
	Init();
	if(flag)
		ShowMenu();

	printf("MODE--> ");
	int choice;
	scanf("%d", &choice);
	puts("");

	if (choice == 1)
	{
		PersonToPerson();
	}
	else if (choice == 2)
	{
		PersonToComputer();
	}
	else
	{
		printf("请选择正确的模式以继续\n\n");
		Select(false);
	}
}

// 打印棋盘
void Chess::ShowMap()
{
	printf("   ");
	for (int i = 0; i < kMapMax; ++i)
	{
		printf("%02d ", i + 1);
	}
	puts("");
	puts(LINE);
	for (int i = 0; i < kMapMax; ++i)
	{
		printf("%02d|", i + 1);
		for (int j = 0; j < kMapMax; ++j)
		{
			switch (map_[i][j])
			{
				case 0: printf(" %c|", kNone); break;
				case 1: printf(" %c|", kFirst); break;
				case 2: printf(" %c|", kSecond); break;
			}
		}
		puts("");
		puts(LINE);
	}
	puts("");
}

// Mode Person to Person实现
void Chess::PersonToPerson()
{
	ShowMap();
	int order = 2;
	while (true)
	{
		order = order == 2 ? 1 : 2;
		SetValue(order, true);
		ShowMap();
		int ans = CheckResult();
		if (ans == 1)
		{
			puts("先手胜利");
			break;
		}
		else if (ans == 2)
		{
			puts("后手胜利");
			break;
		}
		else if (ans == -1)
		{
			puts("平局");
			break;
		}
	}
}

// Mode Person to Computer实现
void Chess::PersonToComputer()
{
	ShowMap();
	int order = 2;
	while (true)
	{
		order = order == 2 ? 1 : 2;
		if (order == 1)
		{
			SetValue(order, false);
			ShowMap();
		}
		else
		{
			ComputerSetValue();
		}
		int ans = CheckResult();
		if (ans == 1)
		{
			puts("先手胜利\n");
			break;
		}
		else if (ans == 2)
		{
			puts("后手胜利\n");
			break;
		}
		else if (ans == -1)
		{
			puts("平局\n");
			break;
		}
	}
}

// Mode Person to Computer下自动生成落子位置
void Chess::ComputerSetValue()
{
	GenerateNeighbor();


}

// 标记所有邻近棋子
void Chess::GenerateNeighbor()
{
	memset(is_neighbor_, 0, sizeof(is_neighbor_));

	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			is_neighbor_[i][j] = HasNeighbor(i, j);
		}
	}
}

// 判断是否是邻近棋子
bool Chess::HasNeighbor(int x, int y)
{
	if (map_[x][y])
		return false;
	for (int i = 0; i < kNeighborDirTimes; ++i)
	{
		int dx = x + kNeighborDir[i][0];
		int dy = y + kNeighborDir[i][1];
		if (IsInMap(dx, dy) && map_[dx][dy])
		{
			return true;
		}
	}
	return false;
}

// 玩家落子
void Chess::SetValue(int color, bool flag)
{
	if (flag)
		printf("请输入P%d落子坐标：", color);
	else
		printf("请输入你的落子坐标： ");
	int x, y;
	scanf("%d%d", &x, &y);
	puts("");
	if (map_[x - 1][y - 1])
	{
		puts("该位置已有棋子, 不能在此位置落子, 请重新选择落子位置。");
		puts("");
		SetValue(color, true);
	}
	else
	{
		map_[x - 1][y - 1] = color;
	}
}

// 判断是否构成比赛结束条件
int Chess::CheckResult()
{
	bool flag = false;
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if (checkPer(i, j, 1, k)) return 1;
				if (checkPer(i, j, 2, k)) return 2;
				if (!map_[i][j]) flag = true;
			}
		}
	}
	if (!flag)
		return -1;
	return 0;
}

// 判断单一位置上是否构成比赛结束条件
bool Chess::checkPer(int x, int y, int val, int order)
{
	int mx = kWinCount;
	while (mx--)
	{
		if (!(IsInMap(x, y) && map_[x][y] == val))
			return false;
		x += kDir[order][0];
		y += kDir[order][1];
	}
	return true;
}

// 判断是否存在于棋盘中
bool Chess::IsInMap(int x, int y)
{
	return (x >= 0 && x < kMapMax && y >= 0 && y < kMapMax);
}

#endif
 

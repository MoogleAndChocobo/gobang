#ifndef FUNTION_H_
#define FUNTION_H_

#include <cstdio>
#include <cstring>
#include <vector>
#include <ctime>
#include "scores.h"

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
	if (flag)
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
	int order = 2;
	while (true)
	{
		order = order == 2 ? 1 : 2;
		if (order == 1)
		{
			ShowMap();
			SetValue(order, false);
			ShowMap();
		}
		else
		{
			ComputerSetValue(order);
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

// 对玩家当前棋局进行评估
bool Chess::HinderPlayer(int color)
{

	return false;
}

// Mode Person to Computer下自动生成落子位置
void Chess::ComputerSetValue(int color)
{
	GenerateNeighbor();

	if (HinderPlayer(color))
		return;

	memset(score_, 0, sizeof(score_));
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			if (is_neighbor_[i][j])
			{
				map_[i][j] = color;
				score_[i][j] = Calculate(i, j, color);
				map_[i][j] = 0;
			}
		}
	}

	struct Point
	{
		int x, y;
		Point(int xx = 0, int yy = 0) :x(xx), y(yy){}
	};

	std::vector<Point> vec;
	int mx = -10;
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			if (score_[i][j] > mx)
			{
				vec.clear();
				vec.push_back(Point(i, j));
				mx = score_[i][j];
			}
			else if (score_[i][j] == mx)
			{
				vec.push_back(Point(i, j));
			}
		}
	}

	int num = vec.size();
	srand(unsigned(time(NULL)));
	num = rand() % num;
	map_[vec[num].x][vec[num].y] = color;
}

//对当前位置的自身棋局进行评估
int Chess::Calculate(int x, int y, int color)
{
	if (Score100(color))
		return 100;
	else if (Score90(color))
		return 90;
	else if (Score80(color))
		return 80;
	else if (Score70(color))
		return 70;
	else if (Score60(color))
		return 60;
	else if (Score50(color))
		return 50;
	else if (Score40(color))
		return 40;
	else if (Score30(color))
		return 30;
	else if (Score20(color))
		return 20;
	else if (Score10(color))
		return 10;
	else if (Score00(color))
		return 0;
	else
		return -10;
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
				if (checkPer(i, j, 1, k, 5)) return 1;
				if (checkPer(i, j, 2, k, 5)) return 2;
				if (!map_[i][j]) flag = true;
			}
		}
	}
	if (!flag)
		return -1;
	return 0;
}

// 判断单一位置上是否构成比赛结束条件
bool Chess::checkPer(int x, int y, int val, int order, const int CheckCount)
{
	int mx = CheckCount;
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

int Chess::ReverseColor(int color)
{
	return color == 2 ? 1 : 2;
}

#endif

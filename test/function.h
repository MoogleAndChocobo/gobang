#ifndef HOME_MOOGLE_PRORAMMING_SOURCE_GOBANG_FUNTION_H_
#define HOME_MOOGLE_PRORAMMING_SOURCE_GOBANG_FUNTION_H_

#include <cstdio>
#include <cstring>
#include "class.h"

Chess::Chess()
{
	memset(map_, 0, sizeof(map_));
}

void Chess::ShowMap()
{
	printf("   ");
	for (int i = 0; i < kPicMax; ++i)
		printf("%02d ", i + 1);
	putchar('\n');
	
	for (int i = 0; i < kPicMax; ++i)
	{
		printf("%02d ", i + 1);
		for (int j = 0; j < kPicMax; ++j)
		{
			switch(map_[i][j])
			{
				case 0: printf(" %c ", kNone); break;
				case 1: printf(" %c ", kFirst); break;
				case 2: printf(" %c ", kSecond); break;
			}
		}
		putchar('\n');
	}
}

void Chess::SetValue()
{
	printf("%s", INPUT_CHESSMAN);
	int x, y, n;
	scanf("%d%d%d", &x, &y, &n);
	if(map_[x - 1][y - 1])
	{
		printf("%s", ALREADY_HAD);
		SetValue();
	}
	else
	{
		map_[x - 1][y - 1] = n;
	}
}

int Chess::CheckResult()
{
	bool flag = false;
	for (int i = 0; i < kPicMax; ++i)
	{
		for (int j = 0; j < kPicMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if(!map_[i][j])
					flag = true;
				if(checkPer(i, j, 1, k))
					return 1;
				if(checkPer(i, j, 2, k))
					return 2;
			}
		}
	}
	if(!flag)
		return -1;
	return 0;
}

bool Chess::checkPer(int x, int y, int val, int order)
{
	int mx = kWinCount;
	while(mx--)
	{
		if(!(IsInPic(x, y) && map_[x][y] == val))
			return false;
		x += kDir[order][0];
		y += kDir[order][1];
	}
	return true;
}

bool Chess::IsInPic(int x, int y)
{
	return (x >= 0 && x < kPicMax && y >= 0 && y < kPicMax);
}

#endif

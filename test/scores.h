#ifndef SCORES_H
#define SCORES_H

#include "gobang.h"

bool Chess::Score100(int color)
{
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if (checkPer(i, j, color, k, 5))
					return true;
			}
		}
	}
	return false;
}

bool Chess::Score90(int color)
{
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if (checkPer(i, j, color, k, 4))
				{
					int dx = i - kDir[k][0], dy = j - kDir[k][1];
					bool fa = IsInMap(dx, dy) && !map_[dx][dy];
					dx += 5 * kDir[k][0], dy += 5 * kDir[k][1];
					bool fb = IsInMap(dx, dy) && !map_[dx][dy];
					if (fa && fb)
						return true;
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if (checkPer(i, j, color, k, 4))
				{
					int dx = i - kDir[k][0], dy = j - kDir[k][1];
					bool fa = IsInMap(dx, dy) && map_[dx][dy] == ReverseColor(color);
					dx += 5 * kDir[k][0], dy += 5 * kDir[k][1];
					bool fb = IsInMap(dx, dy) && map_[dx][dy] == ReverseColor(color);
					if ((fa && !fb) || (!fa && fb))
						cnt++;
					if (cnt == 2)
						return true;
				}
			}
		}
	}

	if (!cnt)
		return false;

	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if (checkPer(i, j, color, k, 3))
				{
					int dx = i - kDir[k][0], dy = j - kDir[k][1];
					bool fa = IsInMap(dx, dy) && !map_[dx][dy];
					dx += 4 * kDir[k][0], dy += 4 * kDir[k][1];
					bool fb = IsInMap(dx, dy) && !map_[dx][dy];
					if (fa && fb)
						return true;
				}
			}
		}
	}

	return false;
}

bool Chess::Score80(int color)
{
	int cnt = 0;
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if (checkPer(i, j, color, k, 3))
				{
					int dx = i - kDir[k][0], dy = j - kDir[k][1];
					bool fa = IsInMap(dx, dy) && !map_[dx][dy];
					dx += 4 * kDir[k][0], dy += 4 * kDir[k][1];
					bool fb = IsInMap(dx, dy) && !map_[dx][dy];
					if (fa && fb)
						cnt++;
					if (cnt == 2)
						return true;
				}
			}
		}
	}
	return false;
}

bool Chess::Score70(int color)
{
	int cnta = 0, cntb = 0;
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if (checkPer(i, j, color, k, 3))
				{
					int dx = i - kDir[k][0], dy = j - kDir[k][1];
					bool fa = IsInMap(dx, dy) && map_[dx][dy] == ReverseColor(color);
					bool ffa = IsInMap(dx, dy) && !map_[dx][dy];
					dx += 4 * kDir[k][0], dy += 4 * kDir[k][1];
					bool fb = IsInMap(dx, dy) && map_[dx][dy] == ReverseColor(color);
					bool ffb = IsInMap(dx, dy) && !map_[dx][dy];
					if (fa || fb)
						cnta++;
					if (ffa && ffb)
						cntb++;
					if (cnta && cntb)
						return true;
				}
			}
		}
	}
	return false;
}

bool Chess::Score60(int color)
{
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if (checkPer(i, j, color, k, 4))
				{
					int dx = i - kDir[k][0], dy = j - kDir[k][1];
					bool fa = IsInMap(dx, dy) && map_[dx][dy] == ReverseColor(color);
					dx += 5 * kDir[k][0], dy += 5 * kDir[k][1];
					bool fb = IsInMap(dx, dy) && map_[dx][dy] == ReverseColor(color);
					if ((fa && !fb) || (!fa && fb))
						return true;
				}
			}
		}
	}
	return false;
}

bool Chess::Score50(int color)
{
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if (checkPer(i, j, color, k, 3))
				{
					int dx = i - kDir[k][0], dy = j - kDir[k][1];
					bool fa = IsInMap(dx, dy) && !map_[dx][dy];
					dx += 4 * kDir[k][0], dy += 4 * kDir[k][1];
					bool fb = IsInMap(dx, dy) && !map_[dx][dy];
					if (fa && fb)
						return true;
				}
			}
		}
	}
	return false;
}

bool Chess::Score40(int color)
{
	int cnt = 0;
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if (checkPer(i, j, color, k, 2))
				{
					int dx = i - kDir[k][0], dy = j - kDir[k][1];
					bool fa = IsInMap(dx, dy) && !map_[dx][dy];
					dx += 3 * kDir[k][0], dy += 3 * kDir[k][1];
					bool fb = IsInMap(dx, dy) && !map_[dx][dy];
					if (fa && fb)
						cnt++;
					if (cnt == 2)
						return true;
				}
			}
		}
	}
	return false;
}

bool Chess::Score30(int color)
{
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if (checkPer(i, j, color, k, 3))
				{
					int dx = i - kDir[k][0], dy = j - kDir[k][1];
					bool fa = IsInMap(dx, dy) && map_[dx][dy] == ReverseColor(color);
					dx += 4 * kDir[k][0], dy += 4 * kDir[k][1];
					bool fb = IsInMap(dx, dy) && map_[dx][dy] == ReverseColor(color);
					if ((fa && !fb) || (!fa && fb))
						return true;
				}
			}
		}
	}
	return false;
}

bool Chess::Score20(int color)
{
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if (checkPer(i, j, color, k, 2))
				{
					int dx = i - kDir[k][0], dy = j - kDir[k][1];
					bool fa = IsInMap(dx, dy) && !map_[dx][dy];
					dx += 3 * kDir[k][0], dy += 3 * kDir[k][1];
					bool fb = IsInMap(dx, dy) && !map_[dx][dy];
					if (fa && fb)
						return true;
				}
			}
		}
	}
	return false;
}

bool Chess::Score10(int color)
{
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				if (checkPer(i, j, color, k, 2))
				{
					int dx = i - kDir[k][0], dy = j - kDir[k][1];
					bool fa = IsInMap(dx, dy) && map_[dx][dy] == ReverseColor(color);
					dx += 3 * kDir[k][0], dy += 3 * kDir[k][1];
					bool fb = IsInMap(dx, dy) && map_[dx][dy] == ReverseColor(color);
					if ((fa && !fb) || (!fa && fb))
						return true;
				}
			}
		}
	}
	return false;
}

bool Chess::Score00(int color)
{
	for (int i = 0; i < kMapMax; ++i)
	{
		for (int j = 0; j < kMapMax; ++j)
		{
			for (int k = 0; k < kDirTimes; ++k)
			{
				int dx = i + kDir[i][0];
				int dy = i + kDir[i][1];
				if (IsInMap(dx, dy) && map_[dx][dy])
					return true;
			}
		}
	}
	return false;
}

#endif

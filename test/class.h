#ifndef HOME_MOOGLE_PRORAMMING_SOURCE_GOBANG_CLASS_H_
#define HOME_MOOGLE_PRORAMMING_SOURCE_GOBANG_CLASS_H_

#define INPUT_CHESSMAN "请输入落子坐标, 落子颜色: "
#define ALREADY_HAD "该位置已有棋子, 不能在此位置落子, 请重新选择落子位置: \n"

const int kMapMax = 20;

class Chess
{
public:
	Chess();
	void ShowMap();
	void SetValue();
	int CheckResult();

private:

	const int kDir[6][2] = {{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,-1}};
	const int kDirTimes = 6;
	const int kWinCount = 5;
	const char kNone = ' ';
	const char kFirst = 'o';
	const char kSecond = 'x';

	int map_[kMapMax][kMapMax];

	bool checkPer(int x, int y, int val, int order);
	bool IsInMap(int x, int y);
};

#endif

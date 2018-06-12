#ifndef CLASS_H_
#define CLASS_H_

#include <cstdio>

#define LINE "---------------------------------------------------------------"
#define MENU_LINE "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
#define MENU_SEPERATE "          "

const int kMapMax = 20;

class Chess
{
public:
	Chess();
	void Select(bool flag);


private:
	const int kDir[6][2] = { { 0,1 },{ 1,1 },{ 1,0 },{ -1,-1 },{ -1,0 },{ 0,-1 } };
	const int kNeighborDir[24][2] = { { -2,-2 },{ -1,-2 },{ 0,-2 },{ 1,-2 },{ 2,-2 },
									{ -2,-1 },{ -1,-1 },{ 0,-1 },{ 1,-1 },{ 2,-1 },
									{ -2, 0 },{ -1, 0 },{ 1, 0 },{ 2, 0 },
									{ -2, 1 },{ -1, 1 },{ 0, 1 },{ 1, 1 },{ 2, 1 },
									{ -2, 2 },{ -1, 2 },{ 0, 2 },{ 1, 2 },{ 2, 2 } };
	const int kDirTimes = 6;
	const int kNeighborDirTimes = 24;
	const char kNone = ' ';
	const char kFirst = 'o';
	const char kSecond = 'x';

	int map_[kMapMax][kMapMax];
	bool is_neighbor_[kMapMax][kMapMax];
	int score_[kMapMax][kMapMax];

	bool checkPer(int x, int y, int val, int order, int CheckCount);
	bool IsInMap(int x, int y);
	void Init();
	void ShowMenu();
	void ShowMap();
	void PersonToPerson();
	void PersonToComputer();
	void SetValue(int color, bool flag);
	void ComputerSetValue(int color);
	void GenerateNeighbor();
	bool HinderPlayer(int color);
	bool HasNeighbor(int x, int y);
	int ReverseColor(int color);
	int Calculate(int x, int y, int color);
	int CheckResult();

	bool Score100(int color);
	bool Score90(int color);
	bool Score80(int color);
	bool Score70(int color);
	bool Score60(int color);
	bool Score50(int color);
	bool Score40(int color);
	bool Score30(int color);
	bool Score20(int color);
	bool Score10(int color);
	bool Score00(int color);
};

#endif

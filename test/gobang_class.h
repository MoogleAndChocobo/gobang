#ifndef GOBANG_CLASS_H_
#define GOBANG_CLASS_H_

#define LINE "---------------------------------------------------------------"
#define MENU_LINE "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
#define MENU_SEPERATE "          "

const int kMapMax = 20;

class Chess
{
public:
	Chess();
	void ShowMenu();
	void ShowMap();
	void PersonToPerson();
	void PersonToComputer();
	void SetValue(int color, bool flag);
	void ComputerSetValue();
	void GenerateNeighbor();
	bool HasNeighbor(int x, int y);
	int CheckResult();
	void Select(bool flag);
	void Init();


private:
	const int kDir[6][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 },{ 1,1 },{ -1,-1 } };
	const int kNeighborDir[24][2] = { { -2,-2 },{ -1,-2 },{ 0,-2 },{ 1,-2 },{ 2,-2 },
									{ -2,-1 },{ -1,-1 },{ 0,-1 },{ 1,-1 },{ 2,-1 },
									{ -2, 0 },{ -1, 0 },{ 1, 0 },{ 2, 0 },
									{ -2, 1 },{ -1, 1 },{ 0, 1 },{ 1, 1 },{ 2, 1 },
									{ -2, 2 },{ -1, 2 },{ 0, 2 },{ 1, 2 },{ 2, 2 } };
	const int kDirTimes = 6;
	const int kNeighborDirTimes = 24;
	const int kWinCount = 5;
	const char kNone = ' ';
	const char kFirst = 'o';
	const char kSecond = 'x';

	int map_[kMapMax][kMapMax];
	bool is_neighbor_[kMapMax][kMapMax];

	bool checkPer(int x, int y, int val, int order);
	bool IsInMap(int x, int y);
};

#endif

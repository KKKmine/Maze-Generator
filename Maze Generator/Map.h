#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;

inline void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

class Map
{
private:
	int _sizex;
	int _sizey;
	vector<vector<int>> _map;
	int _delay = 10;
public:
	Map(int x, int y);
	void SetSize(int x, int y);
	void ResetMap();
	void ShowMap();
	void CloseDelay();
	inline int GetMap(int x, int y);
	void BuildMaze_2(int x, int y);
	void BuildMaze_1(int x, int y);
};
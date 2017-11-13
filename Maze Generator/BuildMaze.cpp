#include"Map.h"

inline int Map::GetMap(int x, int y)
{
	if (x >= 0 && y >= 0 && x<_sizex && y<_sizey)
	{
		return _map[x][y];
	}
	return -1;
}

//2D  非方格式  最深優先路徑
void Map::BuildMaze_2(int x, int y)
{
	gotoxy(2 * y, x);
	cout << "  ";
	_map[x][y] = 0;
	int passed[4] = { 0 };
	Sleep(_delay);
	while (passed[0] != 1 || passed[1] != 1 || passed[2] != 1 || passed[3] != 1)
	{
		switch (rand() % 4)
		{
		case 0:
			if (GetMap(x - 1, y) != -1)
			{
				if (GetMap(x - 2, y) == 1 && GetMap(x - 1, y - 1) == 1 && GetMap(x - 1, y + 1) == 1)
				{
					BuildMaze_2(x - 1, y);
				}
			}
			passed[0] = 1;
			break;
		case 1:
			if (GetMap(x + 1, y) != -1)
			{
				if (GetMap(x + 2, y) == 1 && GetMap(x + 1, y - 1) == 1 && GetMap(x + 1, y + 1) == 1)
				{
					BuildMaze_2(x + 1, y);
				}
			}
			passed[1] = 1;
			break;
		case 2:
			if (GetMap(x, y - 1) != -1)
			{
				if (GetMap(x - 1, y - 1) == 1 && GetMap(x + 1, y - 1) == 1 && GetMap(x, y - 2) == 1)
				{
					BuildMaze_2(x, y - 1);
				}
			}
			passed[2] = 1;
			break;
		case 3:
			if (GetMap(x, y + 1) != -1)
			{
				if (GetMap(x - 1, y + 1) == 1 && GetMap(x + 1, y + 1) == 1 && GetMap(x, y + 2) == 1)
				{
					BuildMaze_2(x, y + 1);
				}
			}
			passed[3] = 1;
			break;
		}
	}
	return;
}

//2D  方格式  最深優先路徑 
void Map::BuildMaze_1(int x, int y)
{
	gotoxy(2 * y, x);
	cout << "  ";
	_map[x][y] = 0;
	Sleep(_delay);
	int passed[4] = { 0 };
	while (passed[0] != 1 || passed[1] != 1 || passed[2] != 1 || passed[3] != 1)
	{
		switch (rand() % 4)
		{
		case 0:
			if (x + 2<_sizex && _map[x + 2][y] == 1)
			{
				_map[x + 1][y] = 4;
				gotoxy(2 * y, x + 1);
				cout << "  ";
				BuildMaze_1(x + 2, y);
			}
			passed[0] = 1;
			break;
		case 1:
			if (x - 2 >= 0 && _map[x - 2][y] == 1)
			{
				_map[x - 1][y] = 4;
				gotoxy(2 * y, x - 1);
				cout << "  ";
				BuildMaze_1(x - 2, y);
			}
			passed[1] = 1;
			break;
		case 2:
			if (y + 2<_sizey && _map[x][y + 2] == 1)
			{
				_map[x][y + 1] = 4;
				gotoxy(2 * y + 2, x);
				cout << "  ";
				BuildMaze_1(x, y + 2);
			}
			passed[2] = 1;
			break;
		case 3:
			if (y - 2 >= 0 && _map[x][y - 2] == 1)
			{
				_map[x][y - 1] = 4;
				gotoxy(2 * y - 2, x);
				cout << "  ";
				BuildMaze_1(x, y - 2);
			}
			passed[3] = 1;
			break;
		}
	}
	return;
}
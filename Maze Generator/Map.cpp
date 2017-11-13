#include"Map.h"

Map::Map(int x, int y)
{
	SetSize(x, y);
	ResetMap();
}

void Map::ResetMap()
{
	for (int i = 0; i<_sizex; i++)
	{
		for (int j = 0; j<_sizey; j++)
		{
			_map[i][j] = 1;
		}
	}
	_delay = 10;
}

void Map::SetSize(int x, int y)
{
	_sizex = x;
	_sizey = y;
	for (int i = 0; i < _sizex; i++)
	{
		vector<int> v(_sizey);
		_map.push_back(v);
	}
}

void Map::ShowMap()
{
	for (int i = 0; i<_sizex; i++)
	{
		for (int j = 0; j<_sizey; j++)
		{
			if (_map[i][j] % 2 == 0)
			{
				cout << "  ";
			}
			else if (_map[i][j] % 2 == 1)
			{
				cout << "¢p";
			}
		}
		cout << endl;
	}
}

void Map::CloseDelay()
{
	_delay = 0;
}
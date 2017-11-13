//
//    Maze Generator v0.2
//
//Map 軸 : x軸-上下  y軸-左右
//Map id : 0-空格  1-牆壁 

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<thread>
#include"Map.h"
using namespace std;

int main()
{
	srand(time(0));
	int x, y;
	cout << "---迷宮生成器---" << endl;
	cout << "迷宮規則 : 牆有厚度 可以斜走" << endl;
	cout << "\n輸入迷宮的寬與高 : " << endl;
	cin >> y >> x;

	Map mMap(x, y);
	do
	{
		system("cls");
		mMap.ResetMap();
		mMap.ShowMap();
		mMap.BuildMaze_2(1, 1);
		gotoxy(0, x);
		cout << "Done" << endl;
	}while (getch());

	return 0;
}


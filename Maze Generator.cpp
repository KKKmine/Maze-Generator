//
//    Maze Generator v0.2
//
//Map 軸 : x軸-上下  y軸-左右
//Map id : 0-空格  1-牆壁 
 
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<thread>
using namespace std;
#define SIZEX 39 
#define SIZEY 39 

void ResetMap(int[SIZEX][SIZEY]);
void ShowMap(int[SIZEX][SIZEY]);
void BuildMaze_2(int[SIZEX][SIZEY], int, int);
void BuildMaze_1(int[SIZEX][SIZEY], int, int);
inline int GetMap(int map[SIZEX][SIZEY], int x, int y)
{
	if(x>=0 && y>=0 && x<SIZEX && y<SIZEY)
	{
		return map[x][y];
	}
	return -1;
}

inline void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

int main()
{
	srand(time(0));
	int map[SIZEX][SIZEY];
	while(getch()) 
	{
		system("cls");
		ResetMap(map);
		ShowMap(map);
		thread mThread(BuildMaze_2, map, 1, 1);
		mThread.join();
		gotoxy(0, SIZEX+1);
		cout<< "Done" <<endl;
	}
	return 0;
} 


void ResetMap(int map[SIZEX][SIZEY])
{
	for(int i=0;i<SIZEX;i++)
	{
		for(int j=0;j<SIZEY;j++)
		{
			map[i][j] = 1;
		}
	}
}

void ShowMap(int map[SIZEX][SIZEY])
{
	for(int i=0;i<SIZEX;i++)
	{
		for(int j=0;j<SIZEY;j++)
		{
			if(map[i][j]%2 == 0)
			{
				cout<<"  ";
			}
			else if(map[i][j]%2 == 1)
			{
				cout<<"▉";
			}
		}
		cout<<endl;
	}
} 

//2D  非方格式  最深優先路徑
void BuildMaze_2(int map[SIZEX][SIZEY], int x, int y)
{
	gotoxy(2*y, x);
	cout<<"  ";
	map[x][y] = 0;
	int passed[4] = {0};
	Sleep(10);
	while(passed[0]!=1||passed[1]!=1||passed[2]!=1||passed[3]!=1)
	{	
		switch(rand()%4)
		{
			case 0:
				if(GetMap(map, x-1, y)!=-1)
				{
					if(GetMap(map, x-2, y)==1 && GetMap(map, x-1, y-1)==1 && GetMap(map, x-1, y+1)==1)
					{
						BuildMaze_2(map, x-1, y);	
					}
				}
				passed[0]=1;
				break;
			case 1:
				if(GetMap(map, x+1, y)!=-1)
				{
					if(GetMap(map, x+2, y)==1 && GetMap(map, x+1, y-1)==1 && GetMap(map, x+1, y+1)==1)
					{
						BuildMaze_2(map, x+1, y);	
					}
				}
				passed[1]=1;
				break;
			case 2:
				if(GetMap(map, x, y-1)!=-1)
				{
					if(GetMap(map, x-1, y-1)==1 && GetMap(map, x+1, y-1)==1 && GetMap(map, x, y-2)==1)
					{
						BuildMaze_2(map, x, y-1);	
					}
				}
				passed[2]=1;
				break;
			case 3:
				if(GetMap(map, x, y+1)!=-1)
				{
					if(GetMap(map, x-1, y+1)==1 && GetMap(map, x+1, y+1)==1 && GetMap(map, x, y+2)==1)
					{
						BuildMaze_2(map, x, y+1);	
					}
				}
				passed[3]=1;
				break;
		}
	}
	return;
}

//2D  方格式  最深優先路徑 
void BuildMaze_1(int map[SIZEX][SIZEY], int x, int y)
{
	gotoxy(2*y, x);
	cout<<"  ";
	map[x][y] = 0;
	Sleep(10);
	int passed[4] = {0};
	while(passed[0]!=1||passed[1]!=1||passed[2]!=1||passed[3]!=1)
	{	
		switch(rand()%4)
		{
			case 0:
				if(x+2<SIZEX&&map[x+2][y] == 1)
				{
					map[x+1][y] = 4;
					gotoxy(2*y, x+1);
					cout<<"  ";
					BuildMaze_1(map, x+2, y);	
				}
				passed[0]=1;
				break;
			case 1:
				if(x-2>=0&&map[x-2][y] == 1)
				{
					map[x-1][y] = 4;
					gotoxy(2*y, x-1);
					cout<<"  ";
					BuildMaze_1(map, x-2, y);	
				}
				passed[1]=1;
				break;
			case 2:
				if(y+2<SIZEY&&map[x][y+2] == 1)
				{
					map[x][y+1] = 4;
					gotoxy(2*y+2, x);
					cout<<"  ";
					BuildMaze_1(map, x, y+2);	
				}
				passed[2]=1;
				break;
			case 3:
				if(y-2>=0&&map[x][y-2] == 1)
				{
					map[x][y-1] = 4;
					gotoxy(2*y-2, x);
					cout<<"  ";
					BuildMaze_1(map, x, y-2);	
				}
				passed[3]=1;
				break;
		}
	}
	return;
}


//
//    Maze Generator v0.2
//
//Map �b : x�b-�W�U  y�b-���k
//Map id : 0-�Ů�  1-��� 

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
	cout << "---�g�c�ͦ���---" << endl;
	cout << "�g�c�W�h : �𦳫p�� �i�H�ר�" << endl;
	cout << "\n��J�g�c���e�P�� : " << endl;
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


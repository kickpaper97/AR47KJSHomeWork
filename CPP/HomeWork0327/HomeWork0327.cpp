// HomeWork0324.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>

class int2
{
public:
	int X = 0;
	int Y = 0;

public:
	int2 Half()
	{
		return { X / 2, Y / 2 };
	}

public:

	int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}
};

class Map
{
public:

	 int MapXSize = 0;
	int MapYSize = 0;

	Map(const int2& _Size): MapXSize(_Size.X),MapYSize(_Size.Y)
	{

	}


	 int2 GetMapSize()
	{
		return int2{ MapXSize,MapYSize };
	}

	 void SetMapSize(const int2& _Size)
	 {
		 MapXSize = _Size.X;
		 MapYSize = _Size.Y;
	}


	bool IsScreenOver(const int2& _Pos)
	{
		if (0 > _Pos.X)
		{
			return true;
		}

		if (0 > _Pos.Y)
		{
			return true;
		}

		if (MapXSize <= _Pos.X)
		{
			return true;
		}

		if (MapYSize <= _Pos.Y)
		{
			return true;
		}

		return false;
	}


};


class ConsoleGameScreen
{
public:
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	static int2 GetScreenSize()
	{
		return int2{ ScreenXSize, ScreenYSize };
	}


	void ScreenClear()
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				Arr[y][x] = 'a';
			}
		}
	}

	void ScreenPrint() const
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				// Arr[y][x] = 'b';
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}
	}

	

	void SetScreenCharacter(const int2& _Pos, char _Ch)
	{
		if (true == NewMap.IsScreenOver(_Pos))
		{
			return;
		}

		Arr[_Pos.Y][_Pos.X] = _Ch;
	}

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, };
	Map NewMap= Map(GetScreenSize());
};



class Player
{
public:
	int2 GetPos() const
	{
		return Pos;
	}

	void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	// 화면바깥으로 못나가게 하세요. 
	void Input()
	{
		if (0 == _kbhit())
		{
			// 0.5초간 멈춘다.
			Sleep(InterFrame);
			return;
		}

		char Ch = _getch();

		switch (Ch)
		{
		case 'a':
		case 'A':
			Pos.X -= 1;
			if (NewMap.IsScreenOver(Pos))
			{
				Pos.X += 1;
			}
			break;
		case 'd':
		case 'D':
			Pos.X += 1;
			if (NewMap.IsScreenOver(Pos))
			{
				Pos.X -= 1;
			}
			break;
		case 'w':
		case 'W':
			Pos.Y -= 1;

			if (NewMap.IsScreenOver(Pos))
			{
				Pos.Y += 1;
			}
			break;
		case 's':
		case 'S':
			Pos.Y += 1;

			if (NewMap.IsScreenOver(Pos))
			{
				Pos.Y -= 1;
			}
			break;
		default:
			break;
		}

		Sleep(InterFrame);
	}

	
protected:

private:
	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);

	Map NewMap=Map(Pos);
};


int main()
{
	ConsoleGameScreen NewScreen;
	Player NewPlayer;

	// int2 NewPos = int2{ 5, 5 };

	int2 ScreenSize = NewScreen.GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		NewScreen.ScreenClear();

		NewScreen.SetScreenCharacter(NewPlayer.GetPos(), '*');

		NewScreen.ScreenPrint();

		NewPlayer.Input();

	}


}

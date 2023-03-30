// HomeWork0329.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Player.h"
#include "Bullet.h"
#include "ConsoleGameScreen.h"

int main()
{
	// 오늘의 숙제입니다.
	// 총알 1발을 발사하세요.
	// 방향 상관 없음.
	// 총알 클래스를 만든다.
	// 플레이어가 여러분들이 지정한 키를 누르르면 

	// Bullet NewBullet;
	
	Player NewPlayer = Player();
	
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetPos(), '*');
		
		if (true == NewPlayer.IsFire())
		{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetBulletPos(), '^');
		}

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();

	}

	std::cout << "Hello World!\n";
}
// HomeWork0324.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
// 운영체제가 도와줄수밖에 없다.
#include <Windows.h>



int main()
{

	//스크린 
	const int ScreenYSize = 10;
	const int ScreenXSize = 10;

	char Arr[ScreenYSize][ScreenXSize] = { 0, };


	//player  배치
	int PlayerY = ScreenYSize / 2;
	int PlayerX = ScreenXSize / 2;


	//폭탄  
	int BombY = 0;
	int BombX = 0;
	int Bombcounter = 0;
	bool isBombOn = false;


	//폭발 불꽃
	int flameUpY = 0;
	int flameUpX = 0;
	int flameDownY = 0;
	int flameDownX = 0;
	int flameLeftY = 0;
	int flameLeftX = 0;
	int flameRightY = 0;
	int flameRightX = 0;
	int flamecount = 0;
	bool isflameUpHitWall = false;
	bool isflameDownHitWall = false;
	bool isflameLeftHitWall = false;
	bool isflameRightHitWall = false;
	bool isFlameOn = false;


	//장애물  배치

	srand(time(0));

	int enemyY1 = rand() % ScreenYSize;
	int enemyX1 = rand() % ScreenXSize;
	bool isEnemy1Alive = true;

	int enemyY2 = (rand() * rand()) % ScreenYSize;
	int enemyX2 = (rand() + rand()) % ScreenXSize;
	bool isEnemy2Alive = true;





	


	while (true)
	{

		system("cls");

		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				Arr[y][x] = '.';
			}
		}



		Arr[PlayerY][PlayerX] = '*';



		if (isEnemy1Alive)
		{
			Arr[enemyY1][enemyX1] = 'E';
		}

		if (isEnemy2Alive)
		{
			Arr[enemyY2][enemyX2] = 'E';
		}


		if (isBombOn)
		{
			Arr[BombY][BombX] = 'B';
		}

		if (isFlameOn)
		{
			if (!isflameUpHitWall)
			{
				Arr[flameUpY][flameUpX] = '@';
			}
			if (!isflameDownHitWall)
			{
				Arr[flameDownY][flameDownX] = '@';
			}
			if (!isflameLeftHitWall)
			{
				Arr[flameLeftY][flameLeftX] = '@';
			}
			if (!isflameRightHitWall)
			{
				Arr[flameRightY][flameRightX] = '@';
			}
		}



		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}


		if (Arr[enemyY1][enemyX1] == '@')
		{
			isEnemy1Alive = false;
		}

		if (Arr[enemyY2][enemyX2] == '@')
		{
			isEnemy2Alive = false;
		}

		if (Bombcounter > 5)
		{
			isBombOn = false;
			Bombcounter = 0;

			isFlameOn = true;

		}

		if (flamecount > 3)
		{

			isFlameOn = false;
			isflameUpHitWall = false;
			isflameDownHitWall = false;
			isflameLeftHitWall = false;
			isflameRightHitWall = false;
			flamecount = 0;
		}



		// 이건 내가 키를 눌렀다면 1
		// 아니라면 0을 리턴하는 함수고 정지하지 않습니다.
		// 키를 눌렀다는것을 체크해주는 함수
		if (0 == _kbhit())
		{
			// 0.5초간 멈춘다.
			Sleep(300);
			// 일부러 멈추게 만들겁니다.
			if (isBombOn)
			{
				++Bombcounter;

			}

			if (isFlameOn)
			{
				++flamecount;
			}

			if (flamecount > 0)
			{
				if (flameUpY == 0)
				{
					isflameUpHitWall = true;
				}
				else
				{
					++flameUpY;
				}

				if (flameDownY == ScreenYSize - 1)
				{
					isflameDownHitWall = true;
				}
				else
				{
					--flameDownY;
				}

				if (flameLeftX == 0)
				{
					isflameLeftHitWall = true;
				}
				else
				{
					--flameLeftX;
				}

				if (flameRightX == ScreenXSize - 1)
				{
					isflameRightHitWall = true;
				}
				else
				{
					++flameRightX;
				}

			}
			continue;
		}


		// 어떤키를 눌렀는지 알려주는 함수.
		char Ch = _getch();


		switch (Ch)
		{

		case 'a':
		case 'A':

			if (PlayerX == 0)
			{
				break;
			}

			if (isEnemy1Alive) {
				if (PlayerX == enemyX1 + 1 && PlayerY == enemyY1)
				{
					break;

				}
			}

			if (isEnemy2Alive) {
				if (PlayerX == enemyX2 + 1 && PlayerY == enemyY2)
				{
					break;

				}
			}


			PlayerX -= 1;
			break;

		case 'd':
		case'D':

			if (PlayerX == ScreenXSize - 1)
			{
				break;
			}

			if (isEnemy1Alive) {
				if (PlayerX == enemyX1 - 1 && PlayerY == enemyY1)
				{
					break;

				}
			}

			if (isEnemy2Alive) {
				if (PlayerX == enemyX2 - 1 && PlayerY == enemyY2)
				{
					break;

				}
			}


			PlayerX += 1;
			break;

		case'w':
		case'W':

			if (PlayerY == 0)
			{
				break;
			}

			if (isEnemy1Alive) {
				if (PlayerX == enemyX1 && PlayerY == enemyY1 + 1)
				{
					break;

				}
			}

			if (isEnemy2Alive) {
				if (PlayerX == enemyX2 && PlayerY == enemyY2 + 1)
				{
					break;

				}
			}



			PlayerY -= 1;
			break;

		case's':
		case'S':

			if (PlayerY == ScreenYSize - 1)
			{
				break;
			}


			if (isEnemy1Alive) {
				if (PlayerX == enemyX1 && PlayerY == enemyY1 - 1)
				{
					break;

				}
			}

			if (isEnemy2Alive) {
				if (PlayerX == enemyX2 && PlayerY == enemyY2 - 1)
				{
					break;

				}
			}


			PlayerY += 1;
			break;

		case 'f':
		case 'F':
			BombY = PlayerY;
			BombX = PlayerX;
			isBombOn = true;


			flameUpY = BombY;
			flameUpX = BombX;
			flameDownY = BombY;
			flameDownX = BombX;
			flameLeftY = BombY;
			flameLeftX = BombX;
			flameRightY = BombY;
			flameRightX = BombX;

			break;

		default:
			break;
		}

	}


}

#include "Bullet.h"
#include "ConsoleGameScreen.h"





bool Bullet::Move()
{
	int2 NextPos = Pos;
	NextPos.Y -= 1;
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
	{
		return false;
		
	}
	Pos.Y -= 1;
	return true;
}



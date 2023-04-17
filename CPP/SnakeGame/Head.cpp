#include "Head.h"
#include <conio.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include<list>

bool Head::IsPlay = true;
bool Head::IsBody = true;

Head::Head() 
{
	RenderChar = '$';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head() 
{
}

void Head::IsCrushCheck(int2 _NextPos)
{
	std::list<ConsoleGameObject*>& AllParts
		= ConsoleObjectManager::GetGroup(0);

	
	for (ConsoleGameObject* Ptr : AllParts)
	{
		// 터질때가 있습니다.
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 BodyPos = Ptr->GetPos();
		if (_NextPos == BodyPos)
		{
			Head::IsPlay = false;
		}
	}

	
}

void Head::NewBodyCreateCheck()
{
	std::list<ConsoleGameObject*>& BodyGroup
		= ConsoleObjectManager::GetGroup(1);

	std::list<ConsoleGameObject*>::iterator Now = BodyGroup.begin();

	for (ConsoleGameObject* Ptr : BodyGroup)
	{
		// 터질때가 있습니다.
		if (nullptr == Ptr)
		{
			continue;
		}

		if (Now == BodyGroup.end())
		{
			IsBody= true;
		}

		int2 ItemPos = Ptr->GetPos();
		if (this->Pos == ItemPos)
		{
			BodyGroup.erase(Now);
			IsBody=false;
			ConsoleObjectManager::CreateConsoleObject<Parts>(0);
			return;
		}
		
	}
	

}

// 화면바깥으로 못나가게 하세요. 
void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}


	if (0 == _kbhit())
	{
		// SetPos(GetPos() + Dir);
		// IsBodyCheck();
		NewBodyCreateCheck();
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		Dir = int2::Left;
		NextPos = Dir+ NextPos;
		IsCrushCheck(NextPos);
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		Dir = int2::Right;
		NextPos = Dir + NextPos;
		IsCrushCheck(NextPos);
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		Dir = int2::Up;
		NextPos = Dir + NextPos;
		IsCrushCheck(NextPos);
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		Dir = int2::Down;
		NextPos = Dir + NextPos;
		IsCrushCheck(NextPos);
		break;
	case 'q':
	case 'Q':

		IsPlay = false;
		return;
	default:
		return;
	}

	SetPos(GetPos() + Dir);
	//IsBodyCheck();
	NewBodyCreateCheck();

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}



}

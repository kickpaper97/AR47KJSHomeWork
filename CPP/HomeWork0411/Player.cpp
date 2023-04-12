#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include "ConsoleObjectManager.h"
#include "Bomb.h"
#include "GameEnum.h"
#include "ConsoleObjectManager.h"

bool Player::IsGameUpdate = true;

Player::Player()
{
	RenderChar = '*';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

}

bool Player::IsBomb(int2 _NextPos)
{
	// ��ź�� ��ġ�Ǿ��ٸ� ������ϰ� ������������.
	GameEngineArray<ConsoleGameObject*>& BombGroup 
		= ConsoleObjectManager::GetGroup(ObjectOrder::Bomb);

	int2 BombPos = { -1,-1 };

	for (size_t i = 0; i < BombGroup.Count(); i++)
	{
		if (BombGroup[i]==nullptr)
		{
			continue;
		}

		BombPos = BombGroup[i]->GetPos();
		if (BombPos == _NextPos)
		{
			return true;
		}
		
	}

	return false;
}

// ȭ��ٱ����� �������� �ϼ���. 
void Player::Update()
{
	if (0 == _kbhit())
	{
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };


	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (true == IsBomb(NextPos))
		{
			NextPos.X += 1;
			break;
		}
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
		}
		
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (true == IsBomb(NextPos))
		{
			NextPos.X -= 1;
			break;
		}
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (true == IsBomb(NextPos))
		{
			NextPos.Y += 1;
			break;
		}
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (true == IsBomb(NextPos))
		{
			NextPos.Y -= 1;
			break;
		}
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
	{
		// ���� �̻�Ȳ���� ����
		// ConsoleObjectManager �ְ�
		// Player 
		Bomb* NewBomb = ConsoleObjectManager::CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
		NewBomb->Init(BombPower);
		NewBomb->SetPos(GetPos());
		// ��ź��ġ 
		break;
	}
	case 'q':
	case 'Q':
	{
		IsGameUpdate = false;
		break;
	}
	default:
		break;
	}
}

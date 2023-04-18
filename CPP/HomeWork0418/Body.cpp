#include "Body.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include <vector>
#include <list>
#include "GameEnum.h"


bool Body::IsSpace = true;


Body::Body() 
{
	RenderChar = L'◇';



	int ScreenSizeX = ConsoleGameScreen::GetMainScreen().GetScreenSize().X;
	int ScreenSizeY = ConsoleGameScreen::GetMainScreen().GetScreenSize().Y;
	int ScreenPixelCount = ConsoleGameScreen::GetMainScreen().GetScreenSize().X * ConsoleGameScreen::GetMainScreen().GetScreenSize().Y;

	std::vector<std::vector<bool>> EmptyPlace(ScreenSizeY, std::vector<bool>(ScreenSizeX, true));

	std::list<ConsoleGameObject*>& bodyParts
		= ConsoleObjectManager::GetGroup(SnakeGameOrder::Body);

	std::list<ConsoleGameObject*>& HeadPart
		= ConsoleObjectManager::GetGroup(SnakeGameOrder::Head);

	

	std::list<ConsoleGameObject*>::iterator Now = bodyParts.begin();

	std::vector<int2>ObjPlace;
	ObjPlace.reserve(bodyParts.size()+1);

	for (ConsoleGameObject* Ptr : bodyParts)
	{
		// 터질때가 있습니다.
		if (nullptr == Ptr)
		{
			continue;
		}


		int2 PtrPos = Ptr->GetPos();
		ObjPlace.push_back(PtrPos);

		if (Now == bodyParts.end())
		{
			break;
		}
		Now++;
	}

	ObjPlace.push_back((*HeadPart.begin())->GetPos());

	int a= 0;

	for (size_t i = 0; i < ObjPlace.size(); i++)
	{
		for (size_t y = 0; y < ScreenSizeY; y++)
		{

			for (size_t x = 0; x < ScreenSizeX; x++)
			{
				if (ObjPlace[i] == int2(x, y))
				{
					EmptyPlace[y][x] = false;
				}
			}
		}

	}

	int EmptyCount = ScreenPixelCount - ObjPlace.size();
	std::vector<int2> ArrEmptyPos;
	ArrEmptyPos.reserve(EmptyCount);

	for (size_t i = 0; i < EmptyCount; i++)
	{
		for (size_t y = 0; y < ScreenSizeY; y++)
		{

			for (size_t x = 0; x < ScreenSizeX; x++)
			{
				if (EmptyPlace[y][x] == true)
				{
					ArrEmptyPos.push_back(int2(x, y));
				}
			}
		}

	}

	if (EmptyCount <= 0)
	{
		Body::IsSpace = false;
		return;
	}

	SetPos(ArrEmptyPos[GameEngineRandom::MainRandom.RandomInt(0, EmptyCount - 1)]);
}

Body::~Body() 
{
}


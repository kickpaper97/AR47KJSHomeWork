#include "Body.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include<GameEngineConsole/ConsoleObjectManager.h>
#include <vector>

bool Body::IsSpace = true;

Body::Body() 
{
	RenderChar = 'i';


	int ScreenSizeX = ConsoleGameScreen::GetMainScreen().GetScreenSize().X;
	int ScreenSizeY = ConsoleGameScreen::GetMainScreen().GetScreenSize().Y;
	int ScreenPixelCount = ConsoleGameScreen::GetMainScreen().GetScreenSize().X * ConsoleGameScreen::GetMainScreen().GetScreenSize().Y;
	
	std::vector<std::vector<bool>> EmptyPlace(ScreenSizeY,std::vector<bool>(ScreenSizeX,true));
	
	std::list<ConsoleGameObject*>& AllParts
		= ConsoleObjectManager::GetGroup(0);
	std::list<ConsoleGameObject*>::iterator Now = AllParts.begin();

	std::vector<int2>ObjPlace;
	ObjPlace.reserve(AllParts.size());
	
	for (ConsoleGameObject* Ptr : AllParts)
	{
		// 터질때가 있습니다.
		if (nullptr == Ptr)
		{
			continue;
		}


		int2 PtrPos = Ptr->GetPos();
		ObjPlace.push_back(PtrPos);

		if (Now == AllParts.end())
		{
			break ;
		}
		Now++;
	}

	for (size_t i = 0; i < ObjPlace.size(); i++)
	{	
		for (size_t y = 0; y < ScreenSizeY; y++)
			{
				
				for (size_t x = 0; x < ScreenSizeX; x++)
				{
					if (ObjPlace[i] == int2(x, y))
					{
					EmptyPlace[y][x]=false;
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




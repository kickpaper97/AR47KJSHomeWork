#include "Bomb.h"
#include "ConsoleObjectManager.h"
#include "GameEnum.h"

Bomb::Bomb() 
{
	
}

Bomb::~Bomb() 
{
}

void Bomb::Init()
{
	RenderChar = '@';
}

// explogen

void Bomb::Update() 
{
	ConsoleGameObject::Update();

	if (0 >= --BoomCount)
	{
		Off();
		
		for (size_t i = 0; i < 4; i++)
		{
			NewFlame[i] = ConsoleObjectManager::CreateConsoleObject<Flame>(ObjectOrder::Flame);
			NewFlame[i]->SetPos(GetPos());
			NewFlame[i]->SetDir((int)i);
		}

		if (NewFlame == nullptr)
		{
			return;
		}

		
	}
	

	
}


void Bomb::Render() 
{

	ConsoleGameObject::Render();

}
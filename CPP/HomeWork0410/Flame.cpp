#include "Flame.h"
#include "GameEnum.h"

Flame::Flame()
{
	RenderChar = 'X';
}

Flame::~Flame()
{
	
	
}


void Flame::Update()
{
	ConsoleGameObject::Update();
	switch (Dir)
	{
	case FlameDir::Up:
		SetPos(int2(Pos.X, Pos.Y - 1));
		break;
	case FlameDir::Down:
		SetPos(int2(Pos.X, Pos.Y + 1));
		break;
	case FlameDir::Left:
		SetPos(int2(Pos.X-1, Pos.Y ));
		break;
	case FlameDir::Right:
		SetPos(int2(Pos.X+1, Pos.Y ));
		break;

	default:
		break;
	}

	--FlameCount;
}


void Flame::Render()
{
	if (0 < FlameCount)
	{

	ConsoleGameObject::Render();
	}

}

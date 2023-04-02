#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();

	inline const int  GetDir()
	{
		return Dir;
	}
	inline bool ChangeDir() 
	{
		Dir *= -1;
		return true;
	}

	inline void ChangeLine()
	{
		Pos.Y += 1;
	}

	void Update();


private:
	int Dir = -1;
};


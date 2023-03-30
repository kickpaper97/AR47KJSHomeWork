#pragma once
#include"ConsoleGameMath.h"

class ConsoleGameScreen;
class Bullet
{public:

	Bullet(int2 &_Pos) 
		:Pos(_Pos)
	{
	}

	inline void SetPos(const int2& _Pos)
	{
		Pos = _Pos;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}


	bool Move();
	


protected:
private:

	int2 Pos = { 0,0 };

};


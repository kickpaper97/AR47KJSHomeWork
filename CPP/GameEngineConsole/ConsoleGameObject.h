#pragma once
#include "ConsoleGameMath.h"

// Screen에서 움직이는 오브젝트들의 기본기능을 제공한다.
class ConsoleGameObject
{
public:



	virtual inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	virtual inline void SetChar(const wchar_t _Ch)
	{
		RenderChar = _Ch;
	}
	
	inline wchar_t GetChar() const
	{
		return RenderChar;
	}

	bool IsDeath()
	{
		return DeathValue && false ==IsDeath();
	}

	void Death()
	{
		DeathValue = true;
	}

	bool IsUpdate()
	{
		return UpdateValue;
	}

	void On()
	{
		UpdateValue = true;
	}

	void Off()
	{
		UpdateValue = false;
	}

	virtual void Update();
	virtual void Render();

protected:
	int2 Pos;
	wchar_t RenderChar = ' ';

private:
	bool UpdateValue = true;
	bool DeathValue = false;

};


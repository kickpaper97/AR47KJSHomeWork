#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineBase/GameEngineDebug.h>

// 설명 :
class Parts : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Parts();
	~Parts();

	// delete Function
	Parts(const Parts& _Other) = delete;
	Parts(Parts&& _Other) noexcept = delete;
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

	inline Parts* GetLast()
	{
		if (nullptr == Next)
		{
			return this;
		}

		return Next->GetLast();
	}

	inline Parts* GetNext() 
	{
		return Next;
	}

	inline void SetNext(Parts* _Next)
	{
		if (nullptr == _Next)
		{
			MsgBoxAssert("자신의 NextNode를 nullptr로 세팅하려고 했습니다.");
		}

		Next = _Next;
	}

	inline int2 GetPrevPos() 
	{
		return PrevPos;
	}

	inline wchar_t GetPrevChar()
	{
		return PrevChar;
	}

	void SetPrevChar(const wchar_t _Ch)
	{
		PrevChar = _Ch;
	}


	inline void SetPos(const int2& _Value) override
	{
		PrevPos = GetPos();
		ConsoleGameObject::SetPos(_Value);
	}

	inline void SetChar(const wchar_t _Ch) override
	{
		PrevChar = GetChar();
		ConsoleGameObject::SetChar(_Ch);
	}

	void NextMove();

protected:
	void Update() override;

private:
	wchar_t PrevChar = L' ';
	int2 PrevPos = int2::Zero;

	

	Parts* Prev;
	Parts* Next;
};


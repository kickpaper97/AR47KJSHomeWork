
#pragma once
#include <Windows.h>
#include <assert.h>
#include <crtdbg.h>


#define MsgBoxAssert(Text) MessageBoxA(nullptr,Text,"Error",MB_OK); assert(false);


class GameEngineDebug
{
public:
	GameEngineDebug();
	~GameEngineDebug();

	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(const GameEngineDebug&& _Other) noexcept = delete;

	static void LeckCheck();

protected:

private:

};


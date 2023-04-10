
#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>



class ConsoleGameScreen;
class Flame : public ConsoleGameObject
{
public:
	Flame();
	~Flame();

	Flame(const Flame& _Other) = delete;
	Flame(Flame&& _Other) noexcept = delete;
	Flame& operator=(const Flame& _Other) = delete;
	Flame& operator=(const Flame&& _Other) noexcept = delete;
	
	void SetDir(int _Dir)
	{
		Dir = _Dir;
	}
	void Update() override;
	void Render() override;
protected:
	
	
private:
	int FlameCount = 5;
	int Dir= -1;

};


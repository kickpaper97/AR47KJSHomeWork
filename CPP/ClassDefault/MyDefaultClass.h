
#pragma once

class MyDefaultClass
{
public:
	MyDefaultClass();
	~MyDefaultClass();

	MyDefaultClass(const MyDefaultClass& _Other) = delete;
	MyDefaultClass(MyDefaultClass&& _Other) noexcept = delete;
	MyDefaultClass& operator=(const MyDefaultClass& _Other) = delete;
	MyDefaultClass& operator=(const MyDefaultClass&& _Other) noexcept = delete;


protected:

private:

};


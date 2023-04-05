#pragma once

class ClassDefault
{
public:
	ClassDefault();
	~ClassDefault();

	ClassDefault(const ClassDefault& _Other) = delete;
	ClassDefault(ClassDefault&& _Other) = delete;
	ClassDefault& operator=(const ClassDefault& _Other) = delete;
	ClassDefault& operator=(const ClassDefault&& _Other) = delete;


protected:

private:

};
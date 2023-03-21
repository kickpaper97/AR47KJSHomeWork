// HomeWork0317.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#include <iostream>

// 영어만 씁니다.

// 문자열을 넣어주면 글자 개수를 알아냅니다.
// 0을 포함할지 아닐지는 스스로 정하세요
int StringCount(const char* _String)
{
	int count = 0;

	while (_String[count])
	{
		count++;
	}

	return count;
}


int TrimDelete(char* _String)
{

	char* pnt = _String;

	while (*pnt != 0)
	{

		if (*pnt != ' ')
		{
			*_String = *pnt;
			++_String;
		}

		++pnt;

	}

	*_String = 0;

	return 0;
}


int StringToInt(const char* _String)
{
	int result = 0;
	int cnt = StringCount(_String);



	while (cnt--)
	{
		int squarecnt = cnt;
		int square = 1;

		while (squarecnt)
		{
			square *= 10;
			squarecnt--;
		}

		result += square * (*_String - '0');

		//또는 result =result*10+(*_String-'0');

		_String++;
	}

	return result;
}

int main()
{
	int Return0 = StringCount("aaaa");
	int Return1 = StringCount("aaaa ggg sss");

	char Arr0[1024] = "a b c d e";
	char Arr1[1024] = "a    b c    d    e";
	char Arr2[1024] = "ab    cde    ";

	TrimDelete(Arr0);
	printf_s(Arr0);
	TrimDelete(Arr1);
	printf_s(Arr1);
	TrimDelete(Arr2);
	printf_s(Arr2);
	// 영어나 다른글자가 섞여 들어가있는것을 가정하지 않는다.
	int RValue0 = StringToInt("1111");
	int RValue1 = StringToInt("432");
	int RValue2 = StringToInt("4523312");
	int RValue3 = StringToInt("432231");

	std::cout << "Hello World!\n";

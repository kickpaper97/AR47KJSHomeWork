#pragma once

typedef int DataType;

// ���� :
class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;


	// constrcuter destructer
	GameEngineArray(size_t _Value)
		: ArrPtr(new DataType[_Value])
		, ArrCount(_Value)
	{
		// ArrPtr = new int[100];
	}

	~GameEngineArray()
	{

		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		
		DataType* other = new DataType[_Other.ArrCount];
		for (size_t i = 0; i < _Other.ArrCount; i++)
		{
			other[i] = _Other.ArrPtr[i];
		}
		


		if (this->ArrCount==_Other.ArrCount)
		{
		ArrPtr = other;
		return *this;
		}

		ReSize(_Other.ArrCount);
		
		ArrPtr = other;
		return *this;

		if (nullptr != other)
		{
			delete[] other;
			other = nullptr;
		}

	}

	size_t Count()
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}



	void ReSize(int _Value)
	{

		// 20�� ����.
		// ���� ������ �Ẹ�ø� �����̴ϴ�.

		// ������ �Ҵ�� �迭�� �˰� �ִ°��� 
		// ���Ҹ� ����� �ȵȴ�.

		// ������ �ִ� ������ ������ �迭�� �����Ѵ��� �����ؾ� �Ѵ�.


		DataType* ArrBackUp = new DataType[ArrCount];


		for (size_t i = 0; i < ArrCount; i++)
		{
			ArrBackUp[i] = ArrPtr[i];
			
		}
		

		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}



		ArrPtr = new DataType[_Value];
		for (size_t i = 0; i < _Value; i++)
		{
			ArrPtr[i] = (i < ArrCount) ? ArrBackUp[i] : 0;
		}
		ArrCount = _Value;


		if (nullptr != ArrBackUp)
		{
			delete[] ArrBackUp;
			ArrBackUp = nullptr;
		}


	}

protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;

};


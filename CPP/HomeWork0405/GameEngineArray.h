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
		
		

		ReSize(_Other.ArrCount);

		for (size_t i = 0; i < _Other.ArrCount; i++)
		{

			ArrPtr[i] = _Other[i];
		}
		
		return *this;

		

	}

	size_t Count()
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index) const
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


		DataType* ArrBackUp = new DataType[_Value];
		int CopySize = _Value < ArrCount ? _Value : ArrCount;


		for (size_t i = 0; i < CopySize; i++)
		{
			ArrBackUp[i] = ArrPtr[i];
			
		}
		

		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}



		ArrPtr = ArrBackUp;
		ArrCount = _Value;


		

	}

protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;

};

#include <iostream>

class Number
{
private:
	int Value;

public:
	// 맴버 이니셜라이저.
	Number(int _Value)
		: Value(_Value)
	{

	}

	int* operator[]( size_t   _Value)
	{
		int Arr[10000];
		for (int i = 0; i < _Value; i++)
		{
			Arr[i] = 0;
		}
		return Arr;
	}


	// 클래스가 연산자를 사용할수 있게 만들어주는 것.
	int operator+(int _Value)
	{
		return Value + _Value;
	}

	int operator-(int _Value)
	{
		return Value - _Value;
	}

	int operator*(int _Value)
	{
		return Value * _Value;
	}

	int operator/(int _Value)
	{
		return Value / _Value;
	}
	int operator%(int _Value)
	{
		return Value % _Value;
	}


	//증감 연산자
	int operator+=(int _Value)
	{
		Value = Value + _Value;
		return Value;
	}

	int operator-=(int _Value)
	{
		Value = Value - _Value;
		return Value;
	}

	int operator*=(int _Value)
	{
		Value = Value * _Value;
		return Value;
	}

	int operator/=(int _Value)
	{
		Value = Value / _Value;
		return Value;
	}
	int operator%=(int _Value)
	{
		Value = Value % _Value;
		return Value;
	}


	int operator++()
	{
		Value = Value +1;
		return Value;
	}


	int operator--()
	{
		Value = Value - 1;
		return Value;
	}




	//비교 연산자
	bool operator==(int _Value)
	{
		if (Value == _Value) {
			return true;
		}

		return false;
	}


	bool operator<(int _Value)
	{
		if (Value < _Value) {
			return true;
		}

		return false;
	}
	bool operator>(int _Value)
	{
		if (Value > _Value) {
			return true;
		}

		return false;
	}


	bool operator!=(int _Value)
	{
		if (Value != _Value) {
			return true;
		}

		return false;
	}

	bool operator>=(int _Value)
	{
		if (Value >= _Value) {
			return true;
		}

		return false;
	}

	bool operator<=(int _Value)
	{
		if (Value <= _Value) {
			return true;
		}

		return false;
	}

	//논리 연산자
	bool operator!()
	{
		if (Value ==false ) {
			return true;
		}

		return false;
	}

	bool operator&&(int _Value)
	{
		if (Value ==_Value ) {
			return true;
		}

		return false;
	}


	bool operator||(int _Value)
	{

	}

};


int main()
{
	{
		// 자신이 논리적으로 이 연산자를 이렇게 만들면 되겠다 할수 있는 

		Number Value = 10;
		int result = 0;
		
		
		result = Value + 10;
		result = Value - 5;
		result = Value * 2;
		result = Value / 5;
		result = Value % 3;


		++Value;
		//Value++;
		--Value;
		//Value--;

		if (Value == 10)
		{
			int a = 0;
		}

		if (Value < 10)
		{
			int a = 0;
		}

		if (Value > 10)
		{
			int a = 0;
		}

		if (Value <= 10)
		{
			int a = 0;
		}

		if (Value >= 10)
		{
			int a = 0;
		}


		if (Value != 10)
		{
			int a = 0;
		}

		result = !Value;


		if (Value && result)
		{
			int a = 0;
		}


		int* Test = Value[2000];
		int a = 0;
	}


}

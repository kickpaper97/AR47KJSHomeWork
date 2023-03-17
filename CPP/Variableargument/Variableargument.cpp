// 029_Variableargument.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void VarFunction(...)
{

}

//                100     108     116
void TestFunction(int _1, int _2, int _3)
{
    int* ValuePtr0 = &_1;
    // int* ValuePtr1 = &_2;
    // int* ValuePtr2 = &_3;

    int Value1 = ValuePtr0[0];
    int Value2 = ValuePtr0[2];
    int Value3 = ValuePtr0[4];

    // 100 + sizeof(int) * 2

    // __int64 Address0 = 0;
    // __int64 Address1 = 0;
    // __int64 Address2 = 0;

    // Address0 = (__int64)ValuePtr0;
    // Address1 = (__int64)ValuePtr1;
    // Address2 = (__int64)ValuePtr2;

}






void TestFunction2(int _1, ...)
{
    int count = 0;
    
    int* pnt = &_1;
    while (count <=_1 ) 
    {
        int Val = pnt[0 + count *(sizeof(int*)/sizeof(int))];
        printf_s("%d /  \n", Val);
        count++;
    }
}

//맨앞 인자의 메모리 위치를 이용하여 
// 특정 자료형의 다음 인자들의 메모리위치를 
// 순서대로 알아낼수 있다.



int main()
{
    VarFunction(2, 3, 4, 7, 9, 1, 1, 1, 1, 1);

    VarFunction("1", "2", "3", "4");

    VarFunction("1", 2, 3, "하하하하");

    TestFunction(10, 20, 30);

    TestFunction2(5, 1, 2, 3, 4, 5);

    std::cout << "Hello World!\n";

    return 0;
}

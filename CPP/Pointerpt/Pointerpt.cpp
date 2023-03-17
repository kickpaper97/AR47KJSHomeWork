// Pointerpt.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Test(int a, int b) {

	int* c = &a;
	int* d = &b;

	int sizec = sizeof(int*);

	printf_s("%d %d\n", *c, *d);
	printf_s("%p %p\n", c, d);


	

	const int& e = a;
	const int& f = b; 

	int sizee = sizeof(e);
	
	printf_s("%d %d\n", e, f);

	printf_s("%p %p\n", &e,&f );

	

}



int main()
{
	int a = 10;
	int b = 20;

	Test(a, b);

}

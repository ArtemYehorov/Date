#include"Date.h"

int main()
{
	Date a(1,1,2020);
	for (int i = 0; i < 365; i++)
	{
		system("cls");
		--a;
		a.Print();
		Sleep(100);
	}
}
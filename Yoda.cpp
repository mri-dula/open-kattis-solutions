#include <iostream>

using namespace std;

int main()
{
	int a, b;
	int aResult = 0, bResult = 0;
	cin >> a;
	cin >> b;
	int i = 10;
	int originalA = a, originalB = b;
	bool aNotFallen = false, bNotFallen = false;
	int ai = 1, bi = 1;
	for(int i = 10; true; i = i*10)
	{
		int x = a%10;
		int y = b%10;

		if(x >= y)
		{
			aResult = aResult + (x * ai);
			ai = ai* 10;
		}
		if(y >= x)
		{
			bResult = bResult + (y * bi);
		}
		if(x == y)
		{
			aNotFallen = true;
			bNotFallen = true;
		}
		a = a/10;
		b = b/10;

		if(a == 0 && b == 0)
			break;
	}
	if(aResult == 0 && !aNotFallen)
	{
		cout << "YODA\n";
	}
	else
	{
		cout << aResult << "\n";
	}
	if(bResult == 0 && !bNotFallen)
	{
		cout << "YODA\n";
	}
	else
	{
		cout << bResult << "\n";
	}
	return 0;
}
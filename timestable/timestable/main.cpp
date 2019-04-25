#include <iostream>

using namespace std;

int main()
{
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;

			if (j % 9 == 0)
			{
				cout << endl;
			}
		}
	}
}
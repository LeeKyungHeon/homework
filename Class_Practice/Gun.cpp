#include "pch.h"

#pragma comment(lib, "winmm.lib")

enum NonFire	// 불발 조건
{
	MAXDEGREE = 80,
	MAXCOUNT = 5,
};

class Gun
{
public:
	Gun(int count, int degree) : Count(count), Degree(degree)
	{
		cout << "방향키 위 : 발사" << endl << "방향키 아래 : 장전" << endl;
	}
	~Gun() {}

public:
	void Fire()
	{
		if (Count == 0)	// 총알 0발일시 재장전
		{
			Reload(); // 재장전 함수
		}

		if (Degree >= MAXDEGREE)	// 총 온도가 한계치 일 때
		{
			cout << "앗 뜨거! 식을때까지 기다려야 겠군..." << endl;

			Sleep(3000);

			Degree = 0;
		}

		else
		{
			cout << "빵야빵야!" << endl;
			Count--;
			Degree += 10;
		}

		cout << "남은 총알개수 : " << Count << endl;
		cout << "총 온도 : " << Degree << endl;
	}

	void Reload()
	{
		if (Count < 5)
		{
			cout << "제기랄 총알이 없잖아!! 어서 장전해야해!!" << endl;
			Count = 5;	// 총알 다시 충전
		}
		else // 총알 꽉찼는데 장전 또 누를시
		{
			cout << "꽉찼는데 뭘 장전이야. 쏘기나해!!" << endl;
		}

	}

private:
	int Count = 5;	// 총알 개수
	int Degree;		// 총알 온도
};


int main()
{
	Gun gun(5, 10);

	int key;

	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			key = _getch();

			switch (key)
			{
			case 72:
				gun.Fire();
				break;
			case 80:
				gun.Reload();
				break;
			}

		}
	}
}
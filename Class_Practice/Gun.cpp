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
			//Reload(); // 재장전 함수
			Count = 0;
			cout << "재장전이 필요해!!" << endl;				//0개가 되고 fire()함수를 호출시 다시 장전되어있는것을 바꿨습니다.
			//GunInfo();
			return;
		}

		if (Degree >= MAXDEGREE)	// 총 온도가 한계치 일 때
		{
			cout << "앗 뜨거! 식을때까지 기다려야 겠군..." << endl;

			int n = Degree / 10;

			for (int i = 0; i < n; i++)						//총의 온도를 0도가 될때까지 내려줍니다.
			{												//총의온도는 0.5초마다 10도씩 내려갑니다.
				Sleep(500);
				Degree -= 10;
				GunInfo();
			}
		}

		else
		{
			cout << "빵야빵야!" << endl;
			Count--;
			Degree += 10;
			GunInfo();
		}

		
	}

	void GunInfo() const									//총의 상태를 알려주는 함수를 따로 만들었습니다.
	{
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
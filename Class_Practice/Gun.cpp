#include <iostream>
#include <Windows.h>
#include <conio.h>

enum NonFire	// 불발 조건
{
	MAXDEGREE = 80,
	MAXCOUNT = 5,
	MINCOUNT = 0,
};

enum KeyBoard	// 키보드
{
	UP = 72,
	DOWN = 80,
};

enum Start	// 시작
{
	STARTCOUNT = 5,
	STARTDEGREE = 10,
};

class Gun
{
public:
	Gun(int count, int degree) : Count(count), Degree(degree)
	{
		std::cout << "방향키 위 : 발사" << std::endl << "방향키 아래 : 장전" << std::endl;	// 시작 시 조작법 안내
	}
	~Gun() {}

public:
	void Fire()
	{
		if (Count == MINCOUNT)	// 총알 0발일시 자동 재장전
		{
			std::cout << "재장전이 필요해!!" << std::endl;				// 0개가 되고 fire()함수를 호출시 다시 장전되어있는것을 바꿨습니다.
			return;
		}

		if (Degree >= MAXDEGREE)	// 총 온도가 한계치 일 때
		{
			std::cout << "앗 뜨거! 식을때까지 기다려야 겠군..." << std::endl;

			int n = Degree / 10;

			for (int i = 0; i < n; i++)						// 총의 온도를 0도가 될때까지 내려줌
			{												// 총의온도는 0.5초마다 10도씩 내려감
				Sleep(500);
				Degree -= 10;
				GunInfo();
			}
		}

		else // 그 외 상황은 총알 발사
		{
			std::cout << "빵야빵야!" << std::endl;
			Count--;
			Degree += 10;
			GunInfo();
		}
	}

	void GunInfo() const	// 총의 상태를 알려줌
	{
		std::cout << "남은 총알개수 : " << Count << std::endl;
		std::cout << "총 온도 : " << Degree << std::endl;
	}

	void Reload()	// 총알 장전
	{
		if (Count < MAXCOUNT)
		{
			std::cout << "제기랄 총알이 없잖아!! 어서 장전해야해!!" << std::endl;
			Count = MAXCOUNT;	// 총알 다시 충전
			GunInfo();
		}
		else // 총알 꽉찼는데 장전 또 누를시
		{
			std::cout << "꽉찼는데 뭘 장전이야. 쏘기나해!!" << std::endl;
			GunInfo();
		}
	}

private:
	int Count = MAXCOUNT;	// 총알 개수
	int Degree;				// 총알 온도
};


int main()
{
	Gun gun(STARTCOUNT, STARTDEGREE);

	int key;	// 키 값
		
	while (1)	// 게임 조작
	{
		if (_kbhit())
		{
			key = _getch();

			switch (key)
			{
			case UP:
				gun.Fire();
				break;
			case DOWN:
				gun.Reload();
				break;
			}

		}
	}
}

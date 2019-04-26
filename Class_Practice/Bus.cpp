#include "pch.h"
#include "vld.h"

class Bus
{
public:
	Bus(float sales) : Sales(sales) {}
	~Bus() {}

	virtual void Ride(int money) = 0;

protected:
	int Charge = 1000;	// 버스비
	float Sales;		// 할인률
};

class Adult : public Bus
{
public:
	Adult(float sales) : Bus(sales) {}
	~Adult() {}

	virtual void Ride(int money)
	{
		cout << "성인 입니다." << endl;
		cout << money << "원 받았습니다." << endl;
		cout << "거스름돈은 " << money - (Charge - Charge * Sales) << "원 입니다." << endl;
	}
};

class Student : public Bus
{
public:
	Student(float sales) : Bus(sales) {}
	~Student() {}

	virtual void Ride(int money)
	{
		cout << "학생 입니다." << endl;
		cout << money << "원 받았습니다." << endl;
		cout << "거스름돈은 " << money - (Charge - Charge * Sales) << "원 입니다." << endl;
	}
};

class Kids : public Bus
{
public:
	Kids(float sales) : Bus(sales) {}
	~Kids() {}
	virtual void Ride(int money)
	{
		cout << "유아 입니다." << endl;
		cout << money << "원 받았습니다." << endl;
		cout << "거스름돈은 " << money - (Charge - Charge * Sales) << "원 입니다." << endl;
	}

};

int main()
{
	int select;	// 유형 선택
	int money;	// 지불할 버스비

	while (1)
	{
		cout << "얼마 내시겠습니까?(버스비는 1000원) : ";
		cin >> money;
		if (money < 1000)
		{
			cout << "나가!! Get Out!!" << endl;
		}

		else
		{
			cout << "당신은 무엇입니까?(1. 성인 2. 학생 3. 유아) ";
			cin >> select;

			if (select == 1)
			{
				Adult adult(0.0);
				adult.Ride(money);
				break;
			}

			else if (select == 2)
			{
				Student student(0.2);
				student.Ride(money);
				break;
			}

			else if (select == 3)
			{
				Kids kids(0.5);
				kids.Ride(money);
				break;
			}
		}
	}
}
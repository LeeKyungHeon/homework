#include "pch.h"
#include "vld.h"

class Bus
{
public:
	Bus(float sales) : Sales(sales) {}
	~Bus() {}

	virtual void Ride(int money) = 0;

	virtual void CountCustomer() = 0;				//손님의 수를 세는 가상 함수입니다.
	virtual int PrintCustomer() = 0;				//손님의 수를 출력합니다.

protected:
	int Charge = 1000;	// 버스비
	float Sales;		// 할인률
	int m_nCustomer = 0;
};

class Adult : public Bus
{
public:
	Adult(float sales) : Bus(sales) {}
	~Adult() {}

	virtual void Ride(int money) override
	{
		cout << "성인 입니다." << endl;
		cout << money << "원 받았습니다." << endl;
		cout << "거스름돈은 " << money - (Charge - Charge * Sales) << "원 입니다." << endl;
	}

	virtual void CountCustomer() override
	{
		m_nCustomer++;
	}

	virtual int PrintCustomer() override
	{
		return m_nCustomer;
	}
};

class Student : public Bus
{
public:
	Student(float sales) : Bus(sales) {}
	~Student() {}

	virtual void Ride(int money) override
	{
		cout << "학생 입니다." << endl;
		cout << money << "원 받았습니다." << endl;
		cout << "거스름돈은 " << money - (Charge - Charge * Sales) << "원 입니다." << endl;
	}

	virtual void CountCustomer() override
	{
		m_nCustomer++;
	}

	virtual int PrintCustomer() override
	{
		return m_nCustomer;
	}
};

class Kids : public Bus
{
public:
	Kids(float sales) : Bus(sales) {}
	~Kids() {}
	virtual void Ride(int money) override
	{
		cout << "유아 입니다." << endl;
		cout << money << "원 받았습니다." << endl;
		cout << "거스름돈은 " << money - (Charge - Charge * Sales) << "원 입니다." << endl;
	}

	virtual void CountCustomer() override
	{
		m_nCustomer++;
	}

	virtual int PrintCustomer() override
	{
		return m_nCustomer;
	}

};

int main()
{
	int select;	// 유형 선택
	int money;	// 지불할 버스비

	Adult adult(0.0);
	Student student(0.2);
	Kids kids(0.5);
	while (1)
	{
		cout << "1. 운행 종료" << endl;
		cout << "얼마 내시겠습니까?(버스비는 1000원) : ";
		cin >> money;
		if (money == 1)
			break;
		else if (money < 1000)
		{
			cout << "나가!! Get Out!!" << endl;
		}

		else
		{
			cout << "당신은 무엇입니까?(1. 성인 2. 학생 3. 유아) ";
			cin >> select;

			if (select == 1)
			{
				adult.Ride(money);
				adult.CountCustomer();
				//break;
			}

			else if (select == 2)
			{
				student.Ride(money);
				student.CountCustomer();
				//break;
			}

			else if (select == 3)
			{
				kids.Ride(money);
				kids.CountCustomer();
				//break;
			}

			else if (select == 4)
			{
				break;
				
			}
		}
	}
	cout << "성인 : " << adult.PrintCustomer() << endl;
	cout << "학생 : " << student.PrintCustomer() << endl;
	cout << "유아 : " << kids.PrintCustomer() << endl;

	return 0;
}

/* 
가상함수를 override하는 부분에 overrid 키워드를 추가했고
운행 종료를 할 수 있게 만들었고, 손님의 수를 count해서
운행 종료시 Print 할 수 있도록 수정 했습니다.
*/
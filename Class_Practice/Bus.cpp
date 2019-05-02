#include <iostream>

enum BusData
{
	CHARGE = 1000,	// 버스비	
	CUSTOMER = 0,	// 손님 수
};

enum SocialPosition
{
	// 본문에 cin에 사용할 수
	ADULT = 1,		// 성인
	STUDENT = 2,	// 학생
	KIDS = 3,		// 유아
};

class Bus
{
public:
	Bus(float sales) : Sales(sales) {}
	~Bus() {}

	virtual void Ride(int money) = 0;

	virtual void CountCustomer() = 0;				// 손님의 수를 세는 가상 함수
	virtual int PrintCustomer() = 0;				// 손님의 수를 출력

protected:
	int Charge = CHARGE;	// 버스비
	float Sales;		// 할인률
	int m_nCustomer = CUSTOMER;
};

class Adult : public Bus
{
public:
	Adult(float sales) : Bus(sales) {}
	~Adult() {}

	virtual void Ride(int money) override	// 성인 탑승시 요금 계산
	{
		std::cout << "성인 입니다." << std::endl;
		std::cout << money << "원 받았습니다." << std::endl;
		std::cout << "거스름돈은 " << money - (Charge - Charge * Sales) << "원 입니다." << std::endl;
	}

	virtual void CountCustomer() override	// 성인 손님 수 계산
	{
		m_nCustomer++;
	}

	virtual int PrintCustomer() override	// 성인 손님 수 출력 
	{
		return m_nCustomer;
	}
};

class Student : public Bus
{
public:
	Student(float sales) : Bus(sales) {}
	~Student() {}

	virtual void Ride(int money) override	// 학생 탑승시 요금 계산
	{
		std::cout << "학생 입니다." << std::endl;
		std::cout << money << "원 받았습니다." << std::endl;
		std::cout << "거스름돈은 " << money - (Charge - Charge * Sales) << "원 입니다." << std::endl;
	}

	virtual void CountCustomer() override	// 학생 손님 수 계산
	{
		m_nCustomer++;
	}

	virtual int PrintCustomer() override	// 학생 손님 수 출력
	{
		return m_nCustomer;
	}
};

class Kids : public Bus
{
public:
	Kids(float sales) : Bus(sales) {}
	~Kids() {}
	virtual void Ride(int money) override	// 유아 탑승시 요금 계산
	{
		std::cout << "유아 입니다." << std::endl;
		std::cout << money << "원 받았습니다." << std::endl;
		std::cout << "거스름돈은 " << money - (Charge - Charge * Sales) << "원 입니다." << std::endl;
	}

	virtual void CountCustomer() override	// 유아 손님 수 계산
	{
		m_nCustomer++;
	}

	virtual int PrintCustomer() override	// 유아 손님 수 출력
	{
		return m_nCustomer;
	}

};

int main()
{
	int select;	// 유형 선택
	int money;	// 지불할 버스비

	float adultsales = 0.0f;	// 성인 할인율
	float studentsales = 0.2f;	// 학생 할인율
	float kidssales = 0.5f;		// 유아 할인율

	Adult adult(adultsales);
	Student student(studentsales);
	Kids kids(kidssales);

	while (1)
	{
		std::cout << "1. 운행 종료" << std::endl;	// 운행 종료 안내
		std::cout << "얼마 내시겠습니까?(버스비는 1000원) : ";	// 버스비 안내
		std::cin >> money;

		if (money == 1)	// 1 선택시 운행종료
			break;

		/*
		여기서 의아할수 있는데
		보통 현실에서 버스탑승 시스템은 신분에 맞게 금액을 내면 되지만
		제가 받은 문제에서는 금액을 내고 할인받는 식으로 문제를 만들라 한걸로 이해해서
		버스비 기준을 정해놓고 그 금액에 못 미칠시 버스를 못타는 방식으로 구현했습니다.
		*/

		else if (money < CHARGE)
		{
			std::cout << "나가!! Get Out!!" << std::endl;
		}

		else
		{
			std::cout << "당신은 무엇입니까?(1. 성인 2. 학생 3. 유아 4. 운행종료) ";
			std::cin >> select;

			if (select == ADULT)
			{
				adult.Ride(money);
				adult.CountCustomer();
			}

			else if (select == STUDENT)
			{
				student.Ride(money);
				student.CountCustomer();
			}

			else if (select == KIDS)
			{
				kids.Ride(money);
				kids.CountCustomer();
			}

			else if (select == 4)
			{
				break;
			}
		}
	}

	// 운행종료후 출력

	std::cout << "성인 : " << adult.PrintCustomer() << std::endl;
	std::cout << "학생 : " << student.PrintCustomer() << std::endl;
	std::cout << "유아 : " << kids.PrintCustomer() << std::endl;

	return 0;
}

/*
가상함수를 override하는 부분에 overrid 키워드를 추가했고
운행 종료를 할 수 있게 만들었고, 손님의 수를 count해서
운행 종료시 Print 할 수 있도록 수정 했습니다.
*/

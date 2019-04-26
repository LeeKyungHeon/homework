#include "pch.h"
#include "vld.h"

class Bus
{
public:
	Bus(float sales) : Sales(sales) {}
	~Bus() {}

	virtual void Ride(int money) = 0;

protected:
	int Charge = 1000;	// ������
	float Sales;		// ���η�
};

class Adult : public Bus
{
public:
	Adult(float sales) : Bus(sales) {}
	~Adult() {}

	virtual void Ride(int money)
	{
		cout << "���� �Դϴ�." << endl;
		cout << money << "�� �޾ҽ��ϴ�." << endl;
		cout << "�Ž������� " << money - (Charge - Charge * Sales) << "�� �Դϴ�." << endl;
	}
};

class Student : public Bus
{
public:
	Student(float sales) : Bus(sales) {}
	~Student() {}

	virtual void Ride(int money)
	{
		cout << "�л� �Դϴ�." << endl;
		cout << money << "�� �޾ҽ��ϴ�." << endl;
		cout << "�Ž������� " << money - (Charge - Charge * Sales) << "�� �Դϴ�." << endl;
	}
};

class Kids : public Bus
{
public:
	Kids(float sales) : Bus(sales) {}
	~Kids() {}
	virtual void Ride(int money)
	{
		cout << "���� �Դϴ�." << endl;
		cout << money << "�� �޾ҽ��ϴ�." << endl;
		cout << "�Ž������� " << money - (Charge - Charge * Sales) << "�� �Դϴ�." << endl;
	}

};

int main()
{
	int select;	// ���� ����
	int money;	// ������ ������

	while (1)
	{
		cout << "�� ���ðڽ��ϱ�?(������� 1000��) : ";
		cin >> money;
		if (money < 1000)
		{
			cout << "����!! Get Out!!" << endl;
		}

		else
		{
			cout << "����� �����Դϱ�?(1. ���� 2. �л� 3. ����) ";
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
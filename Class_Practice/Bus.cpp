#include "pch.h"
#include "vld.h"

class Bus
{
public:
	Bus(float sales) : Sales(sales) {}
	~Bus() {}

	virtual void Ride(int money) = 0;

	virtual void CountCustomer() = 0;				//�մ��� ���� ���� ���� �Լ��Դϴ�.
	virtual int PrintCustomer() = 0;				//�մ��� ���� ����մϴ�.

protected:
	int Charge = 1000;	// ������
	float Sales;		// ���η�
	int m_nCustomer = 0;
};

class Adult : public Bus
{
public:
	Adult(float sales) : Bus(sales) {}
	~Adult() {}

	virtual void Ride(int money) override
	{
		cout << "���� �Դϴ�." << endl;
		cout << money << "�� �޾ҽ��ϴ�." << endl;
		cout << "�Ž������� " << money - (Charge - Charge * Sales) << "�� �Դϴ�." << endl;
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
		cout << "�л� �Դϴ�." << endl;
		cout << money << "�� �޾ҽ��ϴ�." << endl;
		cout << "�Ž������� " << money - (Charge - Charge * Sales) << "�� �Դϴ�." << endl;
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
		cout << "���� �Դϴ�." << endl;
		cout << money << "�� �޾ҽ��ϴ�." << endl;
		cout << "�Ž������� " << money - (Charge - Charge * Sales) << "�� �Դϴ�." << endl;
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
	int select;	// ���� ����
	int money;	// ������ ������

	Adult adult(0.0);
	Student student(0.2);
	Kids kids(0.5);
	while (1)
	{
		cout << "1. ���� ����" << endl;
		cout << "�� ���ðڽ��ϱ�?(������� 1000��) : ";
		cin >> money;
		if (money == 1)
			break;
		else if (money < 1000)
		{
			cout << "����!! Get Out!!" << endl;
		}

		else
		{
			cout << "����� �����Դϱ�?(1. ���� 2. �л� 3. ����) ";
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
	cout << "���� : " << adult.PrintCustomer() << endl;
	cout << "�л� : " << student.PrintCustomer() << endl;
	cout << "���� : " << kids.PrintCustomer() << endl;

	return 0;
}

/* 
�����Լ��� override�ϴ� �κп� overrid Ű���带 �߰��߰�
���� ���Ḧ �� �� �ְ� �������, �մ��� ���� count�ؼ�
���� ����� Print �� �� �ֵ��� ���� �߽��ϴ�.
*/
#include "pch.h"
#include "vld.h"

//#pragma comment(lib, "winmm.lib")

enum NonFire	// �ҹ� ����
{
	MAXDEGREE = 80,
	MAXCOUNT = 5,
};

class Gun
{
public:
	Gun(int count, int degree) : Count(count), Degree(degree)
	{
		cout << "����Ű �� : �߻�" << endl << "����Ű �Ʒ� : ����" << endl;
	}
	~Gun() {}

public:
	void Fire()
	{
		if (Count == 0)	// �Ѿ� 0���Ͻ� ������
		{
			Reload(); // ������ �Լ�
		}

		if (Degree >= MAXDEGREE)	// �� �µ��� �Ѱ�ġ �� ��
		{
			cout << "�� �߰�! ���������� ��ٷ��� �ڱ�..." << endl;

			Sleep(3000);	// 3�ʵ��� �� �µ� ���

			Degree = 0;
		}

		else
		{
			cout << "���߻���!" << endl;
			Count--;
			Degree += 10;
		}

		cout << "���� �Ѿ˰��� : " << Count << endl;
		cout << "�� �µ� : " << Degree << endl;
	}

	void Reload()
	{
		if (Count < 5)
		{
			cout << "����� �Ѿ��� ���ݾ�!! � �����ؾ���!!" << endl;
			Count = 5;	// �Ѿ� �ٽ� ����
		}
		else // �Ѿ� ��á�µ� ���� �� ������
		{
			cout << "��á�µ� �� �����̾�. ��⳪��!!" << endl;
		}

	}

private:
	int Count = 5;	// �Ѿ� ����
	int Degree;		// �Ѿ� �µ�
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
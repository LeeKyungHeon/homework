#include "pch.h"

#pragma comment(lib, "winmm.lib")

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
			//Reload(); // ������ �Լ�
			Count = 0;
			cout << "�������� �ʿ���!!" << endl;				//0���� �ǰ� fire()�Լ��� ȣ��� �ٽ� �����Ǿ��ִ°��� �ٲ���ϴ�.
			//GunInfo();
			return;
		}

		if (Degree >= MAXDEGREE)	// �� �µ��� �Ѱ�ġ �� ��
		{
			cout << "�� �߰�! ���������� ��ٷ��� �ڱ�..." << endl;

			int n = Degree / 10;

			for (int i = 0; i < n; i++)						//���� �µ��� 0���� �ɶ����� �����ݴϴ�.
			{												//���ǿµ��� 0.5�ʸ��� 10���� �������ϴ�.
				Sleep(500);
				Degree -= 10;
				GunInfo();
			}
		}

		else
		{
			cout << "���߻���!" << endl;
			Count--;
			Degree += 10;
			GunInfo();
		}

		
	}

	void GunInfo() const									//���� ���¸� �˷��ִ� �Լ��� ���� ��������ϴ�.
	{
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
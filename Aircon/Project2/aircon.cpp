#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>	/// Ű���� �������� �Լ� �߰�
using namespace std;

class Airconditional
{
public:
	Airconditional() { }

	bool PowerCheck() const { return power; }		// ���� ON / OFF Ȯ���մϴ�.
	void SetPower() { power = !power; }				// ������ �ݴ�� ����ϴ�.

	void SetDegree(int C) { degree = C; }
	int GetDegree() const { return degree; }		//��¸� �ϱ⿡ const�� �������ϴ�.

	void DegreeControl()							//�������� ������ ���� �ð� �� �µ��� ���������� �߽��ϴ�.
	{
		bool power = PowerCheck();

		if (power == false)							//������ OFF�� �۵����� �ʽ��ϴ�.
		{
			return;
		}

		while (1)
		{
			if (GetTickCount() % 1000 == 0)			//���¹��� �߸𸣳� �˻��ؼ� ����ϴ�.
			{
				system("cls");
				cout << "Now Degree : " << degree << endl;
				degree--;

				if (kbhit())	/// Ű���� ����ư ���� �� ������ ����.
				{
					key = getch();

					switch (key)
					{
					case 72:
						cout << "��� �� �������� �����ϴ�." << endl;
						UpDegree();	/// �׸��� �������� �����Ƿ� �ٽ� �µ� ���
						break;
					}
				}

				if (degree < 15)	/// �����µ� 15�� �Ǹ� �ڵ����� ����.
				{
					cout << "�����µ� ����. ������ �����ϰڽ��ϴ�." << endl;
					UpDegree();		/// �׸��� �������� �����Ƿ� �ٽ� �µ� ���
				}
			}
		}
	}

	void UpDegree()	/// �߰��� �Լ�, ������ �������� �µ� ���
	{
		bool power = PowerCheck();

		if (power == false)							//������ OFF�� �۵����� �ʽ��ϴ�.
		{
			return;
		}

		while (1)
		{
			if (GetTickCount() % 1000 == 0)			//���¹��� �߸𸣳� �˻��ؼ� ����ϴ�.
			{
				system("cls");
				cout << "Now Degree : " << degree << endl;
				degree++;

				if (kbhit())	/// Ű���� ����ư ���� �� ������ �۵�.
				{
					key = getch();

					switch (key)
					{
					case 72:
						cout << "��� �� �������� �����ϴ�." << endl;
						DegreeControl();	/// �׸��� �������� �����Ƿ� �ٽ� �µ� ����
						break;
					}
				}

				if (degree > 30)		/// �Ѱ�µ� 30�� �Ǹ� �ڵ����� �۵�.
				{
					cout << "�����µ� ����. �������� �����ϰڽ��ϴ�." << endl;
					DegreeControl();	/// �׸��� �������� �����Ƿ� �ٽ� �µ� ����
				}
			}
		}
	}	

private:
	bool power = false;								//false�� OFF, true�� ON���� ���� �߽��ϴ�.

	int key;	///	Ű���尪 �޾ƿ���

	int degree = 0;
	size_t Time = 0;								//�ð� ���ε� ���̳ʽ��� �ȳ��ò����� size_t�� ���� �߽��ϴ�.
};

int main()
{
	Airconditional air;

	air.SetDegree(30);
	air.SetPower();
	air.DegreeControl();

	getchar();										//ȭ����!
	return 0;
}
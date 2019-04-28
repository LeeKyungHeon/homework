#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>	/// 키보드 쓰기위한 함수 추가
using namespace std;

class Airconditional
{
public:
	Airconditional() { }

	bool PowerCheck() const { return power; }		// 전원 ON / OFF 확인합니다.
	void SetPower() { power = !power; }				// 전원을 반대로 만듭니다.

	void SetDegree(int C) { degree = C; }
	int GetDegree() const { return degree; }		//출력만 하기에 const를 붙혔습니다.

	void DegreeControl()							//에어컨이 켜지면 일정 시간 뒤 온도가 내려가도록 했습니다.
	{
		bool power = PowerCheck();

		if (power == false)							//전원이 OFF면 작동하지 않습니다.
		{
			return;
		}

		while (1)
		{
			if (GetTickCount() % 1000 == 0)			//쓰는법은 잘모르나 검색해서 썼습니다.
			{
				system("cls");
				cout << "Now Degree : " << degree << endl;
				degree--;

				if (kbhit())	/// 키보드 위버튼 누를 시 에어컨 종료.
				{
					key = getch();

					switch (key)
					{
					case 72:
						cout << "잠시 후 에어컨이 꺼집니다." << endl;
						UpDegree();	/// 그리고 에어컨을 껐으므로 다시 온도 상승
						break;
					}
				}

				if (degree < 15)	/// 적정온도 15도 되면 자동으로 종료.
				{
					cout << "적정온도 도달. 전원을 종료하겠습니다." << endl;
					UpDegree();		/// 그리고 에어컨을 껐으므로 다시 온도 상승
				}
			}
		}
	}

	void UpDegree()	/// 추가한 함수, 에어컨 꺼졌을시 온도 상승
	{
		bool power = PowerCheck();

		if (power == false)							//전원이 OFF면 작동하지 않습니다.
		{
			return;
		}

		while (1)
		{
			if (GetTickCount() % 1000 == 0)			//쓰는법은 잘모르나 검색해서 썼습니다.
			{
				system("cls");
				cout << "Now Degree : " << degree << endl;
				degree++;

				if (kbhit())	/// 키보드 위버튼 누를 시 에어컨 작동.
				{
					key = getch();

					switch (key)
					{
					case 72:
						cout << "잠시 후 에어컨이 켜집니다." << endl;
						DegreeControl();	/// 그리고 에어컨을 켰으므로 다시 온도 감소
						break;
					}
				}

				if (degree > 30)		/// 한계온도 30도 되면 자동으로 작동.
				{
					cout << "설정온도 감지. 에어컨을 가동하겠습니다." << endl;
					DegreeControl();	/// 그리고 에어컨을 켰으므로 다시 온도 감소
				}
			}
		}
	}	

private:
	bool power = false;								//false면 OFF, true면 ON으로 설정 했습니다.

	int key;	///	키보드값 받아오기

	int degree = 0;
	size_t Time = 0;								//시간 값인데 마이너스는 안나올꺼같아 size_t로 선언 했습니다.
};

int main()
{
	Airconditional air;

	air.SetDegree(30);
	air.SetPower();
	air.DegreeControl();

	getchar();										//화이팅!
	return 0;
}
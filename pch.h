#pragma once

#include <Windows.h>

#include <iostream>
#include <iomanip>
#include <conio.h>

#include <vector>
#include <map>
#include <algorithm>
#include <bitset>

#include <functional>

#include <cstdlib>
#include <cassert>
#include <ctime>

#include <initializer_list>

#include <assert.h>

using namespace std;

// ��ũ��
#define SAFE_DELETE(x)      { if((x)!= nullptr) { delete (x); (x) = nullptr; } }
#define SAFE_DELETE_ARR(x)  { if((x)!= nullptr) { delete[] (x); (x) = nullptr; } }

/////////////////////// �����ڷ� URL //////////////////////

// ���� ����ڽ� �ּ�	: https://www.dropbox.com/sh/zd0eaxb16v5b10u/AADsEokgGAsZcbTcOdhonHuda?dl=0
// �ҿ� �ּ�				: https://soen.kr
// �ڵ�� �ּ�			: https://codeup.kr
// �ڵ�ñ׳� �ּ�		: https://codesignal.com

//void gotoxy(int x, int y)
//{
//	COORD pos = { x,y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
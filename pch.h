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

// 매크로
#define SAFE_DELETE(x)      { if((x)!= nullptr) { delete (x); (x) = nullptr; } }
#define SAFE_DELETE_ARR(x)  { if((x)!= nullptr) { delete[] (x); (x) = nullptr; } }

/////////////////////// 수업자료 URL //////////////////////

// 강의 드랍박스 주소	: https://www.dropbox.com/sh/zd0eaxb16v5b10u/AADsEokgGAsZcbTcOdhonHuda?dl=0
// 소엔 주소				: https://soen.kr
// 코드업 주소			: https://codeup.kr
// 코드시그널 주소		: https://codesignal.com

//void gotoxy(int x, int y)
//{
//	COORD pos = { x,y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
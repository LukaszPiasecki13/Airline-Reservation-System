#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;
static class Global_Function
{
public:
	static void Clean();
	static void GoToxy(const int x, const int y);  //a function that places the cursor anywhere
};
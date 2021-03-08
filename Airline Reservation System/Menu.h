#pragma once
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "Global_Function.h"
#include <map>


using namespace std;
class Menu
{
private:
    const int start_pos{ 6};
    int current_pos{};
    int previous_pos{};
    int c_last_pos{};
    int c_stock_min{};
    int c_stock_max{};
    void PaintMainMenu(map<int,string> airport_list, string tekst);


public:
    Menu(int list_size);
    void SetStock(int stock_min, int stock_max);
    int GetStock_min();
    int GetStock_max();
    int MainMenu(map<int, string> airport_list, string tekst);

};


#pragma once
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Global_Function.h"
#include "File_Services.h"

using namespace std;

class Plane
{
private:
		map<int, string> seat_status;
		int number_of_seats{120};
		void Paint_Seats(string air_a, string air_b);
		void Comment();
		const int start_pos_ver{ 6 };
		const int start_pos_hor{ 3 };
		int current_pos_ver;
		int previous_pos_ver;
		int current_pos_hor;
		int previous_pos_hor;
		int c_last_pos_ver{20+ start_pos_ver-1 };
		int c_last_pos_hor{ number_of_seats/20*3 +3};
		int c_stock_min{};
		int c_stock_max{};
		

public:
	Plane(int a);
	int price{};
	int Choose_seat(string air_a, string air_b);
	void Change_Seat_Status(int seat);

	

};


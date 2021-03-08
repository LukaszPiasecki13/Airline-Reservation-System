// Airline Reservation System.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "Menu.h"
#include "Plane.h"
#include <string>
#include "File_Services.h"

using namespace std;
bool Payment(string first_airport, string second_airport, int price)
{
	Global_Function::Clean(); // odświerzanie wszystkiego
	cout << "Relation : " << first_airport << " -> " << second_airport << endl;
	cout << "You must payment : " << price << "$" << endl;
	cout << "ENTER => PAY" << endl;
	cout << "ESC => QUIT" << endl;
	while (true) //przesuwanie strzałki
	{
		switch (_getch())
		{
		case 27: //ESC       
			return false;

		case 13:
			//jeżeli wciśnięto Enter, sprawdź wybraną opcję i wykonaj odpowiednią akcję
		{
			Global_Function::Clean(); // odświerzanie wszystkiego
			cout << "Thanks You for reservation flight : " << first_airport << " -> " << second_airport << endl;
			cout << "Now, please, pay money to the account number :15216500000515469 " << endl;
			_getch();
			return true;
		}

		}
	}
}

int main()
{
	
		int chosen_airport1{};
		int chosen_airport2{};
		Plane plane1(120);

		do
		{
			File_Services airports_list("airports.txt");
			map<int, string> list1;
			list1 = airports_list.Read_File();
			Menu menu(list1.size());


			chosen_airport1 = menu.MainMenu(list1, "Choose start airport : ");

			string first_air = list1[chosen_airport1 + 1];
			list1.erase(chosen_airport1 + 1);
			chosen_airport2 = menu.MainMenu(list1, "Choose end airport :");

			string second_air = list1[chosen_airport2 + 2];

			int chosen_place{};
			int i{};

			i++;
			chosen_place = plane1.Choose_seat(first_air, second_air);
			if (chosen_place == 0)
			{ }
			else
			{
				int price = plane1.price;
				if (Payment(first_air, second_air, price))
					plane1.Change_Seat_Status(chosen_place);
			}
		

	} while (true);
}
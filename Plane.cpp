#include "Plane.h"



Plane::Plane(int a)
{
    number_of_seats = a;

    File_Services seats_list("seats.txt");
    map<int, string> seats1;
    seats1 = seats_list.Read_File();
    int i{};
    for (pair<int, string> element : seats1)
    {  
        seat_status[i] = element.second;
        i = i++;
    }
}

int Plane:: Choose_seat(string air_a, string air_b)
{
    Paint_Seats(air_a, air_b);
    current_pos_ver = start_pos_ver;
    previous_pos_ver = current_pos_ver;
    current_pos_hor = start_pos_hor;
    previous_pos_hor = current_pos_hor;
    while (true) //przesuwanie strza³ki
    {
        Paint_Seats(air_a, air_b);
        int h{};
        switch (_getch())
        {
            
        case 72: //strza³ka w górê
            if (start_pos_ver < current_pos_ver) current_pos_ver--;
            else if (current_pos_ver == start_pos_ver)
            {
                current_pos_ver = c_last_pos_ver;
            }
            break;

        case 80: //strza³ka w dó³
            if (current_pos_ver != c_last_pos_ver) current_pos_ver++;
            else current_pos_ver = start_pos_ver;
            break;

        case 77: //strza³ka w prawo
            
            if (current_pos_hor != (c_last_pos_hor))
                if (current_pos_hor == 9)
                {
                    h = 3;
                    current_pos_hor = current_pos_hor + 3 + h;
                }
                else current_pos_hor = current_pos_hor + 3;
                
            else
            {
                h = 0;
                current_pos_hor = start_pos_hor;
            }
            break;

        case 75: //strza³ka w lewo

            if (current_pos_hor != start_pos_hor)
                if (current_pos_hor == 15)
                {
                    h = 3;
                    current_pos_hor = current_pos_hor - 3 - h;
                }
                else current_pos_hor = current_pos_hor - 3;

            else
            {
                h = 0;
                current_pos_hor = c_last_pos_hor;
            }
            break;

        case 13: 
            //je¿eli wciœniêto Enter, sprawdŸ wybran¹ opcjê i wykonaj odpowiedni¹ akcjê
        {
            int place_hor;
            int result;
            place_hor = (current_pos_hor - start_pos_hor) / 3 ;   
            result = (current_pos_ver - start_pos_ver) * 6 + place_hor ;
            if (place_hor >= 4)
            {
                result--;
            }   
            if ((current_pos_ver >= 6) & (current_pos_ver <= 11)) price = 240;
            else if ((current_pos_ver > 11) & (current_pos_ver <= 21)) price = 200;
            else if ((current_pos_ver > 21) & (current_pos_ver <= 26)) price = 270;

            return result;
        }
        case 27: //ESC       
            return false;
            
        }
        Global_Function::GoToxy(previous_pos_hor, previous_pos_ver + 1);  //czyszczenie strza³ki wyboru
        cout << " ";
    }



	return 1; 
}


void Plane::Paint_Seats(string air_a, string air_b)
{
	Global_Function::Clean(); // odœwierzanie wszystkiego
    cout << "Relation : " << air_a << " -> " << air_b << endl;
    cout << "Choose seat "<< endl;
    for (int n{}; n < 20; n++)
    {
        int h{};
        for (int i{};  i  < number_of_seats / 20; i++)
        {
            
            if (i == 3)
            {
                Global_Function::GoToxy(3 + 3 * i , n+ start_pos_ver+1);
                cout << "   " << "[" << seat_status[6*n+i] << "]" << endl;
                h = 1;
            }
            else
            {
                if (i == 5)
                {
                    Global_Function::GoToxy(3 + 3 * (i+h), n+ start_pos_ver+1);
                    cout << "[" << seat_status[6 * n + i] << "]          |" << endl;
                }
                else if (i == 4)
                {
                    Global_Function::GoToxy(3 + 3 * (i + h), n + start_pos_ver + 1);
                    cout << "[" << seat_status[6 * n + i] << "]" << endl;
                }
                           
                else 
                {
                    Global_Function::GoToxy(3 + 3 * (i + h), n + start_pos_ver + 1);
                    h = 0;
                    cout << "[" << seat_status[6 * n + i] << "]" << endl;
                }
            }
        }
    }


    Global_Function::GoToxy(current_pos_hor, current_pos_ver + 1);  //rysowanie strza³ki wyboru
    cout << static_cast <char>(16);

    Comment();

    previous_pos_ver = current_pos_ver; //obs³uga klawiatury
    previous_pos_hor = current_pos_hor; //obs³uga klawiatury
}

void Plane::Comment()
{
    Global_Function::GoToxy(80, 9);  //rysowanie strza³ki wyboru
    cout << "CHOOSE SEAT" << endl;
    Global_Function::GoToxy(80, 10);
    if ((current_pos_ver >= 6) & (current_pos_ver <= 11))
    {
        cout << "Class +" << endl;
        Global_Function::GoToxy(80, 11);
        cout << "Price : 240 $" << endl;
    }
    else if ((current_pos_ver > 11) & (current_pos_ver <= 21))
    {
        cout << "Standard" << endl;
        Global_Function::GoToxy(80, 11);
        cout << "Price : 200 $" << endl;
    }
    else if ((current_pos_ver > 21) & (current_pos_ver <= 26))
    {
        cout << "Clas ++" << endl;
        Global_Function::GoToxy(80, 11);
        cout << "Price : 270 $" << endl;
    }
    
  

}

void Plane::Change_Seat_Status(int seat)
{
    seat_status[seat] = 'x';
    File_Services seats_list("seats.txt");
    seats_list.Write_File(seat_status);
    
}
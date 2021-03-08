#include "Global_Function.h"

void Global_Function::Clean()
{
    system("cls");
    cout << "                            AIRLINE RESERVATION SYSTEM" << endl;
    cout << "                                                                             By Lukasz Piasecki    " << endl;
    cout << "                                                                             WIEiT Elektronika 2020    " << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

   
}

void Global_Function::GoToxy(const int x, const int y) //a function that places the cursor anywhere
{
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
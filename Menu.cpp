#include "Menu.h"


Menu::Menu(int list_size)
{
    
    c_last_pos = list_size+ start_pos-2;
}

void Menu::SetStock(int stock_min, int stock_max)
{
    c_stock_min = stock_min;
    c_stock_max = stock_max;
}

int Menu::GetStock_min()
{
    return c_stock_min;
}
int Menu::GetStock_max()
{
    return c_stock_max;
}

int Menu::MainMenu(map<int, string> airport_list, string tekst)
{
    c_last_pos = airport_list.size() + start_pos - 2;
    while (true) //p�tla g��wna programu
    {
        current_pos = start_pos;
        previous_pos = current_pos;
        PaintMainMenu(airport_list, tekst); //rysowanie menu
        while (true) //przesuwanie strza�ki
        {
            PaintMainMenu(airport_list, tekst);

            switch (_getch())
            {
            case 72: //strza�ka w g�r�
                if (start_pos < current_pos) current_pos--;
                else if (current_pos == start_pos)
                {
                    current_pos = c_last_pos;
                }
                break;

            case 80: //strza�ka w d�
                if (current_pos != c_last_pos) current_pos++;
                else current_pos = start_pos;
                break;

            case 13: //enter
                //je�eli wci�ni�to Enter, sprawd� wybran� opcj� i wykonaj odpowiedni� akcj�
                return current_pos - start_pos;
            }
            Global_Function::GoToxy(1, previous_pos + 1);  //czyszczenie strza�ki wyboru
            cout << " ";
        }
    }
}

void Menu::PaintMainMenu(map<int, string>airport_list, string tekst)
{
    Global_Function::Clean(); // od�wierzanie wszystkiego

    cout << tekst << endl;
    int i{};
    for (pair<int, string> element : airport_list)
    {     
        i = i++;
        Global_Function::GoToxy(3,  start_pos+i);
        int count = element.first; // Accessing KEY from element
        string word = element.second; // Accessing VALUE from element
        cout << word << endl;
    }

    Global_Function::GoToxy(1, current_pos + 1);  //rysowanie strza�ki wyboru
    cout << static_cast <char>(16);

    previous_pos = current_pos; //obs�uga klawiatury
}

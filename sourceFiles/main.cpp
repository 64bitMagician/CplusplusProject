#include "../headerFiles/departments.hpp"
#include "../headerFiles/menus.hpp"
#include "../headerFiles/products.hpp"
#include "../headerFiles/fileManipulation.hpp"
#include "../headerFiles/stringManipulation.hpp"
#include "../headerFiles/special.hpp"

#include<iostream>

#define STOCK_MENU 1
#define ADD_STOCK_MENU 2
#define CUT_OFF_STOCK_MENU 3
#define CURRENT_STOCK_VALUE_MENU 4
#define INCOME_MENU 5
#define EXIT 0



int main(){
    int accessed_menu;
    while(true)
    {   special::clearScreen();
        accessed_menu = main_menu();
        

        if(accessed_menu==STOCK_MENU){
            //Display Stock Menu
            display_stock_menu();
        }
        else if(accessed_menu==ADD_STOCK_MENU){
            stock_menu();
        }
        else if(accessed_menu==CUT_OFF_STOCK_MENU){

        }
        else if(accessed_menu==CURRENT_STOCK_VALUE_MENU){

        }
        else if(accessed_menu==INCOME_MENU){

        }
        else if(accessed_menu==0){
            std::cout<<"EXITING PROGRAM...";
            return 0;
        }
        else{
            std::cout<<"INVALID INPUT.TRY AGAIN\n\n";
        }
    }

    return 0;
}

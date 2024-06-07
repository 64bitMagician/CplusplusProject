#include<iostream>
#include<memory> // Include for smart pointers

#include "../headerFiles/fileManipulation.hpp"
#include "../headerFiles/menus.hpp"
#include "../headerFiles/departments.hpp"
#include "../headerFiles/products.hpp"
#include "../headerFiles/special.hpp"

int main_menu(){
    int accessed_menu;
    std::cout<<"                        MiniMarket Storage System\n";
    std::cout<<"================================================================================\n";
    std::cout<<"Press 1 to display stock\n";
    std::cout<<"Press 2 to add to stock\n";
    std::cout<<"Press 0 to exit the program\n";
    std::cout<<"================================================================================\n";
    std::cout<<"YOUR INPUT: ";
    std::cin>>accessed_menu;
    std::cout<<"\n";
    return accessed_menu;
}

void display_stock_menu(){
    special::clearScreen();
    std::string departmentFileName = "../dataFiles/departments.csv";
    std::cout<<"LIST OF DEPARTMENTS:\n";
    display_departments(departmentFileName);
    std::cout<<"WRITE THE NUMBER OF DEPARTMENT TO SHOW IT'S CAPACITY\n";
    std::cout<<"WRITE NUMBER 0 FOR TOTAL STOCK CAPACITY\n";
    int department_selected;
    std::cin>>department_selected;
    special::clearScreen();
    display_department_stock(departmentFileName, department_selected);
    special::waitForKeyPress();
    return;
}

void stock_menu(){
    special::clearScreen();
    std::string productsFileName = "../dataFiles/products.csv";
    std::cout<<"LIST OF PRODUCTS:\n";
    display_products(productsFileName);
    std::cout<<"OF WHICH PRODUCT DO YOU WISH TO ADD MORE OF?\n ENTER THE PRODUCT ID: ";
    int product_id;
    std::cin>>product_id;
    special::clearScreen();

    // Use smart pointers to manage memory efficiently
    std::shared_ptr<std::string> line = std::make_shared<std::string>(getCSVlineByID(productsFileName,product_id,PCOL_ID));
    Product product = retreive_product_object(*line);

    // IF CAPACITY IS FULL
    if(product.get_quantity()==product.get_maxQuantity()){
        std::cout<<"CAPACITY FULL: "<<product.quantityToMaxQuantityRatio()<<"\n";
        std::cout<<"CAN'T ADD ANY MORE PRODUCTS\n\n";
        special::waitForKeyPress();
        return;
    }

    std::cout<<"CURRENT QUANTITY OF '"<<product.get_name()<<"' "<<product.quantityToMaxQuantityRatio()<<"\n";
    std::cout<<"HOW MANY PRODUCTS OF THE SELECTED KIND YOU WANT TO ADD TO STOCK?\n";
    int quantity_to_be_added;
    std::cin>>quantity_to_be_added;
    
    product.add_product_stock(quantity_to_be_added);
    update_product_to_CSV(productsFileName,product);
    std::string departments_CSVfile ="../dataFiles/departments.csv";
    update_department_into_departmentsCSV(product);
    special::waitForKeyPress();
}

void cut_off_stock_menu(){

}

void current_stock_value_menu(){

}

void expected_income_menu(){
    
}

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>

#include "../headerFiles/fileManipulation.hpp"
#include "../headerFiles/products.hpp"
#include "../headerFiles/stringManipulation.hpp"
#include "../headerFiles/departments.hpp"
#include "../headerFiles/menus.hpp"

//PRODUCT CLASS METHODS
int Product::get_id(){
    return ID;
}
std::string Product::get_departements(){
    return departments;
}
std::string Product::get_prodType(){
    return prodType;
}
std::string Product::get_name(){
    return name;
}
int Product::get_quantity(){
    return quantity;
}
int Product::get_unitPrice(){
    return unitPrice;
}
int Product::get_maxQuantity(){
    return maxQuantity;
}

Product::Product(int PID,std::string Pdepartments,std::string PprodType,std::string Pname,int Pquantity, int PunitPrice,int PmaxQuantity){
    ID = PID;
    departments = Pdepartments;
    prodType = PprodType;
    name = Pname;
    quantity = Pquantity;
    unitPrice = PunitPrice;
    maxQuantity = PmaxQuantity;
}

int Product::quantity_to_be_added(){
    int can_add = maxQuantity - quantity;
    return can_add;
}

void Product::add_product_stock(int nb){
    if(quantity+nb<=maxQuantity){
        quantity+=nb;
        std::cout<<"THE QUANTITY OF '"<<name<<"' IS NOW "<<quantityToMaxQuantityRatio()<<"\n";
    }
    else{
        std::string number = std::to_string(quantity_to_be_added());
        std::cout<<"CAN'T ADD THAT MUCH MORE QUANTITY OF THIS PRODUCT\n";
        std::cout<<"YOU CAN'T ADD MORE THAN "<<number<<" PRODUCTS\n";
    }
}

std::string Product::quantityToMaxQuantityRatio(){
        std::string line;
        std::string current = std::to_string(quantity);
        std::string max = std::to_string(maxQuantity);
        line = current + "/" + max;
        
        return line;
    }


//FUNCTIONS
void display_products(std::string &file){
    // Use the function declared in fileManipulation.hpp
    std::vector<std::string> lines = returnVectorOfAllLinesFromFile(file);

    for (const auto& line : lines) {
        std::string prodID;
        std::string name;
        prodID = CSVlineGetWord(line,PCOL_ID);
        name = CSVlineGetWord(line,PCOL_NAME);
        std::cout << prodID << " " << name << std::endl;
    }
}

//This function will return a Product object, containing all the data passed within the passed CSV file.
//So you pass the CSV type line/string, and it returns an object with the data contained in that string.
Product retreive_product_object(std::string &line){
    std::vector<std::string> object_data = get_substrings_of_a_string(line,',');

    int ID;
    std::string Departments;
    std::string ProductType;
    std::string Name;
    int Quantity;
    int UnitPrice;
    int MaxQuantity;

    ID = stoi(object_data[0]);
    Departments = object_data[1];
    ProductType = object_data[2];
    Name = object_data[3];
    Quantity = stoi(object_data[4]);
    UnitPrice = stoi(object_data[5]);
    MaxQuantity = stoi(object_data[6]);
    
    Product product(ID,Departments,ProductType,Name,Quantity,UnitPrice,MaxQuantity);

    return product;
}

//This function returns the index(int) of the line in the department.csv where you want to change the data of the newly added product
std::string find_department_by_product(Product product){
    std::string departmentsFileName = "../dataFiles/departments.csv";
    std::vector<std::string> lines;

    lines = returnVectorOfAllLinesFromFile(departmentsFileName);

    int index=0;
    while(true){
        if(CSVlineGetWord(lines[index],COL_NAME)==product.get_departements())// if the the line containing the department name corelates with the department name of the product
            return lines[index];
        index++;
    }
}





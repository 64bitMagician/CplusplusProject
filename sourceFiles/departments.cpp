#include "../headerFiles/departments.hpp"
#include "../headerFiles/fileManipulation.hpp"
#include "../headerFiles/stringManipulation.hpp"
#include "../headerFiles/products.hpp"

#include <fstream>
#include <vector>
#include <string>
#include <iostream>


///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
//DEPARTMENT CLASS METHODS
///////////////////////////////////////////////////////////////////////////////////////////
//constructor
Department::Department(std::string PDepartmentName,int PdepartmetID,int PmaxCapacity,int PCurrentCapacity,std::string PproductQuantity){
    departmentName = PDepartmentName;
    departmentID = PdepartmetID;
    maxCapacity = PmaxCapacity;
    currentCapacity = PCurrentCapacity;
    product_and_quantity = PproductQuantity;
}
///////////////////////////////////////////////////////////////////////////////////////////
void Department::new_product_quantity(std::string product_name,int new_quantity){
    std::string element = product_name + std::to_string(new_quantity);
    product_and_quantity = element;
}
///////////////////////////////////////////////////////////////////////////////////////////
//setter functions
void Department::set_departmentName(std::string name) {
    departmentName = name;
}

void Department::set_departmentID(int id) {
    departmentID = id;
}

void Department::set_maxCapacity(int capacity) {
    maxCapacity = capacity;
}

void Department::set_currentCapacity(int capacity) {
    currentCapacity = capacity;
}

void Department::set_product_and_quantity(std::string prodQuantity) {
    product_and_quantity = prodQuantity;
}

void Department::set_product(Product product_passed) {
    product_ = product_passed;
}
///////////////////////////////////////////////////////////////////////////////////////////
//END OF CLASS METHODS
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
//FUNCTIONS

// Assuming you want to display departments by reading from a file
void display_departments(std::string &file) {
    // Use the function declared in fileManipulation.hpp
    std::vector<std::string> lines = returnVectorOfAllLinesFromFile(file);

    for (const auto& line : lines) {
        std::string depID;
        std::string name;
        depID = CSVlineGetWord(line,COL_ID);
        name = CSVlineGetWord(line,COL_NAME);
        std::cout << depID << " " << name << std::endl;
    }
}

//display_department_stock
// This function will return you the current stock of a certain department
// You give the name of the CSV file containing the departments, and the ID of the department you are looking for
// Instead of the ID int number, you can give the defined constants of the department ID's that appear
//in the departments header.
void display_department_stock(std::string &departmentFileName,int department_selected)
{
    std::ifstream file(departmentFileName);
    std::string line;
    int ID=0;

    //Consume First Line Of CSV
    getline(file,line);

    //Display the full Stock Capacity
    if(department_selected==0)
    {
        int MaxCapacity=0;
        int CurrentCapacity=0;

        while(getline(file,line)){
            MaxCapacity += stoi(CSVlineGetWord(line,COL_MAXCAPACITY));
            CurrentCapacity += stoi(CSVlineGetWord(line,COL_CURRENTCAPACITY));
        }

        std::cout<<"TOTAL STOCK CAPACITY\n";
        std::cout<<CurrentCapacity<<"/"<<MaxCapacity<<"\n";
        return;
    }

    line = getCSVlineByID(departmentFileName,department_selected,COL_ID);


    int MaxCapacity = stoi(CSVlineGetWord(line,COL_MAXCAPACITY));
    int CurrentCapacity = stoi(CSVlineGetWord(line,COL_CURRENTCAPACITY));

    std::cout<<"'"<<CSVlineGetWord(line,COL_NAME)<<"' "<<"STOCK CAPCITY\n";
    std::cout<<CurrentCapacity<<"/"<<MaxCapacity<<"\n";
    return;
}



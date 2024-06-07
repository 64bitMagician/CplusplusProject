#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include<vector>

#include "../headerFiles/departments.hpp"
#include "../headerFiles/menus.hpp"
#include "../headerFiles/products.hpp"
#include "../headerFiles/fileManipulation.hpp"
#include "../headerFiles/stringManipulation.hpp"

//returnVectorOfAllLinesFromFile
//You give this function the name of your file, and it will return a vector of strings containing all the lines from that File.
std::vector<std::string> returnVectorOfAllLinesFromFile(const std::string &fileName) {
    std::vector<std::string> lines;
    std::ifstream file(fileName);
    
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return lines;
    }
    
    std::string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    
    file.close();
    
    return lines;
}

//getCSVlineByID
// This function will return the line in a CSV that contains the passed ID
// You give the filepath/name of the file to open, the id from which you want to retreive the line, and the collumn at
// which the id's exist in the passed CSV file
std::string getCSVlineByID(std::string &fileName,int selectedID,int idCollumn){
    std::ifstream file(fileName);
    std::string line;
    int end=0;
    int ID=-1;

    getline(file,line);
    while(ID!=selectedID){
            getline(file,line);
            ID = stoi(CSVlineGetWord(line,idCollumn));
    }

    return line;
}

//This function is used in overwriting the given argument file with the passed vector of string lines argument.
void overwrite_file(std::string &fileName,std::vector<std::string> lines){
    std::ofstream file(fileName);
    if (!file) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    for(auto line:lines){
        file<<line<<"\n";
    }
}

//This function updates the modifications made on the product object into the CSV file
//You pass the name and path of the file as a string, then the object to be updated
void update_product_to_CSV(std::string file, Product product){
    // get the vector of lines within the CSV
    std::vector<std::string> lines = returnVectorOfAllLinesFromFile(file);
    int index = product.get_id()+1;
    lines[index] = "";
    std::string updated_line = "";

    updated_line = std::to_string(product.get_id())+","+product.get_departements()
    +","+product.get_prodType()+","+product.get_name()+","+std::to_string(product.get_quantity())
    +","+std::to_string(product.get_unitPrice())+","+std::to_string(product.get_maxQuantity());

    lines[index] = updated_line;

    std::string products_file = "../dataFiles/products.csv";
    overwrite_file(products_file,lines);
}

//In this function, you pass the line containing the data of a department, and it will return
//an department object containing all data from that line
Department get_department(std::string line){
    std::vector<std::string> substrings = get_substrings_of_a_string(line,',');

    std::string name = substrings[0];
    int departmentID = stoi(substrings[1]);
    int maxCapacity = stoi(substrings[2]);
    int currentCapacity = stoi(substrings[3]);
    std::string P_Q = substrings[4];
    Department department(name,departmentID,maxCapacity,currentCapacity,P_Q);
        
    return department;
}

void Department::display_info() const {
    std::cout << "Department Name: " << departmentName << std::endl;
    std::cout << "Department ID: " << departmentID << std::endl;
    std::cout << "Max Capacity: " << maxCapacity << std::endl;
    std::cout << "Current Capacity: " << currentCapacity << std::endl;
    std::cout << "Product and Quantity: " << product_and_quantity << std::endl;
}

//NOT FINISHED
//This function will be used to update the CSV based on the updated products of department objects.
//So an object is modified within the department vector, and that will be used to update the CSV,
//specifically the line of the department.
//
void update_department_into_departmentsCSV(Product product) {
    // extract CSV line of the corresponding department of product
    std::string line = find_department_by_product(product);

    // extract the data of that department using the constructor
    Department department = get_department(line);

    // Set the product for the department
    department.set_product(product);

    // Display department information
    department.display_info();

}



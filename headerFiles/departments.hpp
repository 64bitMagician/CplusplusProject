#ifndef DEPARTMENTS_HPP
#define DEPARTMENTS_HPP

#include "../headerFiles/products.hpp"

//Libraries included
#include<string>
#include<vector>

// defined constants respresenting the collumn number
#define COL_NAME 1
#define COL_ID 2
#define COL_MAXCAPACITY 3
#define COL_CURRENTCAPACITY 4
#define PRODUCT_QUANTITY 5

// defined constants representing the the department ID's
#define ID_SWEETS 1
#define ID_DIARY 2
#define ID_ENTERTAINMENT 3
#define ID_VEGETABLES 4
#define ID_FRUITS 5
#define ID_BEAUTY 6
#define ID_ALCOHOL 7
#define ID_JUICES 8
#define ID_CEREALS 9

//Department Class
class Department{
    private:
    std::string departmentName;
    int departmentID;
    int maxCapacity;
    int currentCapacity;
    std::string product_and_quantity;

    Product product_;

    public:

    Department(std::string PDepartmentName,int PdepartmetID,int PmaxCapacity,int PCurrentCapacity,std::string PproductQuantity);// it should call the function to make vector of prod_quantity

    //setter functions
    void set_departmentName(std::string name);
    void set_departmentID(int id);
    void set_maxCapacity(int capacity);
    void set_currentCapacity(int capacity);
    void set_product_and_quantity(std::string prodQuantity);
    void set_product(Product product);
    //end of setter functions
    
    void new_product_quantity(std::string product_name,int new_quantity);
    
    void get_products_in_vector();

    void display_info() const;
};


//FUNCTIONS
void display_departments(std::string &file);
void display_department_stock(std::string &departmentFileName,int department_selected);

#endif // DEPARTMENTS_HPP
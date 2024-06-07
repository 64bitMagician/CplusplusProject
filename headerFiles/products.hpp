#ifndef PRODUCTS_HPP
#define PRODUCTS_HPP

#include<string>

#define PCOL_ID 1
#define PCOL_NAME 4
#define PCOL_QUANTITY 5
#define PCOL_MAXQUANTITY 7

class Product{
    private:
        int ID;
        std::string departments;
        std::string prodType;
        std::string name;
        int quantity;
        int unitPrice;
        int maxQuantity;
    public:
    Product(int PID,std::string Pdepartments,std::string PprodType,std::string Pname,int Pquantity, int PunitPrice,int PmaxQuantity);
    Product() : ID(0), departments(""), prodType(""), name(""), quantity(0), unitPrice(0), maxQuantity(0) {}



    int get_id();
    std::string get_departements();
    std::string get_prodType();
    std::string get_name();
    int get_quantity();
    int get_unitPrice();
    int get_maxQuantity();

    void add_product_stock(int nb);

    int quantity_to_be_added();

    std::string quantityToMaxQuantityRatio();
};


void display_products(std::string &file);

Product retreive_product_object(std::string &line);

void update_product_to_CSV(std::string file, Product product);

std::string find_department_by_product(Product product);

#endif //PRODUCTS_HPP
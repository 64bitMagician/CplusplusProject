#ifndef FILEMANIPULATION_HPP
#define FILEMANIPULATION_HPP

#include "../headerFiles/products.hpp"

#include<string>
#include<vector>

std::vector<std::string> returnVectorOfAllLinesFromFile(const std::string &fileName);

std::string readCSVProduct(std::string &fileName,std::string product);

std::string getCSVlineByID(std::string &fileName,int selectedID,int idCollumn);

void update_product_to_CSV(std::string file, Product product);

void update_department_into_departmentsCSV(Product product);

#endif // FILEMANIPULATION_HPP
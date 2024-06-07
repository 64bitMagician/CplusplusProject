#ifndef STRINGMANIPULATION_HPP
#define STRINGMANIPULATION_HPP

#include<string>
#include<vector>

std::vector<std::string> splitCSVLine(const std::string& line);
std::string CSVlineGetWord(std::string line, int collumn);
std::vector<std::string> get_substrings_of_a_string(std::string line, char delimiter);


#endif // STRINGMANIPULATION_HPP
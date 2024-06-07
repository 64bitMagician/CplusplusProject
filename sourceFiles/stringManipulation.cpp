#include "../headerFiles/departments.hpp"
#include "../headerFiles/menus.hpp"
#include "../headerFiles/products.hpp"
#include "../headerFiles/fileManipulation.hpp"
#include "../headerFiles/stringManipulation.hpp"

#include<string>
#include<sstream>
#include<vector>


//splitCSVLine Function:
//You give a string of the form of a CSV line(elements separated by ',')
//And it returns a vector of strings, containing the strings separated by ',' wihin that CSV type line
std::vector<std::string> splitCSVLine(const std::string& line) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(line);
    while (std::getline(tokenStream, token, ',')) {
        tokens.push_back(token);
    }
    return tokens;
}

//CSVlineGetWord function
// This is a function for retreiving a certain word from a CSV type line(words separated by ',')
// You give it the CSV type line(string), and the collumn from where you want to retreive the word, starting from 1
// The function will return the word as a string.
std::string CSVlineGetWord(std::string line, int collumn){
    int i=0;
    while(collumn>1){
    if(line[i]==',') // if encountering the ',' symbol
        collumn--;
    i++;
    }
    std::string word="";
    while(line[i]!=',')
    {
        word+=line[i];
        i++;
    }

    return word;
}

//This function will return a vector of strings.
// You pass to the function a string and a character which represents the delimiter.
// The function will return the vector of substrings of the passed string, where substrings have been
// delimited by the passed character symbol
std::vector<std::string> get_substrings_of_a_string(std::string line, char delimiter){
    std::stringstream lineStream;
    std::vector<std::string> elements;
    lineStream<<line;
    
    while(getline(lineStream,line,delimiter)){
        elements.push_back(line);
    }

    return elements;
}
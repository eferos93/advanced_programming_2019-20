#include<iostream>

int main() {
    std::string previous_line = "";
    int counter = 0;
    for(std::string line; std::getline(std::cin,line);)
    {
        if (line == previous_line || previous_line.empty())
        {
            counter++;
            previous_line = line;
        } 
        else if (line.empty() || line != previous_line)
        {
            std::cout << counter << " " << previous_line << std::endl;
            counter = 1;
            previous_line = line;
        }
    }
    /*
    std::string line;
    std::string previous_line = "";
    while(std::getline(std::cin,line))
    {
        
    } 
    */  
}
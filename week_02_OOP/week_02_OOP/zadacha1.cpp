#include <iostream>
#include <fstream>

const char FILE_PATH[] = "/Users/dzhemshenolov/Documents/FMI/OOP at FMI/Praktikum /week_02_OOP/week_02_OOP/MyFile.txt";
int main()
{
    int a, b, c;
    std::ofstream file1(FILE_PATH);
    if (!file1.is_open())
    {
        std::cout << "Error";
        return -1;
    }
    std::cin  >> a >> b >> c;
    
    
    file1 << a + b + c;
    
    
    std::ifstream outputfile(FILE_PATH);
    if (!outputfile.is_open())
    {
        std::cout << "Error";
        return -1;
    }
    while (!outputfile.eof())
    {
        char buffer[1024];
        outputfile.getline(buffer, 1024);
        std::cout << buffer;
    }
    file1.close();
    outputfile.close();
    return 0;
}

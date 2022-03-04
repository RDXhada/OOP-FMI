#include <iostream>
#include <fstream>
const int BUFF = 1024;

std::ostream& foo(std::ostream& ostream, const char* string)
{
    ostream << string;
    return ostream;
}


int main()
{
    
    foo(std::cout, "Maiko mila\n");
    
    //read
    std::ifstream file("/Users/user/Desktop/OOP/OOP armqnka/week2/week2/myFile.txt");
    
    if (!file.is_open())
    {
        std::cout << "Error!" << std::endl;
        return -1;
    }
    int a = 3, b= 6;
    
    file >> a >> b;
    file.close();
    
    //write
    std::fstream write("/Users/user/Desktop/OOP/OOP armqnka/week2/week2/myFile.txt");
    
    if (!write.is_open())
    {
        std::cout << "Error!" << std::endl;
        return -1;
    }
    
    while(!write.eof())
    {
        char buff[BUFF];
        write.getline(buff, BUFF);
        
        std::cout << buff << std::endl;
    }
    
    std::fstream cmake("/Users/user/Desktop/OOP/OOP armqnka/week2/week2/myFile.txt");
    
    std::fstream read("/Users/user/Desktop/OOP/OOP armqnka/week2/week2/myFile.txt");
    if(!read.is_open()){
        return -1;
    }
    
    while(!cmake.eof()){
        char buff[BUFF];
        cmake.getline(buff, BUFF);
        read << buff;
    }
    
    cmake.close();
    read.close();
    
}


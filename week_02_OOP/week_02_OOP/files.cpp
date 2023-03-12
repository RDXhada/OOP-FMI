#include <iostream>
#include <fstream>


const char FILE_NAME[] = "/Users/dzhemshenolov/Documents/FMI/OOP at FMI/Praktikum /week_02_OOP/week_02_OOP/MyFile.txt";
const int BUFFER_SIZE = 1024;

//types of streams
//input/write -> istream
//outut/read -> ostream
//iostream, ifstream, ofstream, fstream
int main()
{

    //object of istream type
//    int a,b;
//    std::cin >> a >> b;
//
    //object of ostream type
//    char x = 'X', y = 'Y';
//    char z = x | y;
//    std::cout << x << y << '\n';
//    std::cout << z;

    //file streams
    std::ifstream file(FILE_NAME);

    if (!file.is_open())
    {
        std::cout << "Error" << '\n';
        return -1;
    }

    while (!file.eof())
    {
        char buff[BUFFER_SIZE];
        file.getline(buff, BUFFER_SIZE);
        std::cout << "Previous output: " << buff << '\n';
    }

    std::ofstream file1(FILE_NAME);
    if (!file1.is_open())
    {
        std::cout << "Error";
        return -1;
    }
    int dateOfBirth;
    std::cout << "Input date of birth: ";
    std::cin >> dateOfBirth;


    file1 << dateOfBirth;
    if (!file1.eof())
    {
        std::cout << "The file contains more data after the input." << '\n';
    }


    file.close();
    file1.close();

    return 0;
}

#include <iostream>
#include <fstream>

struct Student
{
    char first_name[256];
    char last_name[256];
    char email[256];
    int facultyNumber;
};

void printStudent(const Student& student)
{
    std::ofstream print("/Users/user/Desktop/OOP/OOP armqnka/week2/week2/CMS.txt");
    if(!print.is_open()){
        std::cout << "Error";
    }
    print << student.first_name <<", "<< student.last_name <<", " << student.email<< ", "<< student.facultyNumber;
    print.close();
}
int main(){
    Student s{"Dzhem", "Salimov","@gmail.com",1234};
    printStudent(s);
    return 0;
}

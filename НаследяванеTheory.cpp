#include <iostream>
using namespace std;


struct Person
{
    char firstName[16];
    char lastName[16];
};

struct Student:Person
{
    int facultyNumber;
    int numberOfSubjects;
};



int main()
{
    Student Dzhem;
    cout << Dzhem.numberOfSubjects;
    
    return 0;
}

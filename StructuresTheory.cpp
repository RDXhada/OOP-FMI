#include <iostream>
using namespace std;

struct Student
{
    //poleta na strukturata:
    char id[11];
    char name[36];
    char program[24];
    int year;
    double averageGrade;
};


int main()
{
    Student me ={"8MI0700009" , "Dzhem" , "Information Systems", 1, 4.50};
    
//s tova slagame nova specialnost za studenta:
    strcpy(me.program, "Computer Science");
    
    const Student you = {"1", "Deni", "Mathematics", 4, 4.75};
    me = you;
    cout << me.program;
    return 0;
}

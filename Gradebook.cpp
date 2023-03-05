#include <iostream>
#include <algorithm>

struct Gradebook
{
    char name[16];
    char facultyNumber[16];
    int numberOfGrades;
    double *grades;
};

void initStudent(Gradebook &gradebook)
{
    std::cout << "Enter student name:\n";
    std::cin >> gradebook.name;
    
    std::cout << "Enter faculty number: \n";
    std::cin >> gradebook.facultyNumber;
    
    std::cout << "Enter number of grades: \n";
    std::cin >> gradebook.numberOfGrades;
    gradebook.grades = new double[gradebook.numberOfGrades];
    std::cout << "Enter the grades :\n";
    for (int i = 0; i < gradebook.numberOfGrades; i++)
    {
        std::cin >> gradebook.grades[i];
    }
}

void printStudentInformation(Gradebook &gradebook)
{
    std::cout << "Name is : " << gradebook.name << '\n';
    std::cout << "Faculty number : " << gradebook.facultyNumber << '\n';
    std::cout << "Number of grades : " << gradebook.numberOfGrades << '\n';
    std::cout << "The grades are : ";
    for (int i = 0; i < gradebook.numberOfGrades; i++)
    {
        std::cout << gradebook.grades[i] << " ";
    }
}

void sortGrades(Gradebook &gradebook)
{
    double *arr = gradebook.grades;
    std::sort(arr, arr + gradebook.numberOfGrades);
    
    std::cout << "The sorted grades are : ";
    for (int i = 0 ; i < gradebook.numberOfGrades; i++)
    {
        std::cout << arr[i] << " ";
    }
    
}

double getAverageGrades(const Gradebook& gradebook)
{
    if (gradebook.numberOfGrades > 0)
    {
        double sum = 0;
        for (int i = 0; i < gradebook.numberOfGrades; i++)
        {
            if (gradebook.grades[i] >= 2)
            {
                sum += gradebook.grades[i];
            }
        }
        return sum / gradebook.numberOfGrades;
    }
    return -1;
}

bool canPass(const Gradebook &gradebook)
{
    if(gradebook.numberOfGrades >= 2)
    {
        if(getAverageGrades(gradebook) >= 3.00)
        {
            return true;
        }
    }
    return false;
}

bool canGetScolarship(const Gradebook &gradebook)
{
    if (getAverageGrades(gradebook) >= 4.50)
    {
        return true;
    }
    return false;
}


int main()
{
    Gradebook gradebook;
    initStudent(gradebook);
    printStudentInformation(gradebook);
    std::cout << "\nAverage of grades is : " << getAverageGrades(gradebook) << '\n';
    sortGrades(gradebook);
    std::cout << "\nCan pass course : " <<std::boolalpha << canPass(gradebook);
    std::cout << "\nCan get scolarship : " <<std::boolalpha << canGetScolarship(gradebook) << '\n';
    
    delete gradebook.grades;
    return 0;
}


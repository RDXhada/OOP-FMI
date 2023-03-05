#include <iostream>

const char* days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
enum class Weekday
{
  Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

int main()
{
    std::cout << "The days of the week are: ";
    for (int i = 0; i < (int)Weekday::Sunday; i++)
    {
        std::cout << days[i] << " ";
    }

    Weekday today = Weekday::Sunday;
    std::cout << std::endl << "Today is" << days[(int)today] << std::endl;
}

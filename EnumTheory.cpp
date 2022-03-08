
#include <iostream>
using namespace std;

//izbroim element
enum Colour
{
    //konstanti:
    UNKNOWN = -1,
    
    WHITE,
    RED,
    YELLOW,
    BLACK,
    
    COLOUR_COUNT
    //ako nqma qvna inicializaciq, toest samo white, red,black , pochvame da broim ot 0 - white, red - 1, black - 2 (+1 na vsqko)
    //ako imame qvna white shte e 1, red 7, black 10
    //ako white e 1 i red e prazno, to red e 2(+1 edin vid), a black shte e 3
};

//kratyk variant
const char* ColourNames[COLOUR_COUNT] = {"white", "red", "yellow", "black"};

void printColourName(Colour colour)
{
    if(colour > UNKNOWN && colour < COLOUR_COUNT)
    {
        cout << ColourNames[colour] << endl;
    }
    else
    {
        cout << "Unknown color bro";
    }
}
void printAllColour()
{
    for (int colour = UNKNOWN+1; colour < COLOUR_COUNT; ++colour)
    {
        cout << ColourNames[colour] << endl;
    }
}
//dylyg variant
void print(Colour colour)
{
    switch (colour)
    {
        case WHITE: cout << "white"; break;
        case RED: cout << "red"; break;
        case YELLOW: break;
        case BLACK: cout << "black";
            
        case UNKNOWN:  break;
        case COLOUR_COUNT: break;
        default: cout << "Unknown color";
            break;
    }
}

int main()
{
    Colour hatColour = RED;
    int colour;
    cin >> colour;
    hatColour = (Colour)colour;
    printColourName(hatColour);
    return 0;
}

//фундаментални типове: int, float, double, char bool
//съставни типове: int*, int&, int [10], enum

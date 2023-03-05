#include <iostream>
using namespace std;


struct Drinks
{
    char data;
    //a chat has 1 byte which is 8 bits(usually)
    //the first 3 bits wont be used, so the other 5 bits will
    //be used for binary operations for drinks
    // water, juice, beer, wine, whiskey
    // water ->   0b00000001
    // juice ->   0b00000010
    // beer ->    0b00000100
    // wine ->    0b00001000
    // whiskey -> 0b00010000
    
};

int main()
{
    Drinks exotic;
    exotic.data = 0b00001011;
    
    Drinks Ivan, Petar;
    Ivan.data  = 0b00000101; // Ivan likes water and beer
    Petar.data = 0b00010010; // Petar likes juice and whiskey
    
    if ((Ivan.data & exotic.data) == Ivan.data) // 0b00000001 == 0b00000101 -> false
        cout << "Ivan is happy" << endl;
    else
        cout << "Ivan is not happy" << endl;
    
    if (Petar.data & exotic.data) // 0b00000010 -> true
        cout << "Petar is happy" << endl;
    else
        cout << "Petar is not happy" << endl;
    
    // After heavy drinking, Ivan decides to become a better person
    // and only wants to drink water and juice
    
    // remove beer, wine and whiskey from ivan's preferences
    Ivan.data &= ~0b00000100;
    Ivan.data &= ~0b00001000;
    Ivan.data &= ~0b00010000;
    // explanation:
    // ivan.data               = 0b00000101 -> likes water and beer
    // ~0b00000100(beer)       = 0b11111011
    // 0b00000101 & 0b11111011 = 0b00000001 -> likes water only
    
    // add juice to ivan's preferences
    Ivan.data |= 0b00000010;
    
    // ===================================================================== //
    // Peter only drinks whiskey on the weekends
    
    // On mondays, we have to switch off the whiskey bit
    Petar.data ^= 0b00010000;
    
    // On the weekends we have to switch it back on (same operation)
    Petar.data ^= 0b00010000;
    
    // A different way to do this is:
    Petar.data = Petar.data ^ (1 << 4);
    // or shorter:
    Petar.data ^= 1 << 4;
    
    return 0;
}

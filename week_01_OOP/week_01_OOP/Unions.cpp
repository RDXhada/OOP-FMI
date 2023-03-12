//#include "Unions.hpp"
//#include <iostream>
//union Example
//{
//    int a;
//    char b;
//} var;
//
//union ExampleSize
//{
//    int a;
//    char b;
//    double c;
//    float d;
//} examplesize;
//
//int main()
//{
//    var.a = 65;
//    std::cout << var.a << " " << var.b << '\n'; //outputs 64 A
//    std::cout << sizeof(examplesize) << '\n'; //outputs 8
//    
//    var.a = 90;
//    union Example *ptr = &var;
//    std::cout << ptr->a << " " << ptr->b << '\n'; //90 Z
//    return 0;
//}
//

//#include <iostream>
//
////types of memory in C++
////global(static) - global variables
////stack - local variables (can be nonstatic)
////dynamic (heap)
////program code - memory, stored in the compiled code
//
//
////Structures
//struct Box
//{
//    double height, width, length;
//};
//
//struct Warehouse
//{
//    char name[64];
//    Box b1;
//    Box b2;
//};
//
//
////functions
//void f(int x);
//void f1(int &x);
//void f2(int *x);
//void wareHouse();
//void outputPaddingSize();
//
//
//double calculateVolume(const Box &box);
//void dynamicBoxCall();
//
//int main(int argc, const char * argv[]) {
//    int x = 10; //int in the stack - static memory
//    int *ptr = new int(20); //int in the heap- dynamic memory
//
//    std::cout << x << '\n'; //outputs 10
//    std::cout << *ptr << '\n'; //outputs 20
//    std::cout << ptr << '\n'; //outputs address
//
//    delete ptr; //prevent memory leak
//
//    ptr = &x; //redirect the pointer to int in the stack
//    std::cout << ptr << '\n'; //gives address of x
//    std::cout << *ptr << '\n'; //outputs 10
//
//    int &y = x;
//    y = 30;
//    std::cout << x << '\n'; //outputs 30
//
//    //copy passing
//    f(x);
//    std::cout << x << '\n'; //outputs 30
//    //reference passing
//    f1(x);
//    std::cout << x << '\n'; //outputs 31
//    //pointer passing
//    f2(&x);
//    std::cout << x << '\n'; //outputs 32
//
//    //struct box calling funcs
//    Box* boxPtr = new Box();
//
//    //dynamic objects
//    (*boxPtr).height = 3;
//    (*boxPtr).width = 1;
//    boxPtr->length = 4;
//
//    std::cout << calculateVolume(*boxPtr) << '\n'; //outputs 12
//
//    wareHouse(); //outputs "Ekont"
//    outputPaddingSize();
//    return 0;
//}
//
////copy passing func
//void f(int x)
//{
//    x++;
//}
//
////reference passing func
//void f1(int &x)
//{
//    x++;
//}
//
////pointer passing func
//void f2(int *x)
//{
//    (*x)++;
//}
//
////OOP principles
////Abstraction - the process of hiding the useless information for the client
////Capsulation - public/private stuff for the client
////Polymorphism - object can be of the same type and same interface, but with different outputs/realization of the interface
////Inheritance - child class has the same properties as the parent class
//
//void boxDeclarationTypes()
//{
//    //declaration types
//    Box b1;
//
//    Box b2 = {1, 6.7, 5};
//
//    Box b3;
//    b3.height = 12;
//    b3.width = 5.5;
//    b3.length = 10;
//}
//
////functions always have to have reference
////some functions that we wont have to change have to have const
//double calculateVolume(const Box &box)
//{
//    double volume = box.height * box.width * box.length;
//    return volume;
//}
//
////input func with box
//void inputBoxValues(Box &box)
//{
//    std::cin >> box.height >> box.width >> box.height;
//}
//
////dynamic object calling
//void dynamicBoxCall()
//{
//    Box *boxPtr = new Box();
//    (*boxPtr).height = 1;
//    (*boxPtr).width = 2;
//    boxPtr->length = 3;
//
//    std::cout << calculateVolume((*boxPtr)) << '\n';
//
//    delete boxPtr;
//
//}
//
////Warehouse struct calling func
//void wareHouse()
//{
//    Warehouse wrh = {"Ekont", {2,5,6}, {20,30,20}};
//    
//    std::cout << wrh.name << '\n';
//}
//
////Padding
//struct Example1
//{
//    bool a;
//    int b;
//} ex1;
//
//struct Example2
//{
//    short s;
//    char c;
//    int i;
//} ex2;
//
//struct Example3
//{
//    char c;
//    double d;
//    int s;
//} ex3;
//
//void outputPaddingSize()
//{
//    std::cout << sizeof(ex1) << '\n'; //outputs 8
//    std::cout << sizeof(ex2) << '\n'; //ouputs 8
//    std::cout << sizeof(ex3) << '\n'; //ouputs 24
//}
//
//

#include "../includes/iter.hpp"

#include <iostream>
#include <string>

template <typename T>
void   displayElement(T el)
{
    std::cout << el << std::endl;
}

int main()
{
    char arrayChar[] = {'a', 'b', 'c'};
    int arrayInt[] = {4, 5, 6, 7};
    float   arrayFloat[] = {8.1f, 9.1f, 10.1f, 11.1f, 12.1f};
    double   arrayDouble[] = {13.2, 14.2, 15.2, 16.2, 17.2, 18.2};
    std::string arrayString[] = {"one", "two", "three"};
    
    std::cout << "Display chars" << std::endl;
    ::iter(arrayChar, 3, static_cast<void (*)(char)>(&displayElement));
    std::cout << "Display ints" << std::endl;
    ::iter(arrayInt, 4, static_cast<void (*)(int)>(&displayElement));
    std::cout << "Display floats" << std::endl;
    ::iter(arrayFloat, 5, static_cast<void (*)(float)>(&displayElement));
    std::cout << "Display doubles" << std::endl;
    ::iter(arrayDouble, 6, static_cast<void (*)(double)>(&displayElement));
    std::cout << "Display strings" << std::endl;
    ::iter(arrayString, 3, static_cast<void (*)(std::string)>(&displayElement));
    return (0);
}
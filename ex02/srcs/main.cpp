#include "../includes/Array.hpp"
#include <stdlib.h>
#define MAX_VAL 750

int main()
{
    /*
    Array<int>   array(0);
        
    std::cout << "getArr: " << array.getArr() << std::endl;
    std::cout << "size: " << array.size() << std::endl;
    try
    {
        for (int i = 0; i < 5; i++)
            std::cout << "array[" << i << "]: " << array[i] << std::endl;
        
        array[0] = 667;
        std::cout << "array[0]: " << array[0] << std::endl;
        array[-2] = 0;
        

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    */
    /*
    Array<int>   array(5);
    
    std::cout << "getArr: " << array.getArr() << std::endl;
    std::cout << "size: " << array.size() << std::endl;
    
    
    try
    {
        for (int i = 0; i < 5; i++)
            std::cout << "array[" << i << "]: " << array[i] << std::endl;
        array[0] = 667;
        std::cout << "array[0]: " << array[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    
    try
    {
        array[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    */
    
    
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
    
}
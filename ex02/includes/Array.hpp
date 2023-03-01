#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class   Array
{
        T   *_arr;
        std::size_t _size;
    public:
        Array();
        Array(std::size_t);
        Array(const Array&);
        ~Array();
        Array &operator=(Array const &);
        T   &operator[](std::size_t);
        T   *getArr();
        std::size_t size() const;
        void    setSize(std::size_t);
        class   IndexOutOfBound: public std::exception
        {
            virtual const char* what() const throw();
        };
        class   ArrayCreation: public std::exception
        {
            virtual const char* what() const throw();
        };  
};
#include "../templates/Array.tpp"
#endif
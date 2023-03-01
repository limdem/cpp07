#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T, typename U>
void    iter(T* arr, std::size_t size, U* fptr)
{
    std::size_t i;

    i = 0;
    while (i < size)
    {
        fptr(arr[i]);
        i++;
    }
}
#endif
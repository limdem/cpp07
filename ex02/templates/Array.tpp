template <typename T>
Array<T>::Array()
{
    std::cout << "Array default constructor called" << std::endl;
    this->_arr = NULL;
    this->_size = 0;
}

template <typename T>
Array<T>::Array(std::size_t n)
{
    std::size_t i;

    std::cout << "Array constructor called" << std::endl;
    this->_arr = new T[n];
    this->_size = n;
    i = 0;
    while (i < this->_size)
    {
        this->_arr[i] = 0;
        i++;
    }
}

template <typename T>
Array<T>::Array(const Array& src)
{
    std::size_t    i;

    std::cout << "Array copy constructor called" << std::endl;
    if (!src.size())
    {
        this->_arr = NULL;
        this->setSize(src.size());
        return ;
    }
    this->_arr = new T[src.size()];
    i = 0;
    while (i < src.size())
    {
        this->_arr[i] = src._arr[i];
        i++;
    }
    this->setSize(src.size());
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Array destructor called" << std::endl;
    delete [] this->_arr;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const & src)
{
    std::size_t    i;

    std::cout << "Array copy assignment called" << std::endl;
    if (!src.size())
    {
        this->_arr = NULL;
        this->setSize(src.size());
        return (*this);
    }
    this->_arr = new T[src.size()];
    i = 0;
    while (i < src.size())
    {
        this->_arr[i] = src._arr[i];
        i++;
    }
    this->setSize(src.size());
    return (*this);
}

template <typename T>
T &Array<T>::operator[](std::size_t index)
{
    if (!this->size() || index > this->size() - 1) 
        throw   Array<T>::IndexOutOfBound();
    return  (this->getArr()[index]);
}

template <typename T>
T   *Array<T>::getArr()
{
    return (this->_arr);
}

template <typename T>
std::size_t    Array<T>::size() const
{
    return (this->_size);
}

template <typename T>
void    Array<T>::setSize(std::size_t size)
{
    this->_size = size;
}

template <typename T>
const char* Array<T>::IndexOutOfBound::what() const throw()
{
    return ("ArrayException: index out of range");
}

template <typename T>
const char* Array<T>::ArrayCreation::what() const throw()
{
    return ("ArrayException: array creation failed");
}
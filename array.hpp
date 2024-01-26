/* Filename: array.hpp */

#ifndef _ARRAY_HEADER_
#define _ARRAY_HEADER_

#include <iostream>

/* Basic Array Structure */
template <typename array_t> class Array {
    private:
        unsigned int size; // Array size
        array_t* structure;  // An array_t pointer to implement the actual array

    public:
        Array(const unsigned int&); // Constructor
        ~Array(void);               // Destructor
};

template <typename array_t> Array<array_t>::Array(const unsigned int& size_): size(size_) {
    std::cout << "Constructor called" << std::endl;
    this->structure = new array_t[this->size];
}

template <typename array_t> Array<array_t>::~Array(void) {
    std::cout << "Destructor called" << std::endl;
    delete this->structure;
}

#endif /* _ARRAY_HEADER_ */

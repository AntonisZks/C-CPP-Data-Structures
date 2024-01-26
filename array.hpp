/* Filename: array.hpp */

#ifndef _ARRAY_HEADER_
#define _ARRAY_HEADER_

#include <iostream>

/* Basic Array Structure */
template <typename array_t> class Array {
private:
    unsigned int size;  // Array size
    array_t* structure; // An array_t pointer to implement the actual array
    bool* filled;       // An array that determines whether a sepcific index in the array is filled with data

public:
    Array(const unsigned int&);
    ~Array(void);

    void insertAt(const array_t& data, const unsigned int index);

    template <typename atype> friend std::ostream& operator<<(std::ostream& out, Array<atype>& array);
    array_t& operator[](unsigned int index);
    const array_t& operator[](unsigned int index) const;
};

/* Array Constructor */
template <typename array_t> Array<array_t>::Array(const unsigned int& size_): size(size_) 
{
    this->structure = new array_t[this->size];
    this->filled = new bool[this->size];

    for (unsigned int i = 0; i < this->size; i++)
        this->filled[i] = false;
}

/* Array Destructor */
template <typename array_t> Array<array_t>::~Array(void) 
{
    delete[] this->structure;
    delete[] this->filled;
}

/* Inserts data to the given index of the array */
template<typename array_t> void Array<array_t>::insertAt(const array_t& data, const unsigned int index) 
{
    this->structure[index] = data;
    this->filled[index] = true;
}

/* Prints the contents of the array */
template <typename array_t> std::ostream& operator<<(std::ostream& out, Array<array_t>& array)
{
    out << "[";
    for (unsigned int i = 0; i < array.size; i++) {
        array.filled[i] ? out << array.structure[i] : out << "undef";
        (i < array.size - 1) ? out << ", " : out << "]";
    }
    return out;
}

template <typename array_t> array_t& Array<array_t>::operator[](unsigned int index) {
    return this->structure[index];
}

template <typename array_t> const array_t& Array<array_t>::operator[](unsigned int index) const {
    return this->structure[index];
}

#endif /* _ARRAY_HEADER_ */

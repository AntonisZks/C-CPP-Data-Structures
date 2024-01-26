#include <iostream>
#include "array.hpp"
using namespace std;

int main(int argc, char* argv[]) 
{
    Array<int>* myArray = new Array<int>(10);
    delete myArray;

    return 0;
}

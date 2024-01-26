#include <iostream>
#include "array.hpp"
using namespace std;

int main(int argc, char* argv[]) 
{
    Array<int> myArray = Array<int>(10);

    for (unsigned int i = 0; i < 5; i++)
        myArray[i] = i + 1;

    cout << myArray << endl;

    return 0;
}

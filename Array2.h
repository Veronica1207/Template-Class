#pragma once
// Array2.h
// Member-function definitions for class Array
// Author: Veronica Logvinenko A01208105
// Version: 2021-05-03

#include <iostream>
#include <iomanip>
#include <stdexcept> 

using namespace std;

template <typename elementType, size_t numberOfElements>
int Array<elementType, numberOfElements>::arrayCount = 0;

// default constructor for template class Array 
template <typename elementType, size_t numberOfElements>
Array<elementType, numberOfElements>::Array()
    :myArray()
{
    arrayCount++;
}


// copy constructor for class Array;
template <typename elementType, size_t numberOfElements>
Array<elementType, numberOfElements>::Array(const Array& arrayToCopy)
{  
    for (size_t i = 0; i < numberOfElements; ++i) {
        myArray[i] = arrayToCopy.myArray[i];
    }
} 


// destructor for class Array
template <typename elementType, size_t numberOfElements>
Array<elementType, numberOfElements>::~Array()
{

}


// return number of elements of Array
template <typename elementType, size_t numberOfElements>
size_t Array<elementType, numberOfElements>::getSize() const
{
    return numberOfElements;
} 


// overloaded equal operator
// determine if two Arrays are equal and
// return true, otherwise return false
template <typename elementType, size_t numberOfElements>
bool Array<elementType, numberOfElements>::operator==(const Array& right) const
{

    for (size_t i = 0; i < numberOfElements; ++i) {
        if (myArray[i] != right.myArray[i])
        {
            return false; // Array contents are not equal
        }
    }

    return true; // Arrays are equal
} 


// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
template <typename elementType, size_t numberOfElements>
elementType & Array<elementType, numberOfElements>::operator[](int subscript)
{
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= numberOfElements) {
        throw out_of_range("Subscript out of range");
    }

    return myArray[subscript]; // reference return
}


// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
template <typename elementType, size_t numberOfElements>
elementType Array<elementType, numberOfElements>::operator[](int subscript) const
{
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= numberOfElements) {
        throw out_of_range("Subscript out of range");
    }

    return myArray[subscript]; // returns copy of this element
}


// input function
template <typename elementType, size_t numberOfElements>
void Array<elementType, numberOfElements>::inputArray()
{
    for (size_t i = 0; i < numberOfElements; ++i)
    {
        cin >> myArray[i];
    }

}


//returns the current arrayCount value
//for a specialization of the Array template class
template <typename elementType, size_t numberOfElements>
int Array<elementType, numberOfElements>::getArrayCount()
{
    return arrayCount;
}


// ooutput function
template <typename elementType, size_t numberOfElements>
void Array<elementType, numberOfElements>::outputArray() const
{
    // output private ptr-based array 
    for (size_t i = 0; i < numberOfElements; ++i)
    {
        cout << myArray[i] << " ";
    }
    cout << "\n";

}



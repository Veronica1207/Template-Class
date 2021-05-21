// Array.h
// Member-function definitions for class Array
// Author: Veronica Logvinenko A01208105
// Version: 2021-05-03

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename elementType = int, size_t numberOfElements = 5>
class Array
{
public:
   explicit Array(); // default constructor
   Array( const Array & ); // copy constructor
   ~Array(); // destructor

   size_t getSize() const; // return size

   bool operator==( const Array & ) const; // equality operator

   // inequality operator; returns opposite of == operator
   bool operator!=( const Array &right ) const  
   { 
      return ! ( *this == right ); // invokes Array::operator==
   } // end function operator!=
   
   // subscript operator for non-const objects returns modifiable lvalue of elementType
   elementType &operator[]( int );

   // subscript operator for const objects returns rvalue of elementType
   elementType operator[]( int ) const;

   //input the array elements
   void inputArray();

   //output the array elements
   void outputArray() const;

   //checks the current value of arrayCount 
   //for a specialization of the Array template class
   static int getArrayCount();

private:
    
    elementType myArray[numberOfElements]; //c-style array of elementType of numberOfElements size 
    static int arrayCount; //tracks number of opjects currently instantiated
        
}; // end class Array


#include "Array2.h"

#endif

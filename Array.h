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

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/

// header files
#include "Console_IO_Utility.h"
#include <math.h>  // for cbrt

// global constants
const int TWO_ENDLINES = 2;

// prototypes
double cubeRoot( double value );
double calcElementOne(int coefficientA, int coefficientB);
double calcElementTwo(int coefficientA, int coefficientB, int coefficientC);
double calcElementThree(int coefficientA, int coefficientD);

double calcElementOne(int coefficientA, int coefficientB)
{
   double threePartExpElementOneNum, threePartExpElementOneDen, threePartExpElementOne;
   // calculate first element numerator of three part expression
   threePartExpElementOneNum = -(coefficientB*coefficientB*coefficientB);
   // calculate first element denominator of three part expression
   threePartExpElementOneDen = 27*coefficientA*coefficientA*coefficientA;
   // calculate first element of three part expression
   threePartExpElementOne = threePartExpElementOneNum/threePartExpElementOneDen;
   return threePartExpElementOne;
}
double calcElementTwo(int coefficientA, int coefficientB, int coefficientC)
{
   double threePartExpElementTwoNum, threePartExpElementTwoDen, threePartExpElementTwo;
   // calculate second element numerator of three part expression
   threePartExpElementTwoNum = coefficientB*coefficientC;
   // calculate second element denominator of three part expression
   threePartExpElementTwoDen = 6*coefficientA*coefficientA;
   // calculate second element of three part expression
   threePartExpElementTwo = threePartExpElementTwoNum/threePartExpElementTwoDen;
   return threePartExpElementTwo;
}
double calcElementThree(int coefficientA, int coefficientD)
{
   double threePartExpElementThreeNum, threePartExpElementThreeDen, threePartExpElementThree;
   // calculate third element numerator of three part expression
   threePartExpElementThreeNum = coefficientD;
   // calculate third element denominator of three part expression
   threePartExpElementThreeDen = 2*coefficientA;
   // calculate third element
   threePartExpElementThree = threePartExpElementThreeNum/threePartExpElementThreeDen;
   return threePartExpElementThree;
}
// main program
int main()
   {
    // initialize function/variables

       // initialize variables
       int coefficientA, coefficientB, coefficientC, coefficientD;
      
       double twoPartExpElementOneNum, twoPartExpElementOneDen;
       double twoPartExpElementTwoNum, twoPartExpElementTwoDen;
       double onePartExpressionNum, onePartExpressionDen;
       double threePartExpSquared, twoPartExpCubed;

       double threePartExpElementOne, threePartExpElementTwo;
       double threePartExpElementThree, threePartExpression, onePartExpression;
       double twoPartExpElementOne, twoPartExpElementTwo, twoPartExpression;
       double underSqRtPart, sqRtPart;
       double cubeRtAddedPart, cubeRtSubtractedPart, xResult, testVal;

       bool notComplex = false;

       // show title
          // function: printString, printEndline(s)
       printEndline();
       printString( "Third Degree Polynomial Calculator" );
       printEndline();
       printString( "==================================" );
       printEndlines( TWO_ENDLINES );

    // get input

       // show expression, provide instructions
          // function: printString, printEndline(s)
       printString( "For the expression: ax^3 + bx^2 + cx + d = 0" );
       printEndline();
       printString( "Enter the coefficient values here: " );
       printEndlines( TWO_ENDLINES );

       // get first coefficient
          // function: promptForInteger
       coefficientA = promptForInteger( "Enter coefficient A: " );

       // get second coefficient
          // function: promptForInteger
       coefficientB = promptForInteger( "Enter coefficient B: " );

       // get third coefficient
          // function: promptForInteger
       coefficientC = promptForInteger( "Enter coefficient C: " );

       // get fourth coefficient
          // function: promptForInteger
       coefficientD = promptForInteger( "Enter coefficient D: " );

    // process data

       // create expressions

          threePartExpElementOne = calcElementOne(coefficientA, coefficientB);

          threePartExpElementTwo = calcElementTwo( coefficientA, coefficientB, coefficientC);
          
          threePartExpElementThree = calcElementThree(coefficientA, coefficientD);
          // calculate three part expression
          threePartExpression = threePartExpElementOne + threePartExpElementTwo - threePartExpElementThree;
          // calculate three part expression squared
          threePartExpSquared = threePartExpression*threePartExpression;
          // calculate first element numerator of two part expression
          twoPartExpElementOneNum = coefficientC;
          // calculate first element denominator of two part expression
          twoPartExpElementOneDen = 3*coefficientA;
          // calculate first element of two part expression
          twoPartExpElementOne = twoPartExpElementOneNum/twoPartExpElementOneDen;
          // calculate second element numerator of two part expression
          twoPartExpElementTwoNum = coefficientB*coefficientB;
          // calculate second element denominator of two part expression
          twoPartExpElementTwoDen = 9*coefficientA*coefficientA;
          // calculate second element of two part expression
          twoPartExpElementTwo = twoPartExpElementTwoNum/twoPartExpElementTwoDen;
          // calculate two part expression
          twoPartExpression = twoPartExpElementOne - twoPartExpElementTwo;
          // calculate two part expression cubed
          twoPartExpCubed = twoPartExpression*twoPartExpression*twoPartExpression;
          // calculate numerator of one part expression
          onePartExpressionNum = coefficientB;
          // calculate denominator of one part expression
          onePartExpressionDen = 3*coefficientA;
          // calculate one part expression
          onePartExpression = onePartExpressionNum/onePartExpressionDen;
       // create under square root part
       underSqRtPart = threePartExpSquared + twoPartExpCubed;
       // check for positive square root part
       if( underSqRtPart >= 0 )
          {
           // get square root of under square root part
           sqRtPart = sqrt( underSqRtPart );

           // get cube root of added part
           cubeRtAddedPart = cubeRoot( threePartExpression + sqRtPart );

           // get cube root of subtracted part
           cubeRtSubtractedPart = cubeRoot( threePartExpression - sqRtPart );

           // find x
           xResult = cubeRtAddedPart + cubeRtSubtractedPart - onePartExpression;

           // set flag
           notComplex = true;
          }


    // show results
       // function: printString, printInt, printEndline(s)
    printEndline();
    printString( "For the cube expression: " );
    printInteger( coefficientA );
    printString( "x^3 + " );
    printInteger( coefficientB );
    printString( "x^2 + " );
    printInteger( coefficientC );
    printString( "x + " );
    printInteger( coefficientD );

    // check for not complex
    if( notComplex )
       {
        // display X result
           // function: printString, printDouble, printCharacter
        printString( ", the cube root X is: " );
        printDouble( xResult, PRECISION );
        printCharacter( PERIOD );
        printEndline();

        // check result value for polynomial
        testVal = coefficientA * xResult * xResult * xResult
                + coefficientB * xResult * xResult
                + coefficientC * xResult
                + coefficientD;

        // display verified result
           // function: printString, printDouble, printEndline
        printString( "Verify result: " );
        printDouble( testVal, PRECISION );
        printEndline();
       }

    else
       {
        // print complex message
           // function: printString, printEndline
        printString( ", the cube root is complex (i.e., not real)." );
        printEndline();
       }


    // end program

       // show end program
          // function: printString, printEndline
       printEndline();
       printString( "End Program" );
       printEndline();

       // return program success
       return 0;
   }


// supporting functions
/*
Name: cubeRoot
Process: finds cube root of positive or negative value
         using math.h function cbrt
Function input/parameters: value to be rooted (double)
Function output/parameters: none
Function output/returned: cube root of value (double)
Device input: none
Device output: none
Dependencies: math.h tools - cbrt
*/
double cubeRoot( double value )
   {
    // check for negative value
    if( value < 0 )
       {
        // return negative cube root of negated number
        return -cbrt( -value );
       }

    // return positive cube root of positive number
    return cbrt( value );
   }

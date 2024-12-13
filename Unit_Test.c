#include <stdio.h>
#include <math.h>
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

void test_calcElementOne()
{
    double cutoff = .0001;
    if( fabs(calcElementOne(3,5) - -0.1714) < cutoff)
    {
        printf("calcElementOne test 1 success\n");
    }
    else
    {
        printf("calcElementOne test 1 unsuccessfull\n");
    }
    if( fabs(calcElementOne(4,2) - -0.0046) < cutoff)
    { 
        printf("calcElementOne test 2 success\n");
    }
    else
    {
        printf("calcElementOne test 2 unsuccessfull\n");
    }
}

void test_calcElementTwo()
{
    double cutoff = .0001;
    if( fabs(calcElementTwo(7, 4, 2) - 0.0272) < cutoff)
    {
        printf("calcElementTwo test 1 success\n");
    }
    else
    {
        printf("calcElementTwo test 1 unsuccessfull\n");
    }
    if( fabs(calcElementTwo(3, 6, 5) - 0.5556) < cutoff)
    { 
        printf("calcElementTwo test 2 success\n");
    }
    else
    {
        printf("calcElementTwo test 2 unsuccessfull\n");
    }
}

void test_calcElementThree()
{
    double cutoff = .0001;
    if( fabs(calcElementThree(4, 1) - 0.1250) < cutoff)
    {
        printf("calcElementThree test 1 success\n");
    }
    else
    {
        printf("%1.4f calcElementThree test 1 unsuccessfull\n", calcElementThree(4, 1));
    }
    if( fabs(calcElementThree(7, 8) - 0.5714) < cutoff)
    { 
        printf("calcElementThree test 2 success\n");
    }
    else
    {
        printf("%1.4f calcElementThree test 2 unsuccessfull\n", calcElementThree(7, 8));
    }
}

int main()
{
    test_calcElementOne();
    test_calcElementTwo();
    test_calcElementThree();
}
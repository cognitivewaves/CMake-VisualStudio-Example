// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "simple/SimpleFunctions.h"
#include "advanced/AdvancedFunctions.h"

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout,"%s\n", "Insufficient input - enter a value.");
        return 1;
    }

    double inputValue = atof(argv[1]);

    double sumValue = mysum(inputValue, inputValue);
    double sqrtValue = mysqrt(inputValue);

    fprintf(stdout,"The sum of %g and %g is %g\n", inputValue, inputValue, sumValue);
    fprintf(stdout,"The square root of %g is %g\n", inputValue, sqrtValue);

    return 0;
}

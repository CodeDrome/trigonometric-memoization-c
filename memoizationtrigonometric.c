
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include"memoizationtrigonometric.h"

// --------------------------------------------------------
// FUNCTION memoize_trigonometric
// --------------------------------------------------------
bool memoize_trigonometric()
{
    memoized_sines = malloc(91 * sizeof(double));

    if(memoized_sines != NULL)
    {
        for(int d = 0; d <= 90; d++)
        {
            memoized_sines[d] = sin(d / DEGREES_IN_RADIAN);
        }

        return true;
    }
    else
    {
        return false;
    }
}

// --------------------------------------------------------
// FUNCTION memoized_sine
// --------------------------------------------------------
double memoized_sine(int degrees)
{
    int degrees_shifted;
    double sine;
    bool sine_negative = false;

    // get an angle between -360 and 360 using modulus operator
    degrees_shifted = degrees % 360;

    // move negative angles by 360 into the positive range
    if(degrees_shifted < 0)
        degrees_shifted += 360;

    // if angle is in the 180-360 range shift it to the 0-180 range
    // and record that we need to negate the sine
    if(degrees_shifted > 180)
    {
        degrees_shifted-= 180;
        sine_negative = true;
    }

    // if degrees_shifted is 90-180 we need to "mirror" it into the 0-90 range
    if(degrees_shifted > 90 && degrees_shifted <= 180)
    {
        degrees_shifted = 90 - (degrees_shifted - 90);
    }

    // now get the sine from the memoized lookup table
    sine = memoized_sines[degrees_shifted];

    // negate if angle was 180-360
    if(sine_negative)
    {
        sine*= -1;
    }

    return sine;
}

// --------------------------------------------------------
// FUNCTION memoized_cosine
// --------------------------------------------------------
double memoized_cosine(int degrees)
{
    return memoized_sine(degrees + 90);
}

// --------------------------------------------------------
// FUNCTION memoized_tangent
// --------------------------------------------------------
double memoized_tangent(int degrees)
{
    if( (degrees % 90) != 0)
    {
        double sine = memoized_sine(degrees);
        double cosine = memoized_cosine(degrees);

        return sine / cosine;
    }
    else
    {
        return NAN;
    }
}

// --------------------------------------------------------
// FUNCTION memoize_trigonometric
// --------------------------------------------------------
void free_memoized_trigonometric()
{
    free(memoized_sines);
}

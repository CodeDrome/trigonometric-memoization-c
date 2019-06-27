
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<locale.h>
#include<stdlib.h>
#include<stdbool.h>

#include"memoizationtrigonometric.h"

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main(void)
{
    puts("-----------------------------");
    puts("| codedrome.com             |");
    puts("| Memoization Trigonometric |");
    puts("-----------------------------\n");

    if(memoize_trigonometric())
    {
        // sines
        puts("Sines\n-----");
        for(int i = -720; i <= 720; i+=15)
        {
            printf("%6d%12lf%12lf\n", i, sin(i / DEGREES_IN_RADIAN), memoized_sine(i));
        }

        // cosines
        puts("Cosines\n-------");
        for(int i = -720; i <= 720; i+=15)
        {
            printf("%6d%12lf%12lf\n", i, cos(i / DEGREES_IN_RADIAN), memoized_cosine(i));
        }

        // tangents
        puts("Tangents\n--------");
        for(int i = -720; i <= 720; i+=15)
        {
            if( (i % 90) != 0)
            {
                printf("%6d%12lf%12lf\n", i, tan(i / DEGREES_IN_RADIAN), memoized_tangent(i));
            }
            else
            {
                printf("%6d%12s%12lf\n", i, "~", memoized_tangent(i));
            }
        }

        free_memoized_trigonometric();
    }

    return EXIT_SUCCESS;
}

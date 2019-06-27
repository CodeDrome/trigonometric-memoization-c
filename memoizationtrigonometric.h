
#include<stdbool.h>

#define M_PI 3.14159265358979323846264338327
#define DEGREES_IN_RADIAN (180.0 / M_PI)

double* memoized_sines;

// --------------------------------------------------------
// FUNCTION PROTOTYPES
// --------------------------------------------------------
bool memoize_trigonometric();
double memoized_sine(int degrees);
double memoized_cosine(int degrees);
double memoized_tangent(int degrees);
void free_memoized_trigonometric();

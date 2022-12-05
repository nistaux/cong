#include <stdlib.h>
#include <time.h>
#include <math.h>



void init_rand() {
    srand((unsigned int)time(NULL));
}

float get_rand_f(float left, float right) {
    float randomNumber = sin(rand() * rand());
    return left + (right - left) * fabs(randomNumber);
}
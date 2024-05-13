#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//generate random number
int randomNumber(int nr_min, int nr_max)
{
    static bool initialized = false;
    if(!initialized){
        initialized = true;
        srand(time(NULL));
    }

    return rand() % nr_max  + nr_min;
}

//generate random color value 0 to 255
 
int randomColor()
{
    return randomNumber(0, 255);
}

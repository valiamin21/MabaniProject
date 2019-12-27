#include <stdlib.h>
#include <time.h>

bool initilized = false;

// This method generates random number
int getRandom(int first, int last){
    if(!initilized){
        srand(time(NULL));
        initilized = true;
    }

    return rand() % (last - first + 1) + first;
}

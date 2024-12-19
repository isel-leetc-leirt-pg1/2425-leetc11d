#include <stdlib.h>
#include <time.h>


void rand_init() {
    srand(time(NULL));
}

int rand_in_range(int initial, int final) {
    return initial + rand() % (final - initial + 1);
}

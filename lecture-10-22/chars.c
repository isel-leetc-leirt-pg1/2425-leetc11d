#include <stdio.h>

int my_tolower(int c) {
    if (c >= 'A' && c <= 'Z') {
        c = c + 'a' - 'A';
    }
    return c;
}


int main() {
    printf("tolower('M')= '%c'\n", my_tolower('M'));
    printf("tolower('+')= '%c'\n", my_tolower('+'));
    return 0;
}
    

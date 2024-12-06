#include <stdio.h>


int main() {
    char *msg = "Hello";
    char new_msg[] = "Hello";
    
    char *pnew_msg = new_msg;
    
    *pnew_msg = 'c';

    // descomente a linha seguinte e observe o resultado
    //*msg = 'd';

    printf("msg =%s\n", pnew_msg);
    return 0;
}

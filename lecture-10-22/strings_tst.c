#include <stdio.h>
#include "mystrings.h"

int main() {
    int dvals[30];
    
    char str[10] = { 'a', 'b', 'c', 0 };
    char str1[] = "abc";
    char str2[10];
    
    
    /*
    
    str[0] = 'a';
    str[1] = 'b';
    str[2] = 'c';
    str[3] = '\0'; //  0
    */
    
    printf("str='%10s'\n", str);
    printf("str='%-10s'\n", str);
    
    printf("strlen(str)=%d\n", my_strlen(str));
    printf("sizeof(str)=%ld\n", sizeof(str));
    
    printf("sizeof(dvals)=%ld\n", sizeof(dvals));
 
    printf("strlen(str1)=%d\n", my_strlen(str1));
    
    my_strcpy(str2, str);
    
    int res = my_strcmp(str, str2);
    
    my_strcat(str2, str);
    printf("strlen(str2)=%d\n", my_strlen(str2));
  
    printf("strcmp(str, str2)=%d\n", res);
    printf("str2='%10s'\n", str2);
    return 0;
}

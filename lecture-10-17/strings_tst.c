#include <string.h>
#include <stdio.h>

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
    
    printf("strlen(str)=%ld\n", strlen(str));
    printf("sizeof(str)=%ld\n", sizeof(str));
    
    printf("sizeof(dvals)=%ld\n", sizeof(dvals));
 
    printf("strlen(str1)=%ld\n", strlen(str1));
    
    strcpy(str2, str);
    
    int res = strcmp(str, str2);
    
    strcat(str2, str);
    printf("strlen(str2)=%ld\n", strlen(str2));
  
    printf("strcmp(str, str2)=%d\n", res);
    printf("str2='%10s'\n", str2);
    return 0;
}

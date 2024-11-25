#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int d, m, y;
} date_t;

date_t date_create(int day, int month, int year) {
    
}

bool date_init(date_t *date, int day, int month, int year) {
    //(*date).d = day;
    date->d = day;
    date->m = month;
    date->y = year;
    return true;

}

bool data_is_valid(date_t d) {
    if (d.m < 1 || d.m > 12) return false;
    //...
    return true;
}

void swap(int *i1, int *i2) {
    int tmp;
    tmp = *i1;
    *i1 = *i2;
    *i2 = tmp;
}


int main() {
    int v1 = 3, v2 = 5;
    int *pv1 = &v1;

    int v1a = *pv1; // <=> v1a = v1

    printf("v1a=%d\n", v1a);
    printf("&v1=%p, &v2=%p\n", &v1, &v2);

    swap(&v1, &v2);
    
    printf("v1=%d, v2 = %d\n", v1,v2);
    return 0;
}

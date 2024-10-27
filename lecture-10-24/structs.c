#include <stdio.h>

typedef struct {
    int day, month, year;
} date_t;

#define MAX_NAME 64

/**
 * tipos estrututura "friend_t"que contém
 * os campos "nome" e "birthday" de um amigo
 */
typedef struct {
    char name[MAX_NAME];
    date_t birthday;
} friend_t;

/**
 * as estruturas são passadas às funções
 * como os tipos numéricos, por cópia do valor
 */
void show_friend(friend_t f) {
    printf("name: %s\n", f.name);
    date_t date = f.birthday;
    printf("birthday: %d-%d-%d\n", date.day, date.month, date.year);
}

int main() {
    
    friend_t friends[] = {
        {
            .name = "Carlos",
            .birthday = {
                .day = 1, .month = 10, .year = 1990
            }
        },
        {
            .name = "João",
            .birthday = {
                .day = 1, .month = 10, .year = 1990
            }
        }
    };
    
    friend_t first = friends[0];
       
    

    show_friend(friends[0]);
    return 0;
}

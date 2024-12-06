#include <pg/pglib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void key_handler(KeyEvent ke) {
    if (ke.state == KEY_PRESSED) {
        printf("key pressed: ");
    }
    else {
         printf("key released: "); 
    }
    printf("%c\n", ke.keysym);
}

int main() {
    graph_init2("First", WINDOW_WIDTH, WINDOW_HEIGHT);
    
    graph_regist_key_handler(key_handler);
     
    
    graph_start();
    
    printf("terminated!\n");
 }

#include <pg/pglib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int evt_id =1;
int cx = -1, cy= -1;

void mouse_handler(MouseEvent me) {
    if (me.type == MOUSE_MOTION_EVENT) {
        if (me.state == BUTTON_PRESSED && me.button == BUTTON_LEFT) {
            if (cx != -1) {
                printf("event!\n");
                graph_line(cx, cy, me.x, me.y, c_blue);
            }
            cx = me.x;
            cy = me.y;
        }
    }
    else if (me.state == BUTTON_RELEASED) {
        cx = -1;
    }
}


int main() {
    graph_init2("First", WINDOW_WIDTH, WINDOW_HEIGHT);
    
    graph_regist_mouse_handler(mouse_handler);
     
    
    graph_start();
    
    printf("terminated!\n");
 }

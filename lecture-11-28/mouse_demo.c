#include <pg/pglib.h>

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

void mouse_handler(MouseEvent me) {
    char *msgType = me.type == MOUSE_MOTION_EVENT ? "MOUSE_MOTION_EVENT" : "MOUSE_BUTTON_EVENT";
    printf("mouse_event: %s\n", msgType );
}
 
int main() {
    graph_init2("Mouse Events", WINDOW_WIDTH, WINDOW_HEIGHT);

   
    graph_regist_mouse_handler(mouse_handler);
    graph_start();
}

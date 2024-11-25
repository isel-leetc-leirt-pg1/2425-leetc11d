#include <pg/pglib.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 800

int main() {
    graph_init2("Hello Window", WINDOW_WIDTH, WINDOW_HEIGHT);
    graph_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, c_cyan, true);

    const char *msg= "Hello, World!";
    Size txt_size = graph_text_size(msg, LARGE_FONT);
    int x = WINDOW_WIDTH/2 - txt_size.width/2;
    int y = WINDOW_HEIGHT/2 - txt_size.height/2;
    graph_text(x, y, c_dgray, msg , LARGE_FONT);
    
    graph_start();
    return 0;
}
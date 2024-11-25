#include <pg/pglib.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 800


int main() {
    graph_init2("Balls",WINDOW_WIDTH , WINDOW_HEIGHT);
    graph_circle(40,40, 50, c_orange, true);
    graph_start();
}

/**
 * Início da construção da animação horizontal de uma bola
 * 
 */
 
 
#include <pg/pglib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define BASE_TIME 20
#define BALL_DX  10
#define BALL_DY   0

typedef struct {
    int x, y; // centro
    int radius;
    RGB clr;
} ball_t;


// variáveis globais
ball_t ball;

 

void ball_move(ball_t *ball, int dx, int dy) {
    // to implement
}

int main() {
    graph_init2("Balls",WINDOW_WIDTH , WINDOW_HEIGHT);
    
    graph_circle(40, 40, 50, c_orange, true);
    
    graph_start();
}

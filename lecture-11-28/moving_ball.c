/**
 * Movimento horizontal,  contínuo e constante de uma bola para um lado e 
 * para o outro da janela gráfica. Ilustra a forma como se produz movimento
 * 
 * Compilação:
 *      gcc -o moving_ball -Wall moving_ball.c -lpg
 */
 
#include <pg/pglib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define BASE_TIME 20
#define BALL_DX  10     // 
#define BALL_DY   0

#define MAX_DELTA_X   40
#define MAX_DELTA_Y   40

/* estrutura que representa a bola */
typedef struct {
    int x, y;   // centro
    int radius; // raio
    int dx, dy; // velocidade e direção do movimento
    RGB clr;    // côr
} ball_t;


// variáveis globais
ball_t ball;

/**
 * para produzir um écrã vazio em cima do quealse volta a desenhar a bola
 */
void clear_scene() {
    graph_rect(0,0,WINDOW_WIDTH, WINDOW_HEIGHT, c_white, true);
}

/**
 * constrói a bola presente no endereço referido por "b"
 * usando os argumentos recebidos ("x", "y", "radius" e "clr")
 */
void ball_init(ball_t *b, int x, int y, int radius, RGB clr) {
    b->x = x;
    b->y = y;
    b->clr = clr;
    b->radius = radius;
    b->dx = BALL_DX;
    b->dy = BALL_DY;
}

/**
 * movimenta bola na direção e com a velocidade definidas
 * pelos campos "dx" e "dy" da bola
 */
void ball_move(ball_t *ball) {
    ball->x += ball->dx;
    ball->y += ball->dy;
    if (ball->x > WINDOW_WIDTH- ball->radius ) {
        ball->x = WINDOW_WIDTH- ball->radius;
        ball->dx = -ball->dx;
    }
    else if (ball->x - ball->radius < 0) {
        ball->x = ball->radius;
        ball->dx = -ball->dx;
    }
}

/**
 * mostra a bola na sua posição atual
 */
void ball_draw(ball_t b) {
    graph_circle(b.x, b.y, b.radius, b.clr, true);
}

void ball_accelerate_x(ball_t *b) {
    if (b->dx >= 0) { 
        if (b->dx < MAX_DELTA_X) {
            b->dx += 5;
        }
    }
    else {
        if (b->dx > -MAX_DELTA_X) {
            b->dx -= 5;
        }
    }
  
}

void ball_break_x(ball_t *b) {
    if (b->dx > 0) { 
        b->dx -= 5;
    }
    else if (b->dx < 0) {
        b->dx += 5;
    }
   
}

void ball_accelerate_y(ball_t *b) {
    if (b->dy >= 0) { 
        if (b->dy < MAX_DELTA_Y) {
            b->dy += 2;
        }
    }
    else {
        if (b->dy > -MAX_DELTA_Y) {
            b->dy -= 2;
        }
    }
  
}

void ball_break_y(ball_t *b) {
    if (b->dy > 0) { 
        b->dy -= 5;
    }
    else if (b->dy < 0) {
        b->dy += 5;
    }  
}

/**
 * processa o evento de "passagem de tempo", neste caso por
 * cada novo período de BASE_TIME milisegundos
 */
void timer_handler() {
    //printf("tick!\n");
    clear_scene();
    ball_draw(ball);
    ball_move(&ball);
}

void key_handler(KeyEvent ke) {
    /*
    char *keyState;
    if (ke.state == KEY_PRESSED) {
        keyState = "KEY_PRESSED";
    }
    else {
        keyState = "KEY_RELEASED";
    }
    if (ke.keysym == SDLK_KP_PLUS) {
        printf("key event: %s, KeyPadPlus\n", keyState, ke.keysym);
    }
    */
    if (ke.state == KEY_PRESSED) {
        if (ke.keysym == SDLK_KP_PLUS) {
            ball_accelerate_x(&ball);
        }
        else if (ke.keysym == SDLK_KP_MINUS) {
            ball_break_x(&ball);
        }
        else if (ke.keysym == SDLK_a) {
            ball_accelerate_y(&ball);
        }
        else if (ke.keysym == SDLK_z) {
            ball_break_y(&ball);
        }
    }
}

int main() {
    graph_init2("Moving Ball",WINDOW_WIDTH , WINDOW_HEIGHT);
    ball_init(&ball, 100, 100, 40, c_orange);

    graph_regist_timer_handler(timer_handler, BASE_TIME);
    graph_regist_key_handler(key_handler);

    graph_start();
}

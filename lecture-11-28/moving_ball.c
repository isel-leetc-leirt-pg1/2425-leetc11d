/**
 * Movimento nas duas dimensões (em x e em y),  com possibiliadde
 * de variação de velocidade e direção de uma bola na janela gráfica. 
 * Ilustra a forma como se produz movimento
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
#define BALL_START_X 100
#define BALL_START_Y 200
#define MAX_DELTA_X   15
#define MAX_DELTA_Y   15

#define BOARD_START_Y 100

// dx_view
#define DX_VIEW_X (WINDOW_WIDTH/2 - 200)
#define DX_VIEW_Y (BOARD_START_Y/2)

// dy_view
#define DY_VIEW_X (WINDOW_WIDTH/2 + 200)
#define DY_VIEW_Y DX_VIEW_Y


#define VELOCITY_VIEWS_TXT_CLR c_orange
#define VELOCITY_VIEWS_BACK_CLR c_dgray

/* estrutura que representa a bola */
typedef struct {
    int x, y;   // centro
    int radius; // raio
    int dx, dy; // velocidade e direção do movimento
    RGB clr;    // côr
} ball_t;


// variáveis globais
ball_t ball;
MsgView dx_view, dy_view;

// alternative way to show the dx and dy values of the ball
Counter dx_view2, dy_view2; 

/**
 * para produzir um écrã vazio em cima do quealse volta a desenhar a bola
 */
void clear_scene() {
    graph_rect(0,BOARD_START_Y,WINDOW_WIDTH, WINDOW_HEIGHT-BOARD_START_Y, c_white, true);
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
    if (ball->y > WINDOW_HEIGHT- ball->radius ) {
        ball->y = WINDOW_HEIGHT- ball->radius;
        ball->dy = -ball->dy;
    }
    else if (ball->y - ball->radius < BOARD_START_Y) {
        ball->y = BOARD_START_Y + ball->radius;
        ball->dy = -ball->dy;
    }
}

/**
 * mostra a bola na sua posição atual
 */
void ball_draw(ball_t b) {
    graph_circle(b.x, b.y, b.radius, b.clr, true);
}

/**
 * aumenta a componente em x da velocidade e direção
 */
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
    mv_show_number(&dx_view, abs(b->dx));
  
}

/**
 * diminui a componente em x da velocidade e direção
 */
void ball_break_x(ball_t *b) {
    if (b->dx > 0) { 
        b->dx -= 5;
    }
    else if (b->dx < 0) {
        b->dx += 5;
    }
    mv_show_number(&dx_view, abs(b->dx));
}

/**
 * aumenta a componente em y (dy) da velocidade e direção
 */
void ball_accelerate_y(ball_t *b) {
    if (b->dy >= 0) { 
        if (b->dy < MAX_DELTA_Y) {
            b->dy += 1;
        }
    }
    else {
        if (b->dy > -MAX_DELTA_Y) {
            b->dy -= 1;
        }
    }
    mv_show_number(&dy_view, abs(b->dy));
}

/**
 * diminui a componente em y (dy) da velocidade e direção
 */
void ball_break_y(ball_t *b) {
    if (b->dy > 0) { 
        b->dy -= 1;
    }
    else if (b->dy < 0) {
        b->dy += 1;
    }
    mv_show_number(&dy_view, abs(b->dy));  
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


void init_demo() {
    ball_init(&ball, BALL_START_X, BALL_START_Y, 40, c_orange);
    
  
    mv_create(&dx_view, DX_VIEW_X, DX_VIEW_Y, 4, 
              LARGE_FONT,VELOCITY_VIEWS_TXT_CLR ,VELOCITY_VIEWS_BACK_CLR );
    mv_create(&dy_view, DY_VIEW_X, DY_VIEW_Y, 4, 
              LARGE_FONT,VELOCITY_VIEWS_TXT_CLR ,VELOCITY_VIEWS_BACK_CLR );
    graph_rect(0, 0, WINDOW_WIDTH, BOARD_START_Y, c_gray, true);
    mv_show_number(&dx_view, BALL_DX);
    mv_show_number(&dy_view, BALL_DY);
    
    
    /*
    graph_rect(0, 0, WINDOW_WIDTH, BOARD_START_Y, c_black, true);
    ct_create(&dx_view2, DX_VIEW_X, DX_VIEW_Y,BALL_DX, "DX", LARGE_FONT);
    ct_create(&dy_view2, DY_VIEW_X, DY_VIEW_Y,BALL_DY, "DY", LARGE_FONT);

    ct_show(&dx_view2);
    ct_show(&dy_view2);
    */  
}

int main() {
    graph_init2("Moving Ball",WINDOW_WIDTH , WINDOW_HEIGHT);
    init_demo();
    graph_regist_timer_handler(timer_handler, BASE_TIME);
    graph_regist_key_handler(key_handler);

    graph_start();
}

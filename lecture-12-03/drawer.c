#include <pg/pglib.h>
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int mouse_event_count = 0;
int old_x = -1, old_y;

/*
 * Mostra uma mensagem na janela gráfica centrada em x,
 * com cores de fonte e de fundo especificadas
 * y define o topo do text
 */
void show_centered_msg(char *msg, int y, RGB fc, RGB bc) {
    Size msg_size = graph_text_size(msg, MEDIUM_FONT);
    int x = WINDOW_WIDTH/2 - msg_size.width/2;
    y = y + msg_size.height;
    graph_text2(x, y, fc, bc, msg, MEDIUM_FONT);
}

void mouse_handler(MouseEvent me)
{
    /*
    char *type;


    type = me.type == MOUSE_MOTION_EVENT ? "MOUSE_MOTION_EVENT" : "MOUSE_BUTTON_EVENT";

    char *state = me.state == BUTTON_PRESSED ? "BUTTON_PRESSED" : "BUTTON_RELEASED";

    char *button = me.button == BUTTON_LEFT ? "BUTTON_LEFT" : "BUTTON_RIGHT";

    printf("mouse event: type=%s, button=%s, state = %s, x=%d,y=%d,dx=%d,dy=%d!\n",
                    type, button, state, me.x, me.y, me.dx, me.dy);
    */
    
    if (me.type == MOUSE_MOTION_EVENT && me.button == BUTTON_LEFT &&
                  me.state == BUTTON_PRESSED) {

        if (old_x != -1) {
            graph_line(old_x, old_y, me.x, me.y, c_black);
        }
        old_x = me.x;
        old_y = me.y;
    }
    else if (me.button == BUTTON_LEFT && me.state == BUTTON_RELEASED) {
        old_x = -1;
    }
    
    
}

int main()
{
    graph_init2("Mouse Tester", WINDOW_WIDTH, WINDOW_HEIGHT);

    show_centered_msg("Desenhe a mao livre com o rato", 20, c_green, c_white);

    graph_regist_mouse_handler(mouse_handler);

    graph_start();
}

#include <pg/pglib.h>
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define TIME_BASE 1000 

int h = 0, m = 0, s=0;

void clock_tick() {
    s++;
    if (s == 60) {
        s = 0;
        m++;
        if (m == 60) {
            m=0;
            h++;
        }
    }
}

void clock_show() {
    graph_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, c_cyan, true);
    char time[10];
    
    sprintf(time, "%02d:%02d:%02d", h, m, s);
   
    Size txt_size = graph_text_size(time, LARGE_FONT);
    int x = WINDOW_WIDTH/2 - txt_size.width/2;
    int y = WINDOW_HEIGHT/2 + txt_size.height/2;
    
    graph_text(x, y,  c_black, time, LARGE_FONT);
}


void timer_handler() {
    clock_tick();
    clock_show();
}


int main() {
    graph_init2("First", WINDOW_WIDTH, WINDOW_HEIGHT);
    
    graph_regist_timer_handler(timer_handler, TIME_BASE);
    
    /*
    graph_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, c_cyan, true);
    char msg[] = "Hello, World!";
   
    Size txt_size = graph_text_size(msg, LARGE_FONT);
    int x = WINDOW_WIDTH/2 - txt_size.width/2;
    int y = WINDOW_HEIGHT/2 + txt_size.height/2;
    
    graph_text(x, y,  c_black, msg, LARGE_FONT);
    */
    graph_start();
    
    printf("terminated!\n");
 }

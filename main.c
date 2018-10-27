#include <stdio.h>
#include "lienzo.h"
#include "unistd.h"
#include "betterconsole.h"
#include "objeto.h"

int main() {
    echo_off();
    cursor_off();

    t_lienzo lienzo = crea_lienzo(50, 50, BLUE);
    t_objeto obj = {
            10, 40, // posición
            3, 5,
            RED,
            {
                    " /^\\ ",
                    "<ooo>",
                    " ^^^ ",
            }
    };

    int tecla;
    int vf = 0, vc = 0;


    do {
        tecla = get_key_pressed();
        switch(tecla) {
            case KEY_UP:
                vf = -1; vc = 0;
                break;
            case KEY_DOWN:
                vf = 1; vc = 0;
                break;
            case KEY_LEFT:
                vf = 0; vc = -1;
                break;
            case KEY_RIGHT:
                vf = 0; vc = 1;
                break;
        }

        obj.pos_fil += vf;
        obj.pos_col += vc;
        dibuja_objeto(obj, &lienzo);
        redibuja_lienzo(&lienzo);
        usleep(50000);
    } while (tecla != KEY_ESC);

    echo_on();
    cursor_on();

    destruye_lienzo(&lienzo);

    return 0;
}
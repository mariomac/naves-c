//
// Created by Mario Macías on 27/10/18.
//

#include "betterconsole.h"
#include "objeto.h"
#include "lienzo.h"


void dibuja_objeto(t_objeto obj, t_lienzo *lienzo) {
    for (int fil = 0 ; fil < obj.tam_fils ; fil++) {
        for (int col = 0 ; col < obj.tam_cols ; col++) {
            pon_char(obj.pos_fil + fil, obj.pos_col + col, obj.dibujo[fil][col], obj.color, lienzo);
        }
    }
}
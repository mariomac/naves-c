#ifndef NAVES_C_OBJETO_H
#define NAVES_C_OBJETO_H

#include "lienzo.h"

#define MAX_LADO 5

typedef struct {
    int pos_fil, pos_col; // posición del objeto, dada una fila y una columna
    unsigned int tam_fils, tam_cols; // ancho y alto del objeto, en filas y columnas
    int color; // Color del objeto
    char dibujo[MAX_LADO][MAX_LADO]; // Dibujo del objeto, en carácteres ascii
} t_objeto;

void dibuja_objeto(t_objeto obj, t_lienzo *lienzo);

#endif //NAVES_C_OBJETO_H

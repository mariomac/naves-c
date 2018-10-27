//
// Created by Mario Macías on 27/10/18.
//

#ifndef NAVES_C_LIENZO_H
#define NAVES_C_LIENZO_H

/**
 * Este struct representa los datos de un lienzo.
 */
typedef struct {
    int color_fondo;
    unsigned int cols, fils; // Tamaño del lienzo, en filas y columnas
    int **colors;   // Colores
    char **chars; // Caracteres
} t_lienzo;

t_lienzo crea_lienzo(unsigned int filas, unsigned int columnas, int color_fondo);

void destruye_lienzo(t_lienzo *lienzo);

void redibuja_lienzo(t_lienzo *lienzo);

void pon_char(unsigned int fila, unsigned int columna, char caracter, int color, t_lienzo *lienzo);

#endif //NAVES_C_LIENZO_H

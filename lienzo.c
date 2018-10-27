//
// Created by Mario Macías on 27/10/18.
//

#include "betterconsole.h"
#include <stdlib.h>
#include <stdio.h>
#include "lienzo.h"

#define ESPACIO_VACIO ' '

// AVISO: las funcionalidades aquí programadas incluyen algunos temas que no se dan en la asignagtura de Fonaments
// d'Ordinadors. Basta con que uses las funciones. No es necesario que las entiendas.

t_lienzo crea_lienzo(unsigned int filas, unsigned int columnas, int color_fondo) {
    t_lienzo l;
    l.color_fondo = color_fondo;
    l.cols = columnas;
    l.fils = filas;

    // Reservamos memoria para las matrices de tamaño ancho * alto
    l.chars = (char **) malloc(filas * sizeof(char *));
    l.colors = (int **) malloc(filas * sizeof(unsigned int *));
    for (int fil = 0; fil < filas; fil++) {
        l.chars[fil] = (char *) malloc(columnas * sizeof(char));
        l.colors[fil] = (int *) malloc(columnas * sizeof(int));

        // Ponemos como vacias las columnas
        for (int col = 0; col < columnas; col++) {
            l.chars[fil][col] = ESPACIO_VACIO;
        }
    }
    return l;
}

void destruye_lienzo(t_lienzo *lienzo) {
    // Liberamos la memoria dinámica
    for (int x = 0; x < lienzo->fils; x++) {
        free(lienzo->chars[x]);
        free(lienzo->colors[x]);
    }
    free(lienzo->chars);
    free(lienzo->colors);
}

void redibuja_lienzo(t_lienzo *lienzo) {
    set_background(lienzo->color_fondo);
    for (int fil = 0; fil < lienzo->fils; fil++) {
        for (int col = 0; col < lienzo->cols; col++) {
            // Dibuja lo que hay en el pixel para la fila y la columna
            set_position(fil, col);
            set_foreground(lienzo->colors[fil][col]);
            putchar(lienzo->chars[fil][col]);

            // Después de dibujar el pixel, lo vuelve a poner vacío para volver a redibujar luego
            lienzo->chars[fil][col] = ESPACIO_VACIO;
        }
    }
    set_foreground(WHITE);
    set_background(BLACK);
}

void pon_char(unsigned int fila, unsigned int columna, char caracter, int color, t_lienzo *lienzo) {
    if (fila >= lienzo->fils || columna >= lienzo->cols) {
        return; // Evitamos salirnos de los límites de la matriz
    }
    lienzo->chars[fila][columna] = caracter;
    lienzo->colors[fila][columna] = color;
}

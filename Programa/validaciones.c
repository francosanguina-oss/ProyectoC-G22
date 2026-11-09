#include "validaciones.h"
#include "simulador.h"
#include <stdio.h>

void menu_principal(void)  /* esto va en validaciones.c */
{
    int opcion;

    do {
        if (scanf("%d", &opcion) != 1 || getchar() != '\n') {
            opcion = -1;
            while (getchar() != '\n') { }
        }

        if (opcion == 1) {
            Configurar();
        } else if (opcion == 2) {
            Energia_cinetica();
        } else if (opcion == 3) {
            Trabajo();
        } else if (opcion == 4) {
            Simulacion();
        } else if (opcion == 5) {
            Comparar_energia();
        } else if (opcion == 6) {
            Reporte_final();
        } else if (opcion == 0) {
            printf("Gracias por usar esta simulacion!\n");
        } else {
            printf("Opcion no valida. Vuelva a intentarlo.\n");
        }
    } while (opcion != 0);
}
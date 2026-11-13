#include "validaciones.h"
#include "simulador.h"
#include <stdio.h>


void menu_principal(void)  /* esto va en validaciones.c */
{
    int opcion;
    struct Nave minave = {0};             /*nuevo (P)*/ /*todos los valores en nave son 0*/
    Inicializacion_Nave(&minave);

    do {

        printf("------------------------------------\n");
        printf("ARTEMIS - INYECCION TRANSLUNAR (TLI)\n");
        printf("------------------------------------\n");
        printf("1. Configurar mision (masa, velocidad TLI)\n");
        printf("2. Calcular energia cinetica inicial\n");
        printf("3. Calcular trabajo hasta punto de equilibrio\n");
        printf("4. Simular viaje translunar (por turnos)\n");
        printf("5. Comparar combustible ida vs. vuelta\n");
        printf("6. Ver reporte final\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");

        if (scanf("%d", &opcion) != 1 || getchar() != '\n') {
            opcion = -1;
            while (getchar() != '\n') { }
        }

        if (opcion == 1) {
            Configurar(&minave);
        } else if (opcion == 2) {
            Energia_cinetica(&minave);
        } else if (opcion == 3) {
            Trabajo(&minave);
        } else if (opcion == 4) {
            Simulacion(&minave);
        } else if (opcion == 5) {
            Justificacion_energetica();   /* respuesta teorica ida vs. vuelta */
        } else if (opcion == 6) {
            Reporte_final(&minave);
        } else if (opcion == 0) {
            printf("Gracias por usar esta simulacion!\n");
        } else {
            printf("Opcion no valida. Vuelva a intentarlo.\n");
        }
    } while (opcion != 0);
}

double Leer_valor(double min, double max)
{
    double valor;
    int valido;

    do {
        if (scanf("%lf", &valor) != 1 || getchar() != '\n') {
            while (getchar() != '\n') { }
            printf("Error. Debe ingresar un numero: ");
            valido = 0;
        } else if (valor < min || valor > max) {
            printf("Error. El valor debe estar entre %.0f y %.0f: ", min, max);
            valido = 0;
        } else {
            valido = 1;
        }
    } while (valido == 0);

    return valor;
}

bool estaEnMargen(double valor, int objetivo, int margen) 		/* objetivo: valor optimo*/     /* margen: margen de error permitido*/
{
    int minimo = objetivo - margen; /*10 - 10 = 0*/      /* +-10 */
    int maximo = objetivo + margen; /* 10 + 10 = 20 */ 

    if (valor >= minimo && valor <= maximo) 
    { return true;  }  /*dentro de rango*/ 
    else
    { return false; }  /*fuera de rango*/
}
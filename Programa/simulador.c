/*implementacion de algoritmos de simulacion, calculos fisicos,
actualizacion de estado de juego y logica de negocio*/
#include "simulador.h" /* se usa este */
#include <stdio.h>

void Configurar(struct Nave *minave)       /* *minave = minave */ /* ahora P se llama minave */ 
{ 
    int valido;

do {
    printf("introduce masa (entre 10000 y 30000 kg): ");
    if (scanf("%lf", &minave->Masa) != 1 || getchar() != '\n') {
        while (getchar() != '\n') { }          /* limpia lo que quedo escrito */
        printf("Error. Debe ingresar un numero.\n");
        valido = 0;
    } else if (minave->Masa < 10000 || minave->Masa > 30000) {
        printf("Error. La masa debe estar entre 10000 y 30000 kg.\n");
        valido = 0;
    } else {
        valido = 1;
    }
} while (valido == 0);

do {
    printf("Introduce velocidad TLI (entre 7800 y 12000 m/s): ");
    if (scanf("%lf", &minave->Velocidad) != 1 || getchar() != '\n') {
        while (getchar() != '\n') { }
        printf("Error. Debe ingresar un numero.\n");
        valido = 0;
    } else if (minave->Velocidad < 7800 || minave->Velocidad > 12000) {
        printf("Error. La velocidad debe estar entre 7800 y 12000 m/s.\n");
        valido = 0;
    } else {
        valido = 1;
    }
} while (valido == 0);
  printf("introduce com: ");
  scanf("%d", &(*minave).Combustible); 
  
  printf("Masa elegida: %d\n", (*minave).Masa);
  printf("Velocidad elegido: %d\n", (*minave).Velocidad);
  printf("Combustible elegido: %d\n", (*minave).Combustible);

    printf("PROCESO TERMINADO\n"); 
}





void Energia_cinetica(struct Nave *minave) { printf("[Energia cinetica: en construccion]\n"); }
void Trabajo(struct Nave *minave)          { printf("[Trabajo: en construccion]\n"); }
void Simulacion(struct Nave *minave)       { printf("[Simulacion: en construccion]\n"); }
void Comparar_energia(struct Nave *minave) { printf("[Comparar energia: en construccion]\n"); }
void Reporte_final(struct Nave *minave)    { printf("[Reporte final: en construccion]\n"); }
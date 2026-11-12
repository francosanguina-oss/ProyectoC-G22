/*implementacion de algoritmos de simulacion, calculos fisicos,
actualizacion de estado de juego y logica de negocio*/
#include "simulador.h" /* se usa este */
#include <stdio.h>

void Inicializacion_Nave(struct Nave *minave)
{
  (*minave).Masa = 26000;              /*Kg*/
  (*minave).Velocidad = 10900;         /*m/s*/
  (*minave).Altitud = 70000;          /*Km*/
}

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
}





float Energia_cinetica(struct Nave *minave)
{
  float energia;

  energia = 0.5 * (*minave).Masa * (*minave).Velocidad * (*minave).Velocidad;

  printf("La energia cinetica es: %.2f J\n", energia); 
  return energia;
}


void Trabajo(struct Nave *minave)        
{ 
  double trabajo;

  trabajo = 0.5 * (*minave).Masa * (*minave).Velocidad * (*minave).Velocidad;

  printf("Trabajo de la nave: %.2f J\n", trabajo);
}

void Simulacion(struct Nave *minave)       { printf("[Simulacion: en construccion]\n"); }
void Comparar_energia(struct Nave *minave) { printf("[Comparar energia: en construccion]\n"); }
void Reporte_final(struct Nave *minave)    { printf("[Reporte final: en construccion]\n"); }
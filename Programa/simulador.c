/*implementacion de algoritmos de simulacion, calculos fisicos,
actualizacion de estado de juego y logica de negocio*/
#include "simulador.h" /* se usa este */
#include <stdio.h>

void Configurar(void)       
{ 
  struct Nave minave;             /*nuevo (P)*/
  struct Nave *P = &minave;      /* P = minave */
  
  printf("introduce masa: ");
  scanf("%d", &(*P).Masa);       /* esc() = P.masa */  /* scan f se comporta como puntero  *scanf = P.masa */
  
  printf("introduce v: ");
  scanf("%d", &(*P).Velocidad);

  printf("introduce com: ");
  scanf("%d", &(*P).Combustible); 
  
  printf("Masa elegida: %d\n", (*P).Masa);
  printf("Velocidad elegido: %d\n", (*P).Velocidad);
  printf("Combustible elegido: %d\n", (*P).Combustible);

    printf("PROCESO TERMINADO\n"); 
}





void Energia_cinetica(void) { printf("[Energia cinetica: en construccion]\n"); }
void Trabajo(void)          { printf("[Trabajo: en construccion]\n"); }
void Simulacion(void)       { printf("[Simulacion: en construccion]\n"); }
void Comparar_energia(void) { printf("[Comparar energia: en construccion]\n"); }
void Reporte_final(void)    { printf("[Reporte final: en construccion]\n"); }
/*implementacion de algoritmos de simulacion, calculos fisicos,
actualizacion de estado de juego y logica de negocio*/
#include "simulador.h" /* se usa este */
#include <stdio.h>

void Configurar(struct Nave *minave)       /* *minave = minave */ /* ahora P se llama minave */ 
{ 
  
  printf("introduce masa: ");
  scanf("%d", &(*minave).Masa);       /* esc() = P.masa */  /* scan f se comporta como puntero  *scanf = P.masa */
  
  printf("introduce v: ");
  scanf("%d", &(*minave).Velocidad);

  printf("introduce com: ");
  scanf("%d", &(*minave).Combustible); 
  
  printf("Masa elegida: %d\n", (*minave).Masa);
  printf("Velocidad elegido: %d\n", (*minave).Velocidad);
  printf("Combustible elegido: %d\n", (*minave).Combustible);

    printf("PROCESO TERMINADO\n"); 
}





void Energia_cinetica(struct Nave *minave) { printf("[Energia cinetica: en construccion]\n"); }
void Trabajo(struct Nave *minave)         
  double trabajo;

  trabajo = 0.5 * (*minave).Masa * (*minave).Velocidad * (*minave).Velocidad;

  printf("Trabajo de la nave: %.2f J\n", trabajo);
}
void Simulacion(struct Nave *minave)       { printf("[Simulacion: en construccion]\n"); }
void Comparar_energia(struct Nave *minave) { printf("[Comparar energia: en construccion]\n"); }
void Reporte_final(struct Nave *minave)    { printf("[Reporte final: en construccion]\n"); }
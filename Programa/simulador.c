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
  
  printf("introduce Masa: ");
  scanf("%d", &(*minave).Masa);       /* esc() = P.masa */  /* scan f se comporta como puntero  *scanf = P.masa */
  
  printf("introduce Velocidad: ");
  scanf("%d", &(*minave).Velocidad);

  printf("introduce Altitud: ");
  scanf("%d", &(*minave).Altitud); 
  
  printf("Masa elegida: %d\n", (*minave).Masa);
  printf("Velocidad elegido: %d\n", (*minave).Velocidad);
  printf("Altitud elegida: %d\n", (*minave).Altitud);

    printf("PROCESO TERMINADO\n"); 
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

  trabajo = 0.5 * (*minave).Masa * (*minave).Velocidad * (*minave).Velocidad + (*minave).Masa*9.8* (*minave).Altitud;

  printf("Trabajo de la nave: %.2f J\n", trabajo);
}

void Simulacion(struct Nave *minave)       { printf("[Simulacion: en construccion]\n"); }
void Comparar_energia(struct Nave *minave) { printf("[Comparar energia: en construccion]\n"); }
void Reporte_final(struct Nave *minave)    { printf("[Reporte final: en construccion]\n"); }
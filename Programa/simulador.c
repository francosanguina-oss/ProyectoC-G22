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

void Configurar(struct Nave *minave)      
{ 
    int valido;

do {
    printf("introduce masa (entre 10000 y 30000 kg): ");
    if (scanf("%lf", &minave->Masa) != 1 || getchar() != '\n') {
        while (getchar() != '\n') { }          
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

  trabajo = 0.5 * (*minave).Masa * (*minave).Velocidad * (*minave).Velocidad + (*minave).Masa*9.8* (*minave).Altitud;

  printf("Trabajo de la nave: %.2f J\n", trabajo);
}

void Simulacion(struct Nave *minave)       { printf("[Simulacion: en construccion]\n"); }
/* Respuesta teorica: por que la ida requiere mas combustible que el regreso */
void Justificacion_energetica(void) /*simulador.c*/
{
    printf("\n====================================================\n");
    printf("POR QUE LA IDA TIERRA->LUNA REQUIERE MUCHO MAS\n");
    printf("COMBUSTIBLE QUE EL REGRESO LUNA->TIERRA\n");
    printf("====================================================\n\n");

    printf("1. POZOS DE POTENCIAL GRAVITATORIO\n");
    printf("   Energia potencial: U = -G*M*m/r. La energia por kg que\n");
    printf("   hay que aportar para salir de la superficie es:\n");
    printf("     Tierra: G*M_T/R_T ~ 6.26 x 10^7 J/kg  (v_esc ~ 11.2 km/s)\n");
    printf("     Luna:   G*M_L/R_L ~ 2.82 x 10^6 J/kg  (v_esc ~ 2.4 km/s)\n");
    printf("   La Tierra tiene ~81 veces la masa de la Luna y un radio\n");
    printf("   ~3.7 veces mayor, por lo que su pozo es ~22 veces mas\n");
    printf("   profundo.\n\n");

    printf("2. TEOREMA TRABAJO-ENERGIA\n");
    printf("   W = Delta(Ec) = (1/2)*m*(v_f^2 - v_i^2)\n");
    printf("   La energia que debe entregar el combustible crece con\n");
    printf("   el CUADRADO de la velocidad requerida. Para la ida se\n");
    printf("   necesitan del orden de 12 km/s de Delta_v totales desde\n");
    printf("   la superficie (orbita baja + TLI ~ 3.1 km/s). Para el\n");
    printf("   regreso bastan ~2.5-2.7 km/s desde la superficie lunar.\n\n");

    printf("3. ECUACION DEL COHETE (TSIOLKOVSKI)\n");
    printf("   Delta_v = v_e * ln(m_0 / m_f)  =>  m_0/m_f = e^(Delta_v/v_e)\n");
    printf("   La masa de combustible crece EXPONENCIALMENTE con el\n");
    printf("   Delta_v. Un Delta_v ~4-5 veces mayor no implica 4-5 veces\n");
    printf("   mas combustible, sino una cantidad enormemente mayor.\n\n");

    printf("4. EL COMBUSTIBLE TAMBIEN HAY QUE ACELERARLO\n");
    printf("   En la ida, la nave sale cargada con todo el propelente\n");
    printf("   (incluido el que usara despues), y parte de la energia se\n");
    printf("   gasta en elevar esa propia masa. En el regreso la nave\n");
    printf("   ya esta mucho mas liviana (etapas descartadas, combustible\n");
    printf("   ya consumido), asi que cada m/s de Delta_v cuesta menos.\n\n");

    printf("5. LA VUELTA ES 'CUESTA ABAJO' HACIA EL POZO TERRESTRE\n");
    printf("   Al regresar, la nave no necesita escapar de la Tierra,\n");
    printf("   sino caer hacia ella: la energia potencial se convierte\n");
    printf("   en cinetica sin gasto de combustible. Ademas, la\n");
    printf("   atmosfera frena la capsula en la reentrada, disipando la\n");
    printf("   energia cinetica sin propelente.\n\n");

    printf("CONCLUSION:\n");
    printf("   La ida debe vencer un pozo ~22 veces mas profundo, la\n");
    printf("   energia crece con v^2 y el combustible con e^(Delta_v/v_e).\n");
    printf("   El regreso parte de un pozo poco profundo, con una nave\n");
    printf("   ligera, y es ayudado por la gravedad y la atmosfera\n");
    printf("   terrestres. Por eso la ida requiere una masa de\n");
    printf("   combustible significativamente mayor.\n");
    printf("====================================================\n\n");
}
void Reporte_final(struct Nave *minave)    { printf("[Reporte final: en construccion]\n"); }
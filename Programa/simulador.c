/*implementacion de algoritmos de simulacion, calculos fisicos,
actualizacion de estado de juego y logica de negocio*/
#include "simulador.h" /* se usa este */
#include <stdio.h>
#include "validaciones.h"


void Inicializacion_Nave(struct Nave *minave)
{
  (*minave).Masa = 26000;              /*Kg*/
  (*minave).Velocidad = 10900;         /*m/s*/
  (*minave).Altitud = 70000;          /*Km*/
}

void Configurar(struct Nave *minave)
{
    printf("Introduce masa (entre 10000 y 30000 kg): ");
    minave->Masa = Leer_valor(10000, 30000);

    printf("Introduce velocidad TLI (entre 7800 y 12000 m/s): ");
    minave->Velocidad = Leer_valor(7800, 12000);
}

double Energia_cinetica(struct Nave *minave)
{
  double energia;

  energia = 0.5 * (*minave).Masa * (*minave).Velocidad * (*minave).Velocidad;

  printf("La energia cinetica es: %.2f J\n", energia); 
  return energia;
}

double Trabajo(struct Nave *minave)        
{
    /* Constantes físicas para realizar el calculo */
    const double G = 6.67430e-11;
    const double M_TIERRA = 5.972e24;
    const double R_TIERRA = 6371000.0;
    const double M_LUNA = 7.348e22;
    const double D_TIERRA_LUNA = 384400000.0;

    /* 1. Se calculan las distancias de partida */
    double h = 192000.0;
    double r_tierra_ini = R_TIERRA + h;
    double r_luna_ini = D_TIERRA_LUNA - r_tierra_ini;

    /* Calculamos la velocidad orbital inicial */
    double v_ini = sqrt((G * M_TIERRA) / r_tierra_ini);

    /* Calculamos la energia mecanica inicial */	
    double k_ini = 0.5 * v_ini * v_ini;
    double u_ini = -(G * M_TIERRA / r_tierra_ini) - (G * M_LUNA / r_luna_ini);
    double em_ini = k_ini + u_ini;

    /* 2. se calcula el punto de equilibrio gravitatorio (g Tierra == g Luna) */
    double factor = sqrt(M_LUNA / M_TIERRA);
    double r_tierra_eq = D_TIERRA_LUNA / (1.0 + factor);
    double r_luna_eq = D_TIERRA_LUNA - r_tierra_eq;

    /* 3. Calculamos la energia mecanica final */
    double k_fin = 0.0;
    double u_fin = -(G * M_TIERRA / r_tierra_eq) - (G * M_LUNA / r_luna_eq);
    double em_fin = k_fin + u_fin;

    /* 4. Se calcula el trabajo mecanico */
    double trabajo_por_masa = em_fin - em_ini;
    double trabajo_julios = trabajo_por_masa * (*minave).Masa;

    printf("Velocidad orbital calculada: %.2f m/s\n", v_ini);
    printf("Trabajo minimo por unidad de masa: %.2f J/kg\n", trabajo_por_masa);
    printf("Trabajo total de la nave: %.2f J\n", trabajo_julios);

    return trabajo_julios;
}

void Simulacion(struct Nave *minave)       { printf("[Simulacion: en construccion]\n"); }

void Reporte_final(struct Nave *minave)    
{ 
  printf("====================================================\n\n");
  printf("                    REPORTE FINAL	                		\n");
  printf("====================================================\n\n");

  printf("Masa elegida: %d\n", (*minave).Masa);
  printf("Velocidad elegido: %d\n", (*minave).Velocidad);
  printf("Altitud de la nave: %d\n", (*minave).Altitud);
  Energia_cinetica(minave);
  Trabajo(minave);
}


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
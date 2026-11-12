#include "validaciones.h"
#include "simulador.h"
#include <stdio.h>

/* Respuesta teorica: por que la ida requiere mas combustible que el regreso */
void Justificacion_energetica(void)
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

void menu_principal(void)  /* esto va en validaciones.c */
{
    int opcion;
    struct Nave minave = {0};             /*nuevo (P)*/ /*todos los valores en nave son 0*/

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

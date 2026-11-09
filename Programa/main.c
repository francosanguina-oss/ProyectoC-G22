/*MAIN(), menu principal de navegacion, flujo del programa*/
#include "validaciones.h"


int main(void) 
{
        printf("------------------------------------\n");
        printf("ARTEMIS - INYECCION TRANSLUNAR (TLI)\n");
        printf("------------------------------------\n");
        printf("1. Configurar mision (masa, velocidad TLI)\n");
        printf("2. Calcular energia cinetica inicial\n");
        printf("3. Calcular trabajo hasta punto de equilibrio\n");
        printf("4. Simular viaje translunar (por turnos)\n");
        printf("5. Comparar energia ida vs. vuelta\n");
        printf("6. Ver reporte final\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
    menu_principal();
    return 0;
}
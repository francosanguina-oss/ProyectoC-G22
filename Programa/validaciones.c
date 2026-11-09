#include <stdio.h>
#include <validaciones.h>

int main(void)  /*borrar*/
{
    int opcion; // Variable para almacenar el número ingresado

    printf("\n O R I O N - I N Y E C C I O N T R A N S L U N A R\n");
    printf(" Simulacion y juego de fisica (Newton + conservacion de energia)\n");
    printf(" Los datos del enunciado ya estan cargados: elegi 0 para usarlos.\n");
    
    // Solicitar y leer el número del usuario
    printf("\nIngrese su opcion: ");
    scanf("%d", &opcion);

    // Muestra el número ingresado para confirmar que se leyó correctamente
    printf("Seleccionaste la opcion: %d\n", opcion);

    printf("\nFin del programa. Buen viaje!\n");
    return 0;
    }
    void presentacion_programa(void)  /*borrar*/
    {
    printf("\n O R I O N - I N Y E C C I O N T R A N S L U N A R\n");
    printf(" Simulacion y juego de fisica (Newton + conservacion de energia)\n");
    printf(" Los datos del enunciado ya estan cargados: elegi 0 para usarlos.\n");
}

void menu_principal(void)  /* esto va en validaciones.c */
{
    int opcion;

    do {
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

        if (scanf("%d", &opcion) != 1 || getchar() != '\n') {
            opcion = -1;
            while (getchar() != '\n') { }
        }

        if (opcion == 1) {
            Configurar();
        } else if (opcion == 2) {
            Energia_cinetica();
        } else if (opcion == 3) {
            Trabajo();
        } else if (opcion == 4) {
            Simulacion();
        } else if (opcion == 5) {
            Comparar_energia();
        } else if (opcion == 6) {
            Reporte_final();
        } else if (opcion == 0) {
            printf("Gracias por usar esta simulacion!\n");
        } else {
            printf("Opcion no valida. Vuelva a intentarlo.\n");
        }
    } while (opcion != 0);
}
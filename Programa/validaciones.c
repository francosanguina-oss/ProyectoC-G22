#include <stdio.h>
void presentacion_programa(void);
int main(void) {
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
    void presentacion_programa(void) {
    printf("\n O R I O N - I N Y E C C I O N T R A N S L U N A R\n");
    printf(" Simulacion y juego de fisica (Newton + conservacion de energia)\n");
    printf(" Los datos del enunciado ya estan cargados: elegi 0 para usarlos.\n");
}
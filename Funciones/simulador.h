/*declaracion de constantes, definicion de tipos de datos ESTRUCTURADOS
y prototipos de funciones publicas de la simulacion*/
#ifndef SIMULADOR_H
#define SIMULADOR_H

struct Nave
{
double Masa;
double Velocidad;
double Altitud;
};

void Inicializacion_Nave(struct Nave *minave);
void Configurar(struct Nave *minave);
float Energia_cinetica(struct Nave *minave);
void Trabajo(struct Nave *minave);
void Simulacion(struct Nave *minave);
void Comparar_energia(struct Nave *minave);
void Reporte_final(struct Nave *minave);

#endif
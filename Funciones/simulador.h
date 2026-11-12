/*declaracion de constantes, definicion de tipos de datos ESTRUCTURADOS
y prototipos de funciones publicas de la simulacion*/
#ifndef SIMULADOR_H
#define SIMULADOR_H

struct Nave
{
int Masa;
int Velocidad;
int Combustible;
};

void Configurar(struct Nave *minave);
void Energia_cinetica(struct Nave *minave);
void Trabajo(struct Nave *minave);
void Simulacion(struct Nave *minave);
void Comparar_energia(struct Nave *minave);
void Reporte_final(struct Nave *minave);

#endif

void Trabajo(struct Nave *minave)

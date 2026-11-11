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

void Configurar(void);
void Energia_cinetica(void);
void Trabajo(void);
void Simulacion(void);
void Comparar_energia(void);
void Reporte_final(void);

#endif
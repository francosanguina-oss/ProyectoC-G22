# Comision: K1.1

## Integrantes: 

- Lucas Mariano Salas Maidana
- Tiago Ezequiel Pertile Fogar
- Franco Sanguina Comparin


## Descripcion del escenario artemis:

El escenario desarrollado corresponde a una Inyección Translunar (TLI – Trans-Lunar Injection) e Inercia en Trayectoria Libre.

El objetivo del simulador es representar, mediante una experiencia interactiva, las condiciones necesarias para realizar una inyección translunar exitosa, teniendo en cuenta diferentes parámetros físicos relacionados con la misión.


## Reglas de juego: 

El usuario debe ingresar los valores correspondientes a los siguientes parámetros:

- Masa.
- Velocidad.

A partir de estos datos, el simulador evalúa las condiciones de la misión y determina si se cumplen los requisitos necesarios para alcanzar una inyección translunar exitosa.

El objetivo del juego es ingresar los valores adecuados para lograr completar la misión Artemis.


## Breve detalle de funcionamiento:

Al iniciar el programa, se solicitan al usuario los datos necesarios para configurar la misión.

Una vez ingresados los valores, el simulador realiza las correspondientes validaciones y determina el resultado:

- Misión exitosa: los parámetros ingresados cumplen con las condiciones establecidas para realizar la inyección translunar.
- Misión fallida: los parámetros no cumplen con las condiciones necesarias. En este caso, el programa informa el motivo del fracaso y proporciona indicaciones sobre qué valores podrían modificarse para conseguir un resultado exitoso.

De esta manera, el usuario puede realizar distintos intentos y comprender cómo influyen los parámetros ingresados en el desarrollo de la misión.


# Instrucciones claras de compilación y ejecución; 


Usamos visual studio para la creacion y compilacion del codigo.
Para ejecutar el simulador, asegúrese de tener instalado el compilador de C llamado "gcc" en su sistema.

## Pasos para compilar y ejecutar (Opcion 1)

1. Abra la terminal en la raíz del proyecto (Proyecto_Artemis).


2. Compilar y ejecutar el proyecto:


### coloque el siguiente codigo en la terminal:

    mingw32-make run


## Pasos para compilar y ejecutar: (Opcion 2)

1. Abra la terminal en la raíz del proyecto (Proyecto_Artemis).


2. Compilar el proyecto:


### coloque el siguiente codigo en la terminal:


    gcc Programa/*.c -I funciones -I C:/raylib/raylib/src -L C:/raylib/raylib/src -o programa -lraylib -lopengl32 -lgdi32 -lwinmm -lm
    

3. Ejecutar el simulador:


### coloque el siguiente codigo en la terminal


    .\programa.exe


## VIDEO:

En el siguiente apartado se incorporará un video demostrativo del funcionamiento del simulador Artemis.

https://www.youtube.com/watch?v=btOCAQT4YaY


## Registro detallado del uso de Inteligencia Artificial:

Las herramientas de Inteligencia Artificial se utilizaron como recursos de consulta y apoyo durante el proceso de desarrollo. Las explicaciones y sugerencias obtenidas fueron analizadas y aplicadas por los integrantes del grupo para comprender los problemas encontrados y avanzar en la implementación del proyecto.

* Las IA usadas para generar ideas y resolver dudas fueron: Gemini y Claude


* El orden del registro de preguntas es el siguiente: "Pregunta" [adaptacion] (IA usada):


"como usar files .c y .h en c" [nos enfrentamos a la modularizacion y no comprendiamos porque se necesitaban tantos files.. al final gracias a las explicaciones de gemini pudimos comprender que los 'files.h' pueden entenderse como el 'ambiente' y los 'files.c' el 'proceso'] (gemini)


"error 'Include is not used'" [el codigo no lee los include porque no los necesita, nos
dimos cuenta que teniamos muchos include puestos en lugares donde no ameritaba, quitamos los include
que no pertenecian] (gemini)


"problema, no se compila el codigo por error 'No such file or directory en #include 'validacion.h'" 
[gcc no podia correr el codigo correctamente dentro de visual studio code, la terminal generaba errores porque solo leia un file local sin tener en cuenta el resto, por tanto gemini facilitó un comando para que gcc que permite ejecutar el codigo en la terminal sin ningun error] (gemini)


"Como hacer Apartados visuales en raylib" [raylib se nos fue recomendada, se decia que era una herramienta facil de usar y simple por lo que optamos por su uso, la IA nos mostro formas de como usarla y adaptamos sus ejemplos a nuestro codigo, asi logrando un apartado visual en la simulacion] (Claude y gemini)


"#include 'Raylib.h' da error y no se consigue compilar" [Enfrentamos un problema en el cual nuestra libreria de raylib no conseguia compilar, se nos dijo que el problema se podia resolver incluyendo un path en la extension de c/c++, gracias a hacer este arreglo se puedo ejecutar el codigo] (Claude)

Comision: K1.1

Integrantes: 

Lucas Mariano Salas Maidana

Tiago Ezequiel Pertile Fogar

Franco Sanguina Comparin

Descripcion del escenario artemis:
nuestro escenario fue el de una Inyección Translunar — TLI e Inercia en Trayectoria Libre


Reglas de juego: debes ingresar los datos correctos para lograr una inyección translunar


Breve detalle de funcionamiento: La simulacion empieza pidiendote datos los cuales debes ingresar (masa, velocidad, combustible) segun los datos que elegiste la mision será un exito o fracaso, en caso de fracaso se te dictará porqué fracasaste y como lo puedes cambiar. 



Instrucciones claras de compilación y ejecución; 


Usamos visual studio para la creacion y compilacion del codigo.
Para ejecutar el simulador, asegúrese de tener instalado el compilador de C llamado "gcc" en su sistema.

### Pasos para compilar y ejecutar:

1. Abra la terminal en la raíz del proyecto (Proyecto_Artemis).


2. Compilar el proyecto:


## coloque el siguiente codigo en la terminal:


    gcc Programa/*.c -I funciones -o programa
    

3. Ejecutar el simulador:


## coloque el siguiente codigo en la terminal


    .\programa.exe


VIDEO:

Registro detallado del uso de Inteligencia Artificial:


* Las IA usadas para generar ideas y resolver dudas fueron: Gemini y Claude


* El orden del registro de preguntas es el siguiente: "Pregunta" [adaptacion] (IA usada):


"como usar files .c y .h en c" [nos enfrentamos a la modularizacion y no comprendiamos porque se necesitaban tantos files.. al final gracias a las explicaciones de gemini pudimos comprender que los 'files.h' pueden entenderse como el 'ambiente' y los 'files.c' el 'proceso'] (gemini)


"error 'Include is not used'" [el codigo no lee los include porque no los necesita, nos
dimos cuenta que teniamos muchos include puestos en lugares donde no ameritaba, quitamos los include
que no pertenecian] (gemini)


"problema, no se compila el codigo por error 'No such file or directory en #include 'validacion.h'" 
[gcc no podia correr el codigo correctamente dentro de visual studio code, la terminal generaba errores porque solo leia un file local sin tener en cuenta el resto, por tanto gemini facilitó un comando para que gcc que permite ejecutar el codigo en la terminal sin ningun error] (gemini)

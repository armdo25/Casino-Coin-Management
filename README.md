# Casino-Coin-Management

Casino Coin Management es una continuación de mi proyecto anterior de apuestas deportivas en C++. En esta nueva versión se busca aprovechar los datos de los apostadores para poder organizarlos y analizar su rendimiento.

El programa guarda información de diferentes apostadores, como su nombre, número de apuestas, dinero total apostado y ganancia o pérdida. A partir de estos datos se calcula su rendimiento y se utiliza un algoritmo de ordenamiento para acomodarlos de mayor a menor.

También se hace una clasificación sencilla entre apostadores comunes y profesionales. Para este proyecto se considera profesional a un apostador que tenga mínimo 10 apuestas registradas y que tenga un rendimiento positivo. Esta regla solamente se usa para la simulación del proyecto.


# Descripción del avance 1

En este primer avance se trabajó principalmente con el ordenamiento de los datos.

Se creó una clase `Apostador` que guarda la información de cada jugador y una clase `Ordenamiento` donde se encuentra el algoritmo MergeSort.

Los apostadores se guardan dentro de un vector y cada uno contiene:

- ID
- Nombre
- Número de apuestas
- Dinero total apostado
- Ganancia o pérdida neta

El rendimiento se calcula de la siguiente manera:

```text
rendimiento = (gananciaNeta / totalApostado) * 100
```

Después se utiliza MergeSort para ordenar los apostadores desde el que tiene mayor rendimiento hasta el que tiene menor rendimiento.

El programa también cuenta con un menú donde se pueden consultar todos los apostadores, ordenarlos por rendimiento o mostrar solamente los comunes o profesionales.

Por el momento los datos se encuentran directamente en el `main.cpp`, ya que en este avance lo importante es probar el algoritmo de ordenamiento. Más adelante estos datos podrían salir del historial de apuestas del proyecto original de Casino Coin.


# Instrucciones para compilar el avance de proyecto

Para compilar el programa se utiliza:

```text
g++ main.cpp Apostador.cpp Ordenamiento.cpp -std=c++11 -o primer_avance
```

En Windows también se puede utilizar:

```text
g++ main.cpp Apostador.cpp Ordenamiento.cpp -std=c++11 -o primer_avance.exe
```


# Instrucciones para ejecutar el avance de proyecto

En Windows:

```text
.\primer_avance.exe
```

En Mac o Linux:

```text
./primer_avance
```

Al ejecutar el programa aparece un menú parecido al siguiente:

```text
===== CASINO COIN - ANALISIS DE APOSTADORES =====

1. Ver los datos almacenados
2. Ordenar los apostadores por rendimiento
3. Mostrar apostadores comunes
4. Mostrar apostadores profesionales
5. Salir
```


# Descripción de las entradas del avance de proyecto

En este avance los datos de los apostadores ya se encuentran guardados directamente en el programa.

Cada apostador tiene un ID, nombre, cantidad de apuestas, dinero apostado y su ganancia o pérdida.

La entrada que realiza el usuario es principalmente la opción del menú, ingresando un número del 1 al 5 dependiendo de lo que quiera hacer.


# Descripción de las salidas del avance de proyecto

El programa muestra los datos de los apostadores directamente en la consola.

Dependiendo de la opción seleccionada se pueden mostrar todos los apostadores, ordenarlos por rendimiento o mostrar solamente los apostadores comunes o profesionales.

También se muestra el rendimiento de cada uno para poder observar más fácilmente la diferencia entre los resultados de los jugadores.


# Desarrollo de competencias

## SICT0301: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa

El algoritmo utilizado en el proyecto es MergeSort.

MergeSort divide el vector de apostadores en partes más pequeñas hasta tener elementos individuales. Después vuelve a juntar las partes mientras compara el rendimiento de los apostadores para acomodarlos.

Como el vector se divide aproximadamente a la mitad cada vez, se tienen aproximadamente `log n` niveles. En cada nivel se recorren los elementos para volverlos a juntar, por lo que el algoritmo tiene una complejidad de `O(n log n)`.

Sus complejidades son:

- Mejor caso: `O(n log n)`
- Caso promedio: `O(n log n)`
- Peor caso: `O(n log n)`
- Complejidad de espacio: `O(n)`

La complejidad de espacio es `O(n)` porque se utilizan vectores auxiliares para poder combinar los elementos durante el ordenamiento.

Este algoritmo se puede observar en los archivos `Ordenamiento.hpp` y `Ordenamiento.cpp`.


## SICT0302: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente

Para el proyecto decidí utilizar MergeSort porque permite ordenar los apostadores de acuerdo con su rendimiento y mantiene una complejidad de `O(n log n)` incluso en el peor caso.

También existen algoritmos más sencillos como Bubble Sort, Selection Sort o Insertion Sort, pero estos pueden llegar a una complejidad de `O(n²)`.

Como en un casino pueden existir muchos apostadores, MergeSort me pareció una mejor opción para organizar los datos conforme aumente la cantidad de usuarios.

En este proyecto el algoritmo compara el rendimiento de cada apostador y los acomoda de mayor a menor. De esta forma los jugadores con mejor rendimiento aparecen primero y los que tienen peor rendimiento aparecen al final.

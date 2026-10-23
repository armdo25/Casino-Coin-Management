# Casino-Coin-Management

Casino Coin Management es una herramienta que continúa mi proyecto anterior de apuestas deportivas en C++. En esta proyecto se busca aprovechar los datos de los apostadores para poder organizarlos y analizar su rendimiento.

El programa guarda información de diferentes apostadores, como su nombre, número de apuestas, dinero total apostado y ganancia o pérdida. A partir de estos datos se calcula su rendimiento y se utiliza un algoritmo de ordenamiento para acomodarlos de mayor a menor.

También se hace una clasificación sencilla entre apostadores comunes y profesionales, osea, ara este proyecto se considera profesional a un apostador que tenga mínimo 10 apuestas registradas y que tenga un rendimiento positivo. Esta regla solamente se usa para la simulación del proyecto.

Para la entrega final quiero que el programa permita cargar los datos de los apostadores desde un archivo, organizarlos, consultar su informacion y guardar los datos cuando sea necesario.

En este segundo avance se implementa el almacenamiento en una lista enlazada, la lectura de archivos y las consultas. El guardado de
archivos se realizará en el tercer avance.

# Descripción del avance 1

En el primer avance se trabajó principalmente con el ordenamiento de los datos. Se creó una clase `Apostador` que guarda la información de cada jugador y una clase `Ordenamiento` donde se encuentra el algoritmo MergeSort.

Los apostadores se guardaban dentro de un vector y cada uno contiene:

- ID
- Nombre
- Número de apuestas
- Dinero total apostado
- Ganancia o pérdida neta

El rendimiento se calcula de la siguiente manera:

```text
rendimiento = (gananciaNeta / totalApostado) * 100
```

Después se utilizó MergeSort para ordenar los apostadores desde el que tiene mayor rendimiento hasta el que tiene menor rendimiento. El programa también cuenta con un menú donde se pueden consultar todos los apostadores, ordenarlos por rendimiento o mostrar solamente los comunes o profesionales. Los datos se encontraban directamente en el `main.cpp`,sin embargo, ahora se consultan desde el .csv, ya que en este avance lo importante era probar el algoritmo de ordenamiento.

# Descripción del avance 2

En este avance se agregó una lista simplemente enlazada para almacenar los datos de los apostadores.

Cada nodo de la lista contiene un objeto Apostador y un puntero al siguiente nodo. También se utiliza un puntero al último nodo para agregar registros sin recorrer toda la lista.

Los datos ahora se cargan desde el archivo apostadores.csv, en lugar de escribirlos directamente en el main.

Para ordenar los apostadores se conserva Merge Sort del primer avance. Los datos se pasan temporalmente a un vector, se ordenan y después se acomodan nuevamente en la lista.

También se agregó una búsqueda por ID y se conservaron las consultas de apostadores comunes y profesionales.

# Instrucciones para compilar el avance de proyecto

Para compilar el programa se utiliza:

```text
g++ main.cpp Apostador.cpp Ordenamiento.cpp ListaApostadores.cpp ArchivoApostadores.cpp -o casino
```


Al ejecutar el programa aparece un menú parecido al siguiente:

```text
===== CASINO COIN =====
1. Mostrar apostadores
2. Ordenar por rendimiento
3. Mostrar apostadores comunes
4. Mostrar apostadores profesionales
5. Buscar apostador por ID
6. Salir
```


# Descripción de las entradas de los avances de proyecto

En el avance 1, los datos de los apostadores se encontraban guardados directamente en el programa. O sea, cada apostador tiene un ID, nombre, cantidad de apuestas, dinero apostado y su ganancia o pérdida. Por lo tanto, la entrada que realizaba el usuario es principalmente la opción del menú, ingresando un número del 1 al 5 dependiendo de lo que quiera hacer.

Para este avance 2, prácticamente todo funciona de igual manera a excepción del manejo de los datos de los apostadores, que antes se manejaban principalmente desde el main, pero ahora se consultan desde el archivo .csv.


# Descripción de las salidas de los avances de proyecto

La salidas del avance 1 y 2 son prácticmante las mismas: El programa muestra los datos de los apostadores directamente en la consola. Dependiendo de la opción seleccionada se pueden mostrar todos los apostadores, ordenarlos por rendimiento o mostrar solamente los apostadores comunes o profesionales. También se muestra el rendimiento de cada uno para poder observar más fácilmente la diferencia entre los resultados de los jugadores. Además de mostrar los resultados de búsqueda por ID.


# Desarrollo de competencias

## SICT0301: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa

El algoritmo utilizado en el proyecto es MergeSort, el cual divide el vector de apostadores en partes más pequeñas hasta tener elementos individuales. Después vuelve a juntar las partes mientras compara el rendimiento de los apostadores para acomodarlos. Como el vector se divide aproximadamente a la mitad cada vez, se tienen aproximadamente `log n` niveles. En cada nivel se recorren los elementos para volverlos a juntar, por lo que el algoritmo tiene una complejidad de `O(n log n)`.

Sus complejidades son:

- Mejor caso: `O(n log n)`
- Caso promedio: `O(n log n)`
- Peor caso: `O(n log n)`
- Complejidad de espacio: `O(n)`

La complejidad de espacio es `O(n)` porque se utilizan vectores auxiliares para poder combinar los elementos durante el ordenamiento.
NOTA: el algoritmo es visible en los archivos `Ordenamiento.hpp` y `Ordenamiento.cpp`.

### Análisis de complejidad de las estructuras de datos

Para el avance 2 se utilizó una lista simplemente enlazada para almacenar los apostadores. Sus complejidades son:

- Crear la lista: O(1).
- Agregar un apostador: O(1), porque se utiliza un puntero al último nodo.
- Mostrar todos los apostadores: O(n).
- Buscar por ID: O(n).
- Consultar por categoría: O(n).
- Obtener la cantidad de apostadores: O(1).
- Pasar la lista a un vector: O(n).
- Acomodar los datos ordenados en la lista: O(n).
- Eliminar los nodos al terminar: O(n).

También se utiliza un vector para ordenar los datos. Agregar elementos con push_back tiene complejidad O(1) amortizada, acceder por posición O(1) y recorrerlo O(n).

La lista ocupa O(n) de memoria. El vector temporal y Merge Sort también requieren O(n) de espacio adicional. La complejidad de Merge Sort sigue siendo O(n log n).


## SICT0302: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente

Para el proyecto decidí utilizar MergeSort porque permite ordenar los apostadores de acuerdo con su rendimiento y mantiene una complejidad de `O(n log n)` incluso en el peor caso. También existen algoritmos más sencillos como Bubble Sort, Selection Sort o Insertion Sort, pero estos pueden llegar a una complejidad de `O(n²)` y como en un casino pueden existir muchos apostadores, MergeSort me pareció una mejor opción para organizar los datos conforme aumente la cantidad de usuarios. En este proyecto el algoritmo compara el rendimiento de cada apostador y los acomoda de mayor a menor. De esta forma los jugadores con mejor rendimiento aparecen primero y los que tienen peor rendimiento aparecen al final.

### Selección de una estructura de datos adecuada

Para el avance 2 elegí una lista simplemente enlazada porque permite agregar los apostadores conforme se leen del archivo .csv. Como la lista tiene un puntero al último nodo, no es necesario recorrerla para insertar nuevos registros.

También permite consultar los apostadores recorriendo sus nodos y buscar uno por su ID.

Decidí conservar el vector para utilizar el Merge Sort del primer avance sin cambiar su funcionamiento. De esta manera, la lista almacena los datos y el vector se utiliza para ordenarlos.

## SICT0303: Implementa acciones científicas

### Implementa mecanismos de consulta de información

El programa permite consultar todos los apostadores, mostrar solamente los comunes o profesionales y buscar un apostador por su ID.

Estas consultas se realizan utilizando las funciones de ListaApostadores.cpp. La búsqueda por ID recorre la lista hasta encontrar el registro o llegar al final.

### Implementa mecanismos de lectura de archivos

Se agregó el archivo apostadores.csv, donde se encuentran los datos de los apostadores.

En ArchivoApostadores.cpp se utiliza ifstream para abrir el archivo y leer cada registro. Después se separan los datos y se agregan a la lista enlazada.

Si el archivo no existe, el programa muestra un mensaje de error. Si algún registro contiene datos numéricos incorrectos, se omite.

La lectura de n registros tiene una complejidad O(n), considerando que cada registro tiene un tamaño limitado.

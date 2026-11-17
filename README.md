# Casino-Coin-Management

Casino Coin Management es una herramienta que continúa mi proyecto anterior de apuestas deportivas en C++. En esta proyecto se busca aprovechar los datos de los apostadores para poder organizarlos y analizar su rendimiento.

El programa guarda información de diferentes apostadores, como su nombre, número de apuestas, dinero total apostado y ganancia o pérdida. A partir de estos datos se calcula su rendimiento y se utiliza un algoritmo de ordenamiento para acomodarlos de mayor a menor.

También se hace una clasificación sencilla entre apostadores comunes y profesionales, osea, ara este proyecto se considera profesional a un apostador que tenga mínimo 10 apuestas registradas y que tenga un rendimiento positivo. Esta regla solamente se usa para la simulación del proyecto.

Para la entrega final quiero que el programa permita cargar los datos de los apostadores desde un archivo, organizarlos, consultar su informacion y guardar los datos cuando sea necesario.

En el segundo avance se implementó el almacenamiento en una lista enlazada, la lectura de archivos y las consultas. Ahora, en el tercer avance se agregó el guardado de archivos y un índice ordenado por ID para realizar búsquedas binarias. También se corrigieron los errores de compilación y se agregaron validaciones para los datos del archivo y las entradas del menú.

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

# Descripción del avance 3

En este avance se completó el flujo de cargar, organizar, consultar y guardar los datos de los apostadores.

Se conserva la lista simplemente enlazada del avance 2 como almacenamiento principal y el algoritmo Merge Sort del avance 1 para ordenar por rendimiento. Además, se agregó la clase `IndiceApostadores`, que mantiene una copia de los registros en un vector ordenado por ID y permite realizar búsquedas binarias.

También se agregó la función `guardarApostadores`, que escribe los registros de la lista en `apostadores.csv`. De esta manera, el orden obtenido durante la ejecución puede conservarse al cerrar y volver a abrir el programa.

Se mejoraron las validaciones del CSV y del menú para detectar registros incorrectos, IDs repetidos y entradas que no corresponden a números enteros.

## Cambios sobre el segundo avance

### Corrección de los errores de compilación

En el avance 2, una llave cerraba el ciclo del menú antes de procesar las opciones. En el avance 3 se corrigió su ubicación para que las acciones se ejecuten dentro del ciclo.

También se corrigieron las condiciones de Merge Sort. Las variables `totalIzquierda` y `totalDerecha` ya contienen tamaños de tipo entero, por lo que se eliminaron las llamadas incorrectas a `.size()` sobre ellas.

Estos cambios se encuentran en `main.cpp` y `Ordenamiento.cpp`.

### Cambio en la búsqueda por ID

En el avance 2, la búsqueda del menú recorría la lista enlazada hasta encontrar el ID o llegar al final.

En el avance 3, esa consulta utiliza búsqueda binaria mediante `IndiceApostadores`. El índice se construye una vez después de cargar el archivo y se mantiene ordenado por ID, aunque la lista se ordene por rendimiento.

La búsqueda secuencial de `ListaApostadores` se conserva, pero ahora se utiliza durante la carga para detectar IDs repetidos.

### Ampliación del ordenamiento

En los avances anteriores, Merge Sort ordenaba únicamente por rendimiento de mayor a menor.

En el avance 3 se agregó `ordenarPorId`, que reutiliza Merge Sort para ordenar de menor a mayor por ID. El parámetro `porId` permite elegir la comparación utilizada durante la combinación.

### Validación de la lectura

En el avance 2 ya se leían registros desde el CSV y se validaban algunos de sus valores.

En el avance 3 también se comprueba el encabezado, la cantidad de campos, los nombres en blanco y los IDs repetidos. Las filas rechazadas muestran su número de línea. Si un ID se repite, se conserva el primer registro válido.

### Escritura del archivo

En el avance 2 todavía no se implementaba el guardado.

En el avance 3 se agregó la opción 6 para escribir los registros en `apostadores.csv`. La opción 7 permite salir. El guardado reemplaza el contenido del archivo con los registros válidos de la lista y conserva su orden actual.

### Validación del menú

Se agregó `leerEntero` para comprobar que cada entrada contenga un número entero sin caracteres adicionales. Por ejemplo, se rechazan entradas como `menú`, `2.5` o `7abc`.

También se comprueba que los IDs sean positivos y se muestran mensajes cuando una categoría no tiene resultados o cuando no hay registros cargados.

# Instrucciones para compilar el avance de proyecto

Para compilar el programa se utiliza:

```text
g++ main.cpp Apostador.cpp Ordenamiento.cpp ListaApostadores.cpp ArchivoApostadores.cpp IndiceApostadores.cpp -o casino
```


Al ejecutar el programa aparece un menú parecido al siguiente:

```text
===== CASINO COIN =====
1. Mostrar apostadores
2. Ordenar por rendimiento
3. Mostrar apostadores comunes
4. Mostrar apostadores profesionales
5. Buscar apostador por ID
6. Guardar datos en apostadores.csv
7. Salir
```


# Descripción de las entradas de los avances de proyecto

En el avance 1, los datos de los apostadores se encontraban guardados directamente en el programa. O sea, cada apostador tiene un ID, nombre, cantidad de apuestas, dinero apostado y su ganancia o pérdida. Por lo tanto, la entrada que realizaba el usuario es principalmente la opción del menú, ingresando un número del 1 al 5 dependiendo de lo que quiera hacer.

Para el avance 2, prácticamente todo funciona de igual manera a excepción del manejo de los datos de los apostadores, que antes se manejaban principalmente desde el main, pero ahora se consultan desde el archivo .csv. Para el avance 3 se mantiene el archivo `apostadores.csv` con este encabezado: csv, id,nombre,apuestas,totalApostado,ganancia.



# Descripción de las salidas de los avances de proyecto

La salidas del avance 1 y 2 son prácticmante las mismas: El programa muestra los datos de los apostadores directamente en la consola. Dependiendo de la opción seleccionada se pueden mostrar todos los apostadores, ordenarlos por rendimiento o mostrar solamente los apostadores comunes o profesionales. También se muestra el rendimiento de cada uno para poder observar más fácilmente la diferencia entre los resultados de los jugadores. Además de mostrar los resultados de búsqueda por ID.

En el avance 3 se mantienen las consultas en consola y se agregan mensajes sobre registros rechazados, entradas inválidas, categorías sin resultados y resultado del guardado. La nueva salida en archivo se genera mediante la opción 6. Esta opción reemplaza el contenido de `apostadores.csv` con los registros válidos almacenados en la lista, respetando su orden actual.

Por ejemplo: Si primero se ordena por rendimiento y después se guarda, al volver a ejecutar el programa los registros se cargan en ese orden. El rendimiento y la categoría no se escriben como columnas adicionales ya que se calculan a partir de los cinco datos originales.

Por último, salir del programa no guarda automáticamente ya que las filas rechazadas durante la carga no se incluyen al guardar. Si no hay apostadores cargados, el menú permite salir pero bloquea las demás opciones.


# Desarrollo de competencias

## SICT0301: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa

El algoritmo utilizado en el proyecto es MergeSort, el cual divide el vector de apostadores en partes más pequeñas hasta tener elementos individuales. Después vuelve a juntar las partes mientras compara el rendimiento de los apostadores para acomodarlos. Como el vector se divide aproximadamente a la mitad cada vez, se tienen aproximadamente `log n` niveles. En cada nivel se recorren los elementos para volverlos a juntar, por lo que el algoritmo tiene una complejidad de `O(n log n)`.

Aclaración: en el avance 3 se utiliza el mismo algoritmo para construir el índice ordenado por ID. Y aunque cambia el criterio de comparación, se mantienen las complejidades de O(n log n) en el mejor caso, promedio y peor caso, y O(n) de memoria auxiliar.

La función `merge` combina k elementos en O(k). Si el vector contiene cero o un registro, las funciones públicas de ordenamiento terminan en O(1).

Al ordenar por rendimiento, cuando dos registros tienen el mismo valor se toma primero el de la mitad izquierda. Esto conserva su orden relativo anterior.

Sus complejidades son:

- Mejor caso: `O(n log n)`
- Caso promedio: `O(n log n)`
- Peor caso: `O(n log n)`
- Complejidad de espacio: `O(n)`

La complejidad de espacio es `O(n)` porque se utilizan vectores auxiliares para poder combinar los elementos durante el ordenamiento.
NOTA: el algoritmo es visible en los archivos `Ordenamiento.hpp` y `Ordenamiento.cpp`.

### Análisis de complejidad de las estructuras de datos

Para el avance 2 se utilizaba una lista simplemente enlazada para almacenar los apostadores. Sus complejidades son:

- Crear la lista: O(1).
- Agregar un apostador: O(1), porque se utiliza un puntero al último nodo.
- Mostrar todos los apostadores: O(n).
- Buscar por ID: O(n).
- Consultar por categoría: O(n).
- Obtener la cantidad de apostadores: O(1).
- Pasar la lista a un vector: O(n).
- Acomodar los datos ordenados en la lista: O(n).
- Eliminar los nodos al terminar: O(n).

También se utilizaba un vector para ordenar los datos. Agregar elementos con push_back tiene complejidad O(1) amortizada, acceder por posición O(1) y recorrerlo O(n).

La lista ocupaba O(n) de memoria. El vector temporal y Merge Sort también requerían O(n) de espacio adicional. La complejidad de Merge Sort seguía siendo O(n log n).

Aclaración: en el avance 2 se describían los costos de la lista, pero faltaba distinguir el mejor caso, promedio y peor caso. En el avance 3 se completa esa comparación y se incluye el índice por ID.

En las tablas, n representa la cantidad de registros almacenados. Se consideran nombres y registros de tamaño limitado, además que los casos promedio de búsqueda suponen probabilidades comparables de consultar los distintos registros.

| Operación | Mejor caso | Caso promedio | Peor caso |
|---|---|---|---|
| Crear la lista o un nodo | O(1) | O(1) | O(1) |
| Agregar al final de la lista | O(1) | O(1) | O(1) |
| Obtener la cantidad | O(1) | O(1) | O(1) |
| Mostrar todos | O(n) | O(n) | O(n) |
| Filtrar por categoría | O(n) | O(n) | O(n) |
| Buscar por ID en la lista | O(1) | O(n) | O(n) |
| Pasar la lista a un vector | O(n) | O(n) | O(n) |
| Acomodar n registros en la lista | O(n) | O(n) | O(n) |
| Destruir la lista | O(n) | O(n) | O(n) |
| Construir el índice por ID | O(n log n) | O(n log n) | O(n log n) |
| Buscar por ID en el índice | O(1) | O(log n) | O(log n) |

Agregar al final es O(1) porque se utiliza el puntero `ultimo`. Este costo no incluye la búsqueda previa para detectar duplicados.

La búsqueda en la lista tiene mejor caso O(1) si el registro está en el primer nodo. En la búsqueda binaria, el mejor caso ocurre si el registro se encuentra en la primera posición central revisada.

Mostrar todos o filtrar por categoría requiere recorrer la lista completa. El filtro sigue siendo O(n) aunque no encuentre coincidencias.

En el programa, `acomodar` recibe un vector del mismo tamaño que la lista. Si recibiera k elementos, recorrería como máximo min(n, k).

Construir el índice incluye copiar los registros y ordenarlos por ID. Para cero o un registro tiene costo O(1).

Y sobre las operaciones de los vectores...

Acceder por posición y consultar `size()` cuestan O(1). Copiar, recorrer o destruir un vector de n registros requiere O(n), considerando registros de tamaño limitado.

Una inserción individual con `push_back` puede costar O(n) cuando se amplía la capacidad, pero su costo normal es O(1). Por eso, realizar n inserciones consecutivas requiere O(n) en total.

La lista ocupa O(n) de memoria. El índice conserva copias de los registros y ocupa O(n) adicional y los vectores temporales de ordenamiento y guardado también requieren O(n).


## SICT0302: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente

Para el proyecto decidí utilizar MergeSort porque permite ordenar los apostadores de acuerdo con su rendimiento y mantiene una complejidad de `O(n log n)` incluso en el peor caso. También existen algoritmos más sencillos como Bubble Sort, Selection Sort o Insertion Sort, pero estos pueden llegar a una complejidad de `O(n²)` y como en un casino pueden existir muchos apostadores, MergeSort me pareció una mejor opción para organizar los datos conforme aumente la cantidad de usuarios. En este proyecto el algoritmo compara el rendimiento de cada apostador y los acomoda de mayor a menor. De esta forma los jugadores con mejor rendimiento aparecen primero y los que tienen peor rendimiento aparecen al final.

### Selección de una estructura de datos adecuada

Para el avance 2 elegí una lista simplemente enlazada porque permite agregar los apostadores conforme se leen del archivo .csv. Como la lista tiene un puntero al último nodo, no es necesario recorrerla para insertar nuevos registros. También permite consultar los apostadores recorriendo sus nodos y buscar uno por su ID. Decidí conservar el vector para utilizar el Merge Sort del primer avance sin cambiar su funcionamiento. De esta manera, la lista almacena los datos y el vector se utiliza para ordenarlos.

Revisión de la decisión en el avance 3: en el avance 2, la selección de la lista se justificó principalmente por la inserción al final en O(1). Sin embargo, la retroalimentación señaló que también era necesario considerar la búsqueda.

Buscar por ID en la lista requiere O(n) en promedio y en el peor caso. Por eso en el avance 3 se agregó un vector ordenado por ID para aplicar búsqueda binaria con costo O(log n). La lista mantiene los registros y el orden utilizado para mostrarlos y guardarlos. Adicionalmente, el índice mantiene copias ordenadas por ID y se utiliza para las consultas del menú. Ordenar la lista por rendimiento no modifica ese índice.

Esta decisión requiere O(n) adicional de memoria y O(n log n) para preparar el índice. Se aprovecha que los registros se cargan una vez y después se consultan varias veces. Además, un vector como almacenamiento principal también sería una alternativa válida para las operaciones actuales. Vale recalcar que se conserva la lista para dar continuidad al avance 2 y utilizar sus operaciones con nodos, reconociendo que no es la mejor estructura por sí sola para búsquedas frecuentes.


## SICT0303: Implementa acciones científicas

### Implementa mecanismos de consulta de información

El programa permite consultar todos los apostadores, mostrar solamente los comunes o profesionales y buscar un apostador por su ID.

En el avance 2, estas consultas se realizaban mediante las funciones de `ListaApostadores.cpp`. La búsqueda por ID recorría la lista hasta encontrar el registro o llegar al final.

Ahora bien, en el avance 3 `mostrarTodos` y `mostrarPorCategoria` siguen recorriendo la lista. La consulta por ID del menú utiliza `IndiceApostadores::buscarPorId` que aplica búsqueda binaria sobre el vector ordenado.

Además, la búsqueda secuencial de la lista se conserva para detectar duplicados durante la carga. Ambas búsquedas devuelven un puntero al registro encontrado o `0` si no existe y el programa comprueba el resultado antes de acceder a sus datos.

### Implementa mecanismos de lectura de archivos

Se agregó el archivo apostadores.csv, donde se encuentran los datos de los apostadores.

En ArchivoApostadores.cpp se utiliza ifstream para abrir el archivo y leer cada registro. Después se separan los datos y se agregan a la lista enlazada.

Si el archivo no existe, el programa muestra un mensaje de error. Si algún registro contiene datos numéricos incorrectos, se omite.

En el avance 2, leer e insertar n registros tenía costo O(n), considerando registros de tamaño limitado pero para el avance 3 se agregó una búsqueda en la lista antes de cada inserción para evitar IDs repetidos. Por eso, cargar n registros válidos distintos ahora requiere O(n²).

También se valida el encabezado, que cada fila tenga cinco campos y que el nombre no esté en blanco. Las filas incorrectas se omiten indicando su número de línea y la función devuelve la cantidad cargada o un código negativo si ocurre un problema de apertura, encabezado o lectura. `main.cpp` comprueba ese resultado antes de construir el índice.

### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta

En el avance 3 se implementó `guardarApostadores` en `ArchivoApostadores.cpp`.

La función utiliza `ofstream` para abrir el archivo de salida. Después obtiene los registros mediante `pasarAVector` y escribe el encabezado y los cinco campos de cada apostador, separados por comas.

Se conserva el orden actual de la lista. El índice por ID no se utiliza para guardar, porque tiene un orden independiente destinado a las búsquedas.

Después de cerrar el archivo se consulta `fail()` para detectar errores y el programa solo muestra el mensaje de guardado exitoso cuando la función devuelve `true`.

El guardado se ejecuta al seleccionar la opción 6, ya que esto nos permite conservar el resultado del ordenamiento entre ejecuciones. Por último, como nota importante: la escritura se realiza directamente sobre el archivo original.

# Casino Coin Management

## Clasificación de apostadores en el casino online para medición de riesgos

Casino Coin Management es una continuación de mi proyecto anterior de apuestas deportivas en C++. En esta nueva versión el objetivo principal ya no es solamente registrar apuestas, sino utilizar los datos generados por los apostadores para analizarlos y organizarlos.

Para este primer avance se guarda un resumen del historial de cada apostador, como el número de apuestas realizadas, el dinero total apostado y su ganancia o pérdida neta. Con estos datos el programa calcula el rendimiento de cada apostador y utiliza **MergeSort** para ordenarlos de mayor a menor.

Después se muestra una clasificación sencilla entre apostadores comunes y profesionales. Para este proyecto se considera profesional a un apostador que tenga al menos 10 apuestas registradas y un rendimiento positivo. Esta clasificación es una regla utilizada dentro de la simulación del proyecto.

---

## Descripción del avance 1

En este avance se desarrolló una primera versión funcional enfocada principalmente en algoritmos de ordenamiento.

Se creó la clase `Apostador` para representar los datos que se quieren analizar y la clase `Ordenamiento` para separar la implementación de MergeSort del resto del programa.

El programa contiene varios apostadores de prueba almacenados en un `vector`. Cada apostador tiene los siguientes datos:

- ID.
- Nombre.
- Número de apuestas realizadas.
- Total de dinero apostado.
- Ganancia o pérdida neta.

A partir de estos datos se calcula el rendimiento con la siguiente operación:

```text
rendimiento = (gananciaNeta / totalApostado) * 100
```

Después, MergeSort ordena el vector de apostadores utilizando el rendimiento como criterio. El orden se realiza de mayor a menor para que primero aparezcan los jugadores con mejor resultado histórico.

También se pueden mostrar solamente los apostadores comunes o solamente los apostadores profesionales.

Por el momento no se agregó una simulación de apuestas en tiempo real, ya que el objetivo principal de este avance es demostrar el uso correcto de un algoritmo de ordenamiento. Los datos de prueba se cargan directamente en `main.cpp`.

En avances posteriores se podría conectar esta parte con el sistema original de Casino Coin para obtener los datos directamente del historial de apuestas o desde un archivo.

---

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal dentro de la carpeta del proyecto:

```bash
g++ main.cpp Apostador.cpp Ordenamiento.cpp -std=c++11 -o primer_avance
```

En Windows utilizando MinGW también se puede generar un archivo ejecutable con extensión `.exe`:

```bash
g++ main.cpp Apostador.cpp Ordenamiento.cpp -std=c++11 -o primer_avance.exe
```

---

## Instrucciones para ejecutar el avance de proyecto

### macOS o Linux

```bash
./primer_avance
```

### Windows

```bash
.\primer_avance.exe
```

Al ejecutar el programa se muestra el siguiente menú:

```text
===== CASINO COIN - ANALISIS DE APOSTADORES =====

1. Ver los datos almacenados
2. Ordenar los apostadores por rendimiento
3. Mostrar solamente apostadores comunes
4. Mostrar solamente apostadores profesionales
5. Salir
```

El usuario selecciona una opción escribiendo un número del `1` al `5`.

---

## Descripción de las entradas del avance de proyecto

En este avance no se utiliza un archivo externo como entrada.

Los datos iniciales de los apostadores están declarados directamente en `main.cpp` para mantener el avance concentrado en el algoritmo de ordenamiento.

Cada apostador de prueba contiene:

- ID del apostador.
- Nombre.
- Número de apuestas realizadas.
- Total de dinero apostado.
- Ganancia o pérdida neta.

La entrada directa del usuario es la opción seleccionada dentro del menú.

El programa recibe un número entero del `1` al `5` para decidir qué información mostrar o si debe ejecutar MergeSort.

---

## Descripción de las salidas del avance de proyecto

El programa muestra los resultados directamente en consola.

Dependiendo de la opción seleccionada se pueden observar:

- Todos los apostadores almacenados.
- Los apostadores ordenados de mayor a menor rendimiento.
- Solamente los apostadores comunes.
- Solamente los apostadores profesionales.
- El rendimiento calculado de cada apostador.
- Los datos principales de cada jugador.

Un ejemplo del tipo de información mostrada es:

```text
ID: 1
Nombre: Luis
Apuestas realizadas: 18
Total apostado: $12500
Ganancia neta: $1650
Rendimiento: 13.20%
Clasificacion: Profesional
```

El resultado principal de este avance es poder ordenar los datos almacenados utilizando el rendimiento del apostador como criterio.

---

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa

Para ordenar los apostadores se utiliza **MergeSort**.

MergeSort funciona dividiendo el conjunto de datos en partes cada vez más pequeñas hasta llegar a elementos individuales. Después combina nuevamente estas partes mientras las acomoda de acuerdo con el criterio seleccionado.

En este proyecto el criterio utilizado es el rendimiento de cada apostador.

La recurrencia general de MergeSort se puede representar como:

```text
T(n) = 2T(n/2) + O(n)
```

El algoritmo divide el conjunto aproximadamente a la mitad en cada nivel, por lo que existen aproximadamente:

```text
log2(n)
```

niveles de división.

En cada nivel se recorren aproximadamente los `n` elementos durante el proceso de combinación. Por esta razón, la complejidad temporal final es:

```text
O(n log n)
```

### Complejidad temporal

| Caso | Complejidad |
|---|---|
| Mejor caso | O(n log n) |
| Caso promedio | O(n log n) |
| Peor caso | O(n log n) |

Una ventaja de MergeSort es que mantiene la misma complejidad temporal incluso en el peor caso.

### Complejidad espacial

La implementación necesita vectores auxiliares durante el proceso de combinación, por lo que la complejidad espacial es:

```text
O(n)
```

En este avance esta competencia se puede observar principalmente en los archivos `Ordenamiento.hpp` y `Ordenamiento.cpp`, donde se encuentra la implementación del algoritmo.

---

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente

Para este proyecto seleccioné **MergeSort** porque necesito ordenar una colección de apostadores utilizando su rendimiento como criterio.

El programa puede aumentar la cantidad de apostadores almacenados conforme se agreguen más datos. Por esta razón preferí utilizar un algoritmo con complejidad `O(n log n)` en lugar de algoritmos como Bubble Sort, Selection Sort o Insertion Sort, que pueden llegar a tener una complejidad de `O(n²)`.

Otra razón para seleccionar MergeSort es que su peor caso también tiene una complejidad de:

```text
O(n log n)
```

Esto permite tener un comportamiento más constante aunque aumente la cantidad de apostadores.

En el programa, MergeSort recibe el vector de apostadores y compara el rendimiento de los elementos para organizarlos de mayor a menor.

Por ejemplo, si existen los siguientes rendimientos:

```text
5.2%
-3.4%
13.7%
2.1%
```

después de utilizar MergeSort quedan ordenados de la siguiente manera:

```text
13.7%
5.2%
2.1%
-3.4%
```

La implementación del algoritmo se encuentra en la clase `Ordenamiento` y se utiliza desde `main.cpp` cuando el usuario selecciona la opción para ordenar a los apostadores.

De esta manera, el algoritmo de ordenamiento tiene una función directa dentro del problema del proyecto y no se utiliza solamente como una demostración aislada.

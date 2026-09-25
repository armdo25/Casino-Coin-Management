Proyecto: Casino Coin Management - Clasificación de apostadores en el casino online para medición de riesgos 
Casino Coin Management es una continuación de mi proyecto anterior de apuestas deportivas en C++. En esta nueva versión el objetivo principal ya no es solamente registrar apuestas, sino utilizar los datos generados por los apostadores para analizarlos y organizarlos. Para este primer avance se guarda un resumen del historial de cada apostador, como el número de apuestas realizadas, el dinero total apostado y su ganancia o pérdida neta.
Con estos datos el programa calcula el rendimiento de cada apostador y utiliza MergeSort para ordenarlos de mayor a menor. Después se muestra una clasificación sencilla entre apostadores comunes y profesionales. En este proyecto se considera profesional a un apostador que tenga al menos 10 apuestas registradas y rendimiento positivo.
Descripción del avance 1
En este avance se desarrolló una primera versión funcional enfocada en algoritmos de ordenamiento. Se creó la clase Apostador para representar los datos que se quieren analizar y la clase Ordenamiento para separar la implementación de MergeSort del resto del programa.
El programa contiene varios apostadores de prueba almacenados en un vector. Cada apostador tiene un ID, nombre, número de apuestas, total apostado y ganancia neta. A partir de estos datos se calcula el rendimiento con la siguiente operación:
rendimiento = (gananciaNeta / totalApostado) * 100
MergeSort ordena el vector de apostadores utilizando este rendimiento como criterio. El orden se realiza de mayor a menor para que primero aparezcan los jugadores con mejor resultado histórico. También se pueden mostrar solamente los apostadores comunes o solamente los profesionales.
Por el momento no se agregó una simulación de apuestas en tiempo real porque el objetivo principal de este avance es demostrar el uso correcto de un algoritmo de ordenamiento. Los datos de prueba se cargan directamente en main.cpp. En avances posteriores se puede conectar esta parte con el sistema original de Casino Coin para obtener los datos directamente del historial de apuestas o desde un archivo.
Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal dentro de la carpeta del proyecto:
g++ main.cpp Apostador.cpp Ordenamiento.cpp -std=c++11 -o primer_avance
En Windows con MinGW también se puede generar un ejecutable con extensión .exe:
g++ main.cpp Apostador.cpp Ordenamiento.cpp -std=c++11 -o primer_avance.exe
Instrucciones para ejecutar el avance de proyecto
En macOS o Linux:
./primer_avance
En Windows:
.\primer_avance.exe
Al ejecutar el programa se muestra un menú con las siguientes opciones:
1. Ver los datos almacenados.
2. Ordenar los apostadores por rendimiento.
3. Mostrar solamente apostadores comunes.
4. Mostrar solamente apostadores profesionales.
5. Salir del programa.
Descripción de las entradas del avance de proyecto
En este avance no se utiliza un archivo externo como entrada. Los datos iniciales de los apostadores están declarados directamente en main.cpp para mantener el avance concentrado en el algoritmo de ordenamiento.
La entrada del usuario es la opción seleccionada dentro del menú. El programa recibe un número entero del 1 al 5 para decidir qué información mostrar o si debe ejecutar MergeSort.
Cada apostador de prueba contiene los siguientes datos:
- ID del apostador.
- Nombre.
- Número de apuestas realizadas.
- Total de dinero apostado.
- Ganancia o pérdida neta.
Descripción de las salidas del avance de proyecto
El programa muestra en consola los datos de los apostadores y su rendimiento calculado. Cuando el usuario selecciona la opción de ordenamiento, los apostadores aparecen organizados de mayor a menor rendimiento.
También se muestra la categoría asignada a cada apostador. Para efectos de esta simulación, un apostador con al menos 10 apuestas y rendimiento mayor a 0% se clasifica como Profesional. Los demás se clasifican como Comun.
Desarrollo de competencias
SICT0301: Evalúa los componentes
Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El algoritmo utilizado es MergeSort. Si n representa la cantidad de apostadores almacenados, el algoritmo divide el vector en dos partes hasta llegar a elementos individuales y después combina las partes nuevamente en orden.
La división produce aproximadamente log n niveles. En cada nivel, la función merge() recorre en total los n elementos que pertenecen a las partes que se están combinando. Por esta razón, la complejidad temporal es:
- Mejor caso: O(n log n)
- Caso promedio: O(n log n)
- Peor caso: O(n log n)
También puede representarse con la relación T(n) = 2T(n/2) + O(n), ya que se resuelven dos mitades y luego se realiza la mezcla de los elementos.
La complejidad espacial es O(n) porque durante la mezcla se crean vectores auxiliares para guardar temporalmente las dos partes que se están comparando. La profundidad de las llamadas recursivas es O(log n), pero la memoria auxiliar dominante sigue siendo O(n).
En esta implementación MergeSort es estable, porque cuando dos apostadores tienen el mismo rendimiento se toma primero el elemento de la parte izquierda usando >=, conservando su orden relativo original.
El desarrollo de esta competencia se puede observar principalmente en Ordenamiento.cpp, dentro de los métodos mergeSort() y merge().
SICT0302: Toma decisiones
Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Se eligió MergeSort porque el proyecto necesita ordenar una lista de apostadores y se busca tener un comportamiento consistente aunque aumente la cantidad de datos. A diferencia de algoritmos sencillos como Bubble Sort, Selection Sort o Insertion Sort, MergeSort mantiene una complejidad de O(n log n) incluso en el peor caso.
También se consideró QuickSort porque normalmente tiene un buen rendimiento, pero su peor caso puede llegar a O(n²). Para este avance preferí MergeSort porque hace más sencillo justificar que el tiempo de ejecución del ordenamiento se mantiene en O(n log n) en los tres casos principales.
El criterio utilizado para ordenar es el rendimiento porcentual de cada apostador. El método ordenarPorRendimiento() recibe el vector completo y lo reorganiza de mayor a menor sin utilizar std::sort, ya que la intención del avance es implementar directamente el algoritmo de ordenamiento estudiado en clase.
El desarrollo de esta competencia se puede observar en Ordenamiento.cpp y en la opción 2 del menú de main.cpp, donde se ejecuta el algoritmo y se muestran los resultados ya organizados.

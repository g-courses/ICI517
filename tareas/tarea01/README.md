# Medición del tiempo de ejecución (timing) de un algoritmo

El objetivo de la tarea es introducir el uso de la herramienta [gnuplot](http://www.gnuplot.info) para realizar los gráficos de tiempos ejecución, acelaración y eficiencia. Para esto, se utilizarán datos ficticios para generar estos gráficos.

## Plazo

Miércoles 20 de Abril, 18:00 horas.

## Antecedentes

Para caracterizar el comportamiento de un programa, se hacen una serie de experimentos cuyo diseño es el siguiente:

```
Sea T={1,2,4,8} el número de threads a utilizar.
Sea S={10,20,30,40,50,60,70,80,90} el tamaño del problema en MB.

Para cada T :
	Para cada S :
		Ejecute el programa con T threads y con tamaño de problema S.
		Mida el tiempo de ejecución.
		Mida la cantidad de memoria utilizada.
		Agregue estos datos a un archivo con nombre ```timeExec-Tth.txt```
	Fin Para cada S
Fin Para cada T	
```

En el directorio ```code/experiments-data``` están los archivos de texto generados por los experimentos. Cada archivo contiene registros con la siguiente estructura:

```
size_problem:threads_used:t_ejec_1th:t_ejec_4th:memory_used
```

donde:
* ```size_problem``` : Tamaño en MB de la prueba.
* ```threads_used``` : Threads utilizados en el prueba.
* ```t_ejec_1th``` : Tiempo de ejecución base (1 thread).
* ```t_ejec_Tth``` : Tiempo de ejecución para T threads.
* ```memory_used```: Cantidad de memoria utilizada en la prueba (KB)

## Descripción del trabajo a realizar

Usted debe implementar un script en GnuPlot que sea capaz de generar los gráficos que se encuentran en el directorio ```graph_target```:

![](https://github.com/g-courses/ICI517/blob/main/tareas/tarea01/graph-target/01-texec.png)

![](https://github.com/g-courses/ICI517/blob/main/tareas/tarea01/graph-target/02-speedup.png)

![](https://github.com/g-courses/ICI517/blob/main/tareas/tarea01/graph-target/03-eficiencia.png)

Debe utilizar como base el script que se encuentra en ```code/comparacion.plt```. Además, En el directorio [graphs-example](https://github.com/g-courses/ICI517/edit/main/tareas/tarea01/graph-examples) se encuentran ejemplos de uso de GnuPlot.

El script realizado se deberá subir al Aula Virtual. El nombre del script deberá ser el siguiente: ```Apellido1-Apellido2-Nombre.plt```. No se corregirán scripts con otro nombre.
 
## Forma de corregir

Cada script se ejecutará en consola, en el directorio ```code```, donde se verificará la creación de los tres gráficos solicitados. Ejemplo:

```
$ cd code
$ ./flores-delcampo-zacarias.plt
[...] se omiten warnings
$ ls -l 
-rw-r--r--@ 1 user  staff  17163 Apr  7 22:25 01-texec.png
-rw-r--r--@ 1 user  staff   7505 Apr  7 22:25 02-speedup.png
-rw-r--r--@ 1 user  staff   8924 Apr  7 22:25 03-eficiencia.png
-rwxr--r--@ 1 user  staff   2273 Apr  7 22:25 comparacion.plt
drwxr-xr-x@ 7 user  staff    224 Apr  7 21:43 experiments-data
```

Cada gráfico después de revisa en forma individual para evaluar su cercanía al gráfico solicitado.


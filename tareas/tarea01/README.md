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

Debe utilizar como base el script que se encuentra en ```code/comparacion.plt```. Además, En el directorio [code/graphs-example](https://github.com/g-courses/ICI517/edit/main/tareas/tarea01/graph-examples) se encuentran ejemplos de uso de GnuPlot.
 
 

4. Usted debe preparar un informe del trabajo realizado, utilizando la plantilla entregada ```plantilla-informe.dotx```. El código de su trabajo deberá ser copiado en XXXXX. El informe deberá subirlo al Aula Virtual, y el nombre del archivo debera ser: ```Apellido1-Apellido2-Nombre.pdf```.


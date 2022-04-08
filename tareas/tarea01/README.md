# Medición del tiempo de ejecución (timing) de un algoritmo

El objetivo de la tarea es introducir el uso de la herramienta [gnuplot](http://www.gnuplot.info) para realizar los gráficos de tiempos ejecución, acelaración y eficiencia. Para esto, se utilizarán datos ficticios para generar estos gráficos.

## Plazo

Viernes 23 de Abril.

## Descripción del trabajo a realizar

En el directorio ```experiments-data``` 
> a[0:nx-1] = a[0:nx-1]*b[0:nx-1]+c[0:nx-1]

La operación la repite **nt** veces.

El trabajo de realizar se dividirá principalmente en las siguientes etapas.

1. Determinar la complejidad del algoritmo que está implementado en el código.
2. Modificar el código para que al terminar, muestre las siguientes métricas
> - Tiempo de ejecución del algoritmo (T<sub>total</sub>).
> - Tiempo de ejecución de una iteración del algoritmo (T<sub>iter</sub>).
> - Tiempo de ejecución del cómputo de un elemento del algoritmo (T<sub>elem</sub>).
> Todos los tiempos deben estar en las mismas unidades (segundos (s), milisegundos (ms)) y todos los resultados presentados deben ir acompañados por sus respecticas unidades.

3. Realizar experimentos que permitan caracterizar el tiempo de ejecución en función del tamaño del problema y la cantidad de iteraciones. Los resultados de estos experimentos se deben resumir en un gráfico, en donde la variable de salida (eje vertical) es el tiempo de ejecución observado. La variable de entrada debe ser la cantidad de iteraciones o el tamaño del problema. Finalmente, la tercera variable queda como parámetro. En la siguiente figura se muestra un posible gráfico. 

![](https://github.com/UV-ramos/ICI517-tarea01/blob/main/code/graph-example/example.png?raw=true)

La variable de entrada en este caso en la cantidad de iteraciones (**nt**) y la variable parámetrica es el tamaño del problema (**nx**). Se realizaron experimentos con nt={10·10<sup>3</sup>, ..., 50·10<sup>3</sup>} y por cada uno se hizo variar el tamaño del problema con nx={15·10<sup>3</sup>, 30·10<sup>3</sup>, 45·10<sup>3</sup>, 60·10<sup>3</sup>}. En el directorio [code/graph-example](https://github.com/UV-ramos/ICI517-tarea01/tree/main/code/graph-example) está el código que permite obtener este gráfico con GnuPlot.

4. Usted debe preparar un informe del trabajo realizado, utilizando la plantilla entregada ```plantilla-informe.dotx```. El código de su trabajo deberá ser copiado en el directorio ```/projects/$USER/tarea01``` para su revisión. La estructura de este directorio debe ser:

```
/projects/$USER/
	+ tarea01/
		+ code/
			- Makefile
			+ src/
		- README.txt	
```

El archivo README.txt deberá contener una descripción de los directorios y de su contenido. El directorio ```src``` debe tener la misma estructura del que se encuentra en este repositorio. Recuerde que su código debe ser compilado con el comando ```make```. El informe deberá subirlo al Aula Virtual, y el nombre del archivo debera ser: ```Apellido1-Apellido2-Nombre.pdf```.


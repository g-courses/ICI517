# Medición del tiempo de ejecución (timing) de un algoritmo

El objetivo de la tarea es introducir el uso de la herramienta [gnuplot](http://www.gnuplot.info) para realizar los gráficos de tiempos ejecución, acelaración y eficiencia. Para esto, se utilizarán datos ficticios para generar estos gráficos.

## Plazo

Miércoles 20 de Abril, 18:00 horas.

## Descripción del trabajo a realizar

En el directorio ```experiments-data``` hay archivos de texto con nombre ```timeExec-Nth.txt```, donde N={1,2,4,8} indica la cantidad de threads utilizados en dicho experimento.

En el directorio [code/graph-example](https://github.com/UV-ramos/ICI517-tarea01/tree/main/code/graph-example) está el código que permite obtener este gráfico con GnuPlot.
 
 

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


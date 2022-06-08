# Programación paralela con OpenMP

El objetivo de la tarea evaluar cómo el uso de paralelización en memoria compartida puede acelarar el tiempo de ejecución de un algoritmo. En particular, se implementarán tres algoritmos de procesamiento de imágenes en su versión secuencial y paralela para evaluar el desempeño según la cantidad de procesadores lógicos utilizados.

## Plazo

Viernes 8 de Julio, 18:00. Ver condiciones de entrega en la sección **Entregables**.

## Antecedentes

### Formato PGM

En esta tarea, se utilizará imágenes del tipo Portable GrayMap ([PGM](https://en.wikipedia.org/wiki/Netpbm_format)), principalmente porque el algoritmo para leer y crear este tipo de imágenes es sencillo. Las imágenes a utilizar se encuentran disponible en [este directorio](https://github.com/g-courses/ICI517/tree/main/tareas/tarea04/base/data). Si se quiere utilizar otras imágenes, debe convertir una imagen (jpg, png) con el comando ```convert``` (disponible en Linux con el software ImageMagick) de la siguiente forma:

```
convert -compress none inputImage.png outputImage.pgm
```

Cada imagen PGM consta de lo siguiente:

* Un "número mágico" para identificar el tipo de archivo. El número mágico de una imagen pgm son los dos caracteres "P2".
* Salto de línea.
* Un número que representa la cantidad de columnas que tiene la imagen.
* Espacio en blanco.
* Un número que representa la cantidad de filas que tiene la imagen.
* Salto de línea.
* El valor máximo de gris (maxGreyValue). Para los fines de la tarea, debe ser un número entero sin signo de 8 bits.
* Salto de línea.
* Un matriz con los datos de intensidad de gris de la imagen. Cada fila consta de números que representan la intensidad de gris de cada píxel, en orden de izquierda a derecha. Cada valor gris es un número de 0 a maxGreyValue, siendo 0 negro y maxGreyValue blanco.

Ejemplo de imagen PGM ([fuente](http://netpbm.sourceforge.net/doc/pgm.html))

```
P2
24 7
15
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  3  3  3  3  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
0  3  3  3  0  0  0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
0  3  0  0  0  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

![](https://github.com/g-courses/ICI517/tree/main/tareas/tarea04/base/content/feep.jpg)


En el directorio ```base/``` están los archivos que debe utilizar para iniciar su tarea. El lenguaje a utilizar es C++17. El contenido de este directorio es:

* ```Makefile``` : Archivo para generar el ejecutable. Debe modificarlo según las indicaciones en el interior de él.
* ```include/``` : Bibliotecas no estándar utilizadas..
* ```main.cc``` : Archivo fuente principal que debe modificar. 
* ```MultMatrix.cc``` : Archivo fuente de implementación del objeto MultMatrix. 
* ```MultMatrix.hh``` : Archivo fuente de declaración del objeto MultMatrix. 
* ```run_experiments.sh``` : Script BASH para realizar los experimentos.
* ```make_graphs.plt``` : Script GnuPLot para generar los gráficos de desempeño y comparación.

Estos archivos se deben copiar en un directorio denominado ```tarea2-Apellido1-Apellido2-Nombre/```, el que debe ser entregado en formato ```tar.gz``` según las indicaciones de la sección **Entregables**.


## Descripción del trabajo a realizar

1) Implementar el método ijk y kij. Esto se realizará a través de un objeto denominado MultMatrix que tiene por lo menos los siguientes métodos públicos:

* ```MultMatrix()```: Constructor vacío.
* ```DOijk(const Matrix& A, const Matrix& B, Matrix& C)```: Multiplica A y B con el algoritmo ijk y almacena el resultado en la matriz C.
* ```DOkij(const Matrix& A, const Matrix& B, Matrix& C)```: Multiplica A y B con el algoritmo kij y almacena el resultado en la matriz C.

2) Debe ejecutar por lo menos 30 experimentos por cada tamaño de matriz. Si S es el conjunto de tamaños de matriz a probar, S podría ser S={10x10, 50x50, 100x100, 500x500, 1000x1000, 5000x5000, 10000x10000, ...}. Los tamaños utilizados y su cantidad lo establecerá cada estudiante, debiendo justificar su elección. Deberá calcular promedio y desviación estándar de los tiempos de ejecución de cada algoritmo por cada tamaño de matrix y mostrarlos en un gráfico.


## Entregables

Deberá entregar un informe de su trabajo en formato PDF. Debe utilizar la plantilla entregada. El nombre del documento del informe deberá ser el siguiente: ```tarea4-Apellido1-Apellido2-Nombre.pdf```. **Aviso**: Al igual que las anteriores, esta tarea se entregará por correo. El título del correo **debe** ser : *```[ICI517-PAD]Tarea#4-Apellido1-Apellido2-Nombre```*. Sólo se recepcionarán correos que cumplan con este requisito. Debe adjuntar el informe y un archivo ```tar.gz``` que contenga el directorio de trabajo con sus respectivos archivos. El archivo ```tar.gz``` debe ser creado **después** de ejecutar ```make distclean``` en el directorio respectivo. 

Recuerde que el directorio enviardo debe incluir el script BASH que utilizó para realizar los experimentos, el que se debe llamar ```run_experiments```. La forma de uso de ese script es:

```./run_experiments --matrix <ruta_al_archivo_de_datos> --repeticiones <nro>```

 
## Forma de corregir

Cada script se ejecutará en consola, en el servidor de la asignatura, en el directorio ```code```, donde se verificará el funcionamiento de su programa y la validez de los datos utlizados en su informe. Ejemplo:

```
$ cd entregas
$ tar xf tarea2-Flores-Delcampo-Zacarias.tar
$ cd tarea2-Apellido1-Apellido2-Nombre/
-rw-r--r--@ 1 user  staff   758 Apr 26 00:37 Makefile
-rw-r--r--@ 1 user  staff   473 Apr 26 00:18 MultMatrix.cc
-rw-r--r--@ 1 user  staff   347 Apr 26 00:14 MultMatrix.hh
drwxr-xr-x@ 6 user  staff   192 Apr 26 00:30 include
-rw-r--r--@ 1 user  staff  1416 Apr 26 00:35 main.cc
-rwxr-xr-x@ 1 user  staff  1416 Apr 26 00:35 run_experiments.sh
$ make clean && make
$ ./mult --A <ruta_al_archivo_de_datos>
rowsxcols:time_ijk:time_kij #<-- nros dependen de la ejecución
$ ./run_experiments --matrix <ruta_al_archivo_de_datos> --repeticiones <nro>
rowsxcols:time_ijk:time_kij #<-- nros dependen de la ejecución
rowsxcols:time_ijk:time_kij #<-- nros dependen de la ejecución
rowsxcols:time_ijk:time_kij #<-- nros dependen de la ejecución
...
rowsxcols:time_ijk:time_kij #<-- nros dependen de la ejecución
$

```



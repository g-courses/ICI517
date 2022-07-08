# Programación paralela con OpenMP

El objetivo de la tarea evaluar cómo el uso de paralelización en memoria compartida puede acelerar el tiempo de ejecución de un algoritmo. En particular, se implementarán tres algoritmos de procesamiento de imágenes en su versión secuencial y paralela para evaluar el desempeño según la cantidad de procesadores lógicos utilizados.

## Plazo

~~Viernes 8 de Julio, 18:00~~. Viernes 22 de Julio, 18:00. Ver condiciones de entrega en la sección **Entregables**.

## Antecedentes

### Formato PGM

En esta tarea, se utilizará imágenes del tipo Portable GrayMap ([PGM](https://en.wikipedia.org/wiki/Netpbm_format)), principalmente porque el algoritmo para leer y crear este tipo de imágenes es sencillo. Las imágenes a utilizar se encuentran disponible en [este directorio](https://github.com/g-courses/ICI517/tree/main/tareas/tarea04/base/data). En el servidor, están sin comprimir en el directorio ```/opt/tareas/tarea04/base/data```. Si se quiere utilizar otras imágenes, debe convertir una imagen (jpg, png) con el comando ```convert``` (disponible en Linux con el software ImageMagick) de la siguiente forma:

```
convert -compress none inputImage.png outputImage.pgm
```

**Observación**: La mayoría de las herramientas de conversión en línea utilizan datos binarios para los valores de los pixeles, por lo que no sirven para esta tarea.

Cada imagen PGM consta de lo siguiente:

* Un "número mágico", consistente en los primeros 16 bits, para identificar el tipo de archivo. El número mágico de una imagen pgm son dos caracteres ```P2```.
* Salto de línea.
* Un número que representa la cantidad de columnas que tiene la imagen.
* Espacio en blanco.
* Un número que representa la cantidad de filas que tiene la imagen.
* Salto de línea.
* El valor máximo de gris (```maxGreyValue```). Para los fines de la tarea, debe ser un número entero sin signo de 8 bits, por lo que ```0≤maxGreyValue≤255```.
* Salto de línea.
* Un matriz con los datos de intensidad de gris de la imagen. Cada fila consta de números que representan la intensidad de gris de cada píxel, en orden de izquierda a derecha. Cada valor gris es un número de 0 a ```maxGreyValue```, siendo 0 negro y ```maxGreyValue``` blanco.

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

![](https://github.com/g-courses/ICI517/blob/main/tareas/tarea04/content/feep.png?raw=true)


### Descripción de los algoritmos de procesamiento de imágenes a utilizar

**(1) Invertir escala de grises de la imagen**

Debido a que según el formato PGM, el color negro = 0 y el  blanco = 255, para invertir la escala de grises de la imagen, se debe realizar el siguiente mapeo por cada píxel de la imagen:

```
0 → 255 
1 → 254 
2 → 253
...
254 → 1 
255 → 0
```

![](https://github.com/g-courses/ICI517/blob/main/tareas/tarea04/content/inverted.png?raw=true)

**(2) Pixelar**

Una forma de pixelar una imagen es hacer sub-matrices **no superpuestas** de tamaño ```n x n```. Estas sub-matrices se denominan *ventanas*. Para pixelar la imagen, cada pixel de esta ventana se debe sobreescribir con el valor promedio de todos los píxeles de esa ventana. Por ejemplo, si la siguiente imagen se pixela con una ventana de 4x4:

```
11 12 13 14 15 16 17 18
21 22 23 24 25 26 27 28
31 32 33 34 35 36 37 38
41 42 43 44 45 46 47 48
51 52 53 54 55 56 57 58
61 62 63 64 65 66 67 68
71 72 73 74 75 76 77 78
81 82 83 84 85 86 87 88
```

se transforma en:

```
28 28 28 28 32 32 32 32
28 28 28 28 32 32 32 32
28 28 28 28 32 32 32 32
28 28 28 28 32 32 32 32
68 68 68 68 72 72 72 72
68 68 68 68 72 72 72 72
68 68 68 68 72 72 72 72
68 68 68 68 72 72 72 72
```
, donde 28 es el promedio redondeado de la ventana de 4x4 superior izquierda. Para esta tarea, se utilizarán ventanas de la forma $2^k \times 2^k$, con $k \in${$1, 2, \dots$}

![](https://github.com/g-courses/ICI517/blob/main/tareas/tarea04/content/pixelated.png?raw=true)

**(3) Detectar bordes horizontales**

Para detectar los bordes, se utiliza una técnica de procesamiento de imágenes que consiste en utlizar una **ventana deslizante** correspodiente a la vecindad de Moore de un píxel determinado $p_{i,j}$.


$$p_{i-1,j-1}~~~~p_{i-1,j}~~~p_{i-1,j+1}$$

$$p_{i,j-1}~~~~p_{i,j}~~~p_{i,j+1}$$

$$p_{i+1,j-1}~~~~p_{i+1,j}~~~p_{i+1,j+1}$$

El valor del pixel (i,j) queda determinado como $p_{i,j} = (p_{i+1,j-1} + 2\cdot p_{i+1,j} + p_{i+1,j+1}) - (p_{i-1,j-1} + 2 \cdot p_{i-1,j} + p_{i-1,j+1})$. Si $p_{i,j} < 0 \Rightarrow p_{i,j} = 0$. Si $p_{i,j} > 255 \Rightarrow p_{i,j} = 255$. 

![](https://github.com/g-courses/ICI517/blob/main/tareas/tarea04/content/horiz_edges.png?raw=true)

### Descripción de la estructura de directorios a utilizar

En el directorio ```base/``` están los archivos que debe utilizar para iniciar su tarea. El lenguaje a utilizar es C++17. El contenido de este directorio es:

* ```Makefile``` : Archivo para generar el ejecutable. Debe modificarlo según las indicaciones en el interior de él.
* ```include/``` : Bibliotecas no estándar utilizadas..
* ```main.cc``` : Archivo fuente principal que debe modificar. 
* ```PGM.cc``` : Archivo fuente de implementación de los métodos adicionales de la clase PGM. 
* ```PGM.hh``` : Archivo fuente de declaración e implementación de los métodos base de la clase PGM. Este clase es derivada de la clase Matrix, utilizada en tareas anteriores.
* ```run_experiments.sh``` : Script BASH para realizar los experimentos.

Estos archivos se deben copiar en un directorio denominado ```tarea4-Apellido1-Apellido2-Nombre/```, el que debe ser entregado en formato ```tar.gz``` según las indicaciones de la sección **Entregables**.


## Descripción del trabajo a realizar

1) Implementar los métodos secuenciales de procesamiento:

* void PGM::invert();
* void PGM::pixelate(uint32_t sizeWindow);
* void PGM::hEdges();

2) Implementar los métodos paralelos de procesamiento con OpenMP:

* void PGM::invertMP();
* void PGM::pixelateMP(uint32_t sizeWindow);
* void PGM::hEdgesMP();

3) Debe diseñar los experimentos que permitan medir el desempeño de métods paralelos, en base a métricas como SpeedUp y Eficiencia Paralela.


## Entregables

Deberá entregar un informe de su trabajo en formato PDF. Debe utilizar la plantilla entregada. El nombre del documento del informe deberá ser el siguiente: ```tarea4-Apellido1-Apellido2-Nombre.pdf```. Este informe deberá ser enviado por correo, cuyo título **debe** ser : *```[ICI517-PAD]Tarea#4-Apellido1-Apellido2-Nombre```*. Sólo se recepcionarán correos que cumplan con este requisito. El código de la tarea será entregado en el servidor. Una vez que haya terminado su trabajo, debe enviar su trabajo con el comando ```make submit```.
 
## Forma de corregir

Cada script se ejecutará en consola, en el servidor de la asignatura, en el directorio ```code```, donde se verificará el funcionamiento de su programa y la validez de los datos utlizados en su informe. Ejemplo:

```
$ cd entregas
$ tar xf tarea2-Flores-Delcampo-Zacarias.tar
$ cd tarea4-Apellido1-Apellido2-Nombre/
-rw-r--r--@ 1 user  staff   758 Apr 26 00:37 Makefile
-rw-r--r--@ 1 user  staff   473 Apr 26 00:18 PGM.cc
-rw-r--r--@ 1 user  staff   347 Apr 26 00:14 PGM.hh
drwxr-xr-x@ 6 user  staff   192 Apr 26 00:30 include
-rw-r--r--@ 1 user  staff  1416 Apr 26 00:35 main.cc
-rwxr-xr-x@ 1 user  staff  1416 Apr 26 00:35 run_experiments.sh
$ make clean && make
$ ./pgm -i <ruta_al_archivo_de_imagen> -t <nro de threads>
rowsxcols:threads:time_inv:time_pix:time_edges #<-- nros dependen de la ejecución
$ ./run_experiments --imagen <ruta_al_archivo_de_imagen> --repeticiones <nro>
.... #<-- nros dependen de la ejecución
$

```



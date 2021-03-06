# Impacto del uso de la memoria cache y la utilización de instrucciones SIMD en la multiplicación de matrices

El objetivo de la tarea evaluar cómo el uso de instrucciones SIMD pueden acelerar el tiempo de ejecución de un algoritmo. En particular, se utilizarán dos algoritmos clásicos de multiplicación de matrices. Se utilizarán conjuntos de matrices *cuadradas* de números en precisión simple de distinto tamaño para evaluar los tiempo de ejecución. Se deberá analizar la aceleración que se puede obtener en los siguientes casos:

1) Comparando el algoritmo clásico ```ijk```, versus el mismo algoritmo ```ijk``` mejorado mediante el uso de instrucciones SIMD.
2) Comparando el algoritmo mejorado mediante el uso de la memora cache  ```kij```, versus  el mismo algoritmo ```kij``` mejorado mediante el uso de instrucciones SIMD.

## Plazo

~~Miércoles 25 de Mayo, 18:00 horas~~. ~~Viernes 3 de Junio, 18:00 horas~~. ~~Viernes 24 de Junio, 18:00~~. Viernes 15 de Julio, 18:00Ver condiciones de entrega en la sección **Entregables**.

## Antecedentes

Para multiplicar matrices existen varios métodos. Los que se evaluarán en esta tarea son dos:  1) método ```ijk``` y 2) método ```kij```. Ambos métodos ya fueron implementados en la tarea 2, por lo deberá utilizar esta tarea como base y agregar los métodos correspodientes.

En el directorio ```base/``` están los archivos que debe utilizar para iniciar su tarea. El lenguaje a utilizar es C++17. El contenido de este directorio es:

* ```Makefile``` : Archivo para generar el ejecutable. Debe modificarlo según las indicaciones en el interior de él.
* ```include/``` : Bibliotecas no estándar utilizadas..
* ```main.cc``` : Archivo fuente principal que debe modificar. 
* ```MultMatrix.cc``` : Archivo fuente de implementación del objeto MultMatrix. 
* ```MultMatrix.hh``` : Archivo fuente de declaración del objeto MultMatrix. 
* ```run_experiments.sh``` : Script BASH para realizar los experimentos.
* ```make_graphs.plt``` : Script GnuPLot para generar los gráficos de desempeño y comparación.

Estos archivos se deben copiar en un directorio denominado ```tarea3-Apellido1-Apellido2-Nombre/```, el que debe ser entregado en formato ```tar.gz``` según las indicaciones de la sección **Entregables**.


## Descripción del trabajo a realizar

1) Agregar los método ijkSIMD y kijSIMD al objeto  MultMatrix que tiene por lo menos los siguientes métodos públicos:

* ```MultMatrix()```: Constructor vacío.
* ```DOijk(const Matrix& A, const Matrix& B, Matrix& C)```: Multiplica A y B con el algoritmo ijk y almacena el resultado en la matriz C.
* ```DOkij(const Matrix& A, const Matrix& B, Matrix& C)```: Multiplica A y B con el algoritmo kij y almacena el resultado en la matriz C.
* ```DOijkSIMD(const Matrix& A, const Matrix& B, Matrix& C)```: Multiplica A y B con el algoritmo ijk vectorizado y almacena el resultado en la matriz C.
* ```DOkijSIMD(const Matrix& A, const Matrix& B, Matrix& C)```: Multiplica A y B con el algoritmo kij vectorizado y almacena el resultado en la matriz C.

2) Debe ejecutar por lo menos 30 experimentos por cada tamaño de matriz. Si S es el conjunto de tamaños de matriz a probar, S podría ser S={10x10, 50x50, 100x100, 500x500, 1000x1000, 5000x5000, 10000x10000, ...}. Los tamaños utilizados y su cantidad lo establecerá cada estudiante, debiendo justificar su elección. Deberá calcular promedio y desviación estándar de los tiempos de ejecución de cada algoritmo por cada tamaño de matrix y mostrarlos en un gráfico. El script BASH que debe crear para realizar los experimentos, que se debe llamar ```run_experiments```. La forma de uso de ese script es:

```./run_experiments --matrix <ruta_al_archivo_de_datos> --repeticiones <nro>```


## Entregables

Deberá entregar un informe de su trabajo en formato PDF. Debe utilizar la plantilla entregada. El nombre del documento del informe deberá ser el siguiente: ```tarea3-Apellido1-Apellido2-Nombre.pdf```. Este informe deberá ser enviado por correo, cuyo título **debe** ser : *```[ICI517-PAD]Tarea#3-Apellido1-Apellido2-Nombre```*. Sólo se recepcionarán correos que cumplan con este requisito. El código de la tarea será entregado en el servidor. Una vez que haya terminado su trabajo, debe enviar su trabajo con el comando ```make submit```. Recuerde que en Makefile, debe asignar ```WORK_NAME="tarea3"```.

 
## Forma de corregir

Cada script se ejecutará en consola, en el directorio ```code```, donde se verificará la creación de los tres gráficos solicitados. Ejemplo:

```
$ cd entregas
$ tar xf tarea3-Flores-Delcampo-Zacarias.tar
$ cd tarea3-Apellido1-Apellido2-Nombre/
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




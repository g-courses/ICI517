# Impacto del uso de la memoria cache en la multiplicación de matrices

El objetivo de la tarea evaluar cómo el uso de la memoria cache puede acelarar el tiempo de ejecución de un algoritmo. En particular, se utilizarán dos algoritmos clásicos de multiplicación de matrices. Se utilizarán conjuntos de matrices *cuadradas* de números en precisión simple de distinto tamaño para evaluar los tiempo de ejecución.

## Plazo

~~Miércoles 11 de Mayo, 18:00 horas~~. Viernes 20 de Mayo, 18:00. Ver condiciones de entrega en la sección **Entregables**.

## Antecedentes

Para multiplicar matrices existen varios métodos. Los que se evaluarán en esta tarea son dos. El anális teórico de la tasa de fallos de caché se realizó en clases.

### Método A (método ijk)

![](https://github.com/g-courses/ICI517/blob/main/tareas/tarea02/content/metodo01.png)


```
for(size_t i=0; i < filas(a); i++){
  for(size_t j=0; j < columnas(b); j++){
    for(size_t k=0; k < columnas(a); k++){
      c[i][j] += a[i][k] * b[k][j];
    }			
  }
}
```

### Método B (método kij)

![](https://github.com/g-courses/ICI517/blob/main/tareas/tarea02/content/metodo02.png)

```
for(size_t k=0; k < columnas(a); k++){
  for(size_t i=0; i < filas(a); i++){
    float r = a[i][k]
    for(size_t j=0; j < columnas(b); j++){
       c[i][j] += r * b[k][j];
    }			
  }
}
```

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

Deberá entregar un informe de su trabajo en formato PDF. Debe utilizar la plantilla entregada. El nombre del documento del informe deberá ser el siguiente: ```tarea2-Apellido1-Apellido2-Nombre.pdf```. **Aviso**: Al igual que la tarea 1, esta tarea se entregará por correo. El título del correo **debe** ser : *```[ICI517-PAD]Tarea#2-Apellido1-Apellido2-Nombre```*. Sólo se recepcionarán correos que cumplan con este requisito. Debe adjuntar el informe y un archivo ```tar.gz``` que contenga el directorio de trabajo con sus respectivos archivos. El archivo ```tar.gz``` debe ser creado **después** de ejecutar ```make distclean``` en el directorio respectivo. 

Además debe incluir el script BASH que utilizó para realizar los experimentos, que se debe llamar ```run_experiments```. La forma de uso de ese script es:

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



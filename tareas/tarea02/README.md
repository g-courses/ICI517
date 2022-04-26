# Impacto del uso de la memoria cache en la multiplicación de matrices

El objetivo de la tarea evaluar cómo el uso de la memoria cache puede acelarar el tiempo de ejecución de un algoritmo. En particular, se utilizarán dos algoritmos clásicos de multiplicación de matrices.

## Plazo

Miércoles 11 de Mayo, 18:00 horas. Ver condiciones de entrega en la sección **Entregables**.

## Antecedentes

Para multiplicar matrices existen varios métodos. Los que se evaluarán en esta tarea son dos. El anális teórico de la tasa de fallos de caché se realizó en clases.

### Método A (método ijk)

![](https://github.com/g-courses/ICI517/blob/main/tareas/tarea02/content/metodo01.png | width=100)

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

En el directorio ```skel/base``` están los archivos que debe utilizar para iniciar su tarea. El lenguaje a utilizar es C++17. El contenido de este directorio es:

* ```Makefile``` : Archivo para generar el ejecutable. Debe modificarlo según las indicaciones en el interior de él.
* ```include/``` : Bibliotecas no estándar utilizadas..
* ```mult.cc``` : Archivo fuente que debe modificar. 

Estos archivos se deben copiar en un directorio denominado ```tarea2-Apellido1-Apellido2-Nombre/```, el que debe ser entregado en formato ```tar.gz``` según las indicaciones de la sección **Entregables**.


## Descripción del trabajo a realizar


## Entregables

Deberá entregar un informe de su trabajo en formato PDF. Debe utilizar la plantilla entregada. El nombre del documento del informe deberá ser el siguiente: ```tarea2-Apellido1-Apellido2-Nombre.pdf```. **Aviso**: Al igual que la tarea 1, esta tarea se entregará por correo. El título del correo **debe** ser : *```[ICI517-PAD] Tarea #2 - Apellido1-Apellido2-Nombre```* y debe adjuntar el informe y un archivo ```tar.gz``` que contengo el directorio de trabajo con sus respectivos . Sólo se recepcionarán correos que cumplan con este requisito.
 
## Forma de corregir

Cada script se ejecutará en consola, en el directorio ```code```, donde se verificará la creación de los tres gráficos solicitados. Ejemplo:

```
$ cd entregas
$ tar xf tarea2-Flores-Delcampo-Zacarias.tar
$ cd tarea2-Apellido1-Apellido2-Nombre/
-rw-r--r--@ 1 user  staff  17163 Apr  7 22:25 Makefile
-rw-r--r--@ 1 user  staff   7505 Apr  7 22:25 mult.cc
-rw-r--r--@ 1 user  staff   8924 Apr  7 22:25 include/
```



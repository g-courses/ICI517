#!/usr/bin/env gnuplot

#---------------------------
#  Identificación del alumno
#
#  Nombre Completo:
#----------------------------

set encoding iso_8859_1
set term png size 800,600

set datafile separator ":"

FILE_1TH="experiments-data/timeExec-1th.txt"
FILE_2TH="experiments-data/timeExec-2th.txt"
FILE_4TH="experiments-data/timeExec-4th.txt"
FILE_8TH="experiments-data/timeExec-8th.txt"

#----------------------------
#	Tiempos de ejecución
#----------------------------

set title "Execution time Graph"
set ylabel "Time (s)"
set xlabel "Problem size (MB)"
set output "01-texec.png"


# Aca va el código para generar este gráfico. Debe comentar adecuadamente y colocar las referencias que utilizó 
# para resolver el problema.





#-------------
#	SpeedUP
#------------- 
	 
set title "SpeedUp Graph"
set ylabel "SpeedUp"
set xlabel "Problem size (MB)"
set output "02-speedup.png"	


# Aca va el código para generar este gráfico. Debe comentar adecuadamente y colocar las referencias que utilizó 
# para resolver el problema.



#----------------
#	Eficiencia
#----------------
	 
set title "Parallel Efficiency Graph"
set ylabel "Efficiency"
set xlabel "Problem size (MB)"
set output "03-eficiencia.png"	



# Aca va el código para generar este gráfico. Debe comentar adecuadamente y colocar las referencias que utilizó 
# para resolver el problema.
	 
	 
	 
	 
	 

#!/usr/bin/env gnuplot

set encoding iso_8859_1
set term png size 800,600
set output "example.png"

set title "Tiempo ejecución"
set ylabel "Tiempo ms"
set xlabel "Número de repeticiones"

set key outside title "Tamaño problema"
set grid

set style data histograms
#set style fill solid 1.00 border -1
set style fill pattern 0 border -1
#set ytics 0.5
#set mytics 5
set xtics offset 1.5

plot "data.txt"  using 2:xtic(1) title "nx_1=15·10^3" lt -1,\
                  '' using 3 title "nx_2=30·10^3" lt -1,\
                  '' using 4 title "nx_3=45·10^3" lt -1,\
                  '' using 5 title "nx_4=60·10^3" lt -1 fillstyle pattern 4


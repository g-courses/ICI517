#!/usr/bin/env gnuplot

set encoding iso_8859_1

sc=1
set term png enhanced size 640*sc,480*sc

set termoption dashed
set datafile separator ":"
 
set output "tject.png"

set ylabel "ms"
set xlabel "probleme size (2^N Byte)"
set key inside bottom right 

#set logscale y 2
#set logscale x 2
#set xrange [10:*]

set yrange [1:*]
set xtics 1
#set mytics 2
#set format y "%.0f"

set grid xtics ytics mxtics mytics

plot "datos.txt"  using 1:3 title ""  with linespoints lt -1 pointtype 11 pointsize 1.3 dt 1

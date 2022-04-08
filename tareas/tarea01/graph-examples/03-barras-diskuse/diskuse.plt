#!/usr/bin/env gnuplot

set terminal png truecolor
set output "diskuse.png"
set grid
set style data histograms
set style fill solid 1.00 border -1
plot "data.txt"  using 2:xtic(1) title "Oct-09 data growth(gb)",\
              '' using 3 title "Nov-09 data growth(gb)",\
              '' using 4 title "Dec-09 data growth(gb)"

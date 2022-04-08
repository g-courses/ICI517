#!/bin/bash


N=$(echo {10..30})

for size in $N; do
	./matrix -N $size
done
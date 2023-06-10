#!/bin/bash

# C programını derleme ve çalıştırma
gcc py.c -o cAndPy 
./cAndPy | while read line; 
do 
  python3 c.py $line; 
done 

# Tüm işlemleri bekle
wait

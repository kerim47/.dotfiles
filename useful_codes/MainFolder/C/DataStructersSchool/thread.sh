#!/bin/bash

# Fonksiyonlar
loop1() {
  for i in {1..10}; do
    echo "Loop 1: $i"
    sleep 1
  done
}

loop2() {
  for i in {A..J}; do
    echo "Loop 2: $i"
    sleep 2
  done
}

# İşlemleri arka planda başlat
loop1 | while read line; do echo "$line"; done &
loop2 | while read line; do echo "$line"; done &

# Tüm işlemleri bekle
wait


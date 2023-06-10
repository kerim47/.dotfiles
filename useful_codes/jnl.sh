#!/bin/bash

# Jupyter notebook'u arka planda çalıştır
jn > /dev/null 2>&1 &

# nvim'i arka planda çalıştır
# nvim --listen localhost:8888 /home/kerim/MainFolder/notebook.ju.py > /dev/null 2>&1 &
lvim --listen localhost:8888 /home/kerim/MainFolder/notebook.ju.py 2> /home/kerim/nvim.log

# Tüm işlemlerin tamamlanmasını bekle
wait


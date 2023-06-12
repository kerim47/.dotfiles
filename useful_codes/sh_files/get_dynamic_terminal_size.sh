# #!/bin/bash

# shopt -s checkwinsize
# echo $checkwinsize
# export PROMPT_COMMAND=update_bashrc
#!/bin/bash

# Fonksiyon: Terminal boyutunu kontrol eder ve ekrana yazdırır
function check_terminal_size() {
  size=$(stty size)
  echo "Terminal boyutu: $size"
}

# Başlangıçta terminal boyutunu yazdır
check_terminal_size

# Terminal boyutunun değişip değişmediğini kontrol etmek için bir önceki boyutu sakla
prev_size=$(stty size)

# Sonsuz döngü
while true; do
  # Şu anki terminal boyutunu kontrol et
  curr_size=$(stty size)
  # Eğer boyut değiştiyse
  if [ "$curr_size" != "$prev_size" ]; then
    # Yeni boyutu yazdır
    check_terminal_size
    # Önceki boyutu güncelle
    prev_size="$curr_size"
  fi
done


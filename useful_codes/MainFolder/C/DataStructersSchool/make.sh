#!/bin/bash

# Desteklenen programlama dilleri ve calistirma komutlari
declare -A lang_commands=(
  [py]="python3 %"
  [java]="java %"
  [c]="gcc % -o ${1%.*} && ./${1%.*} && rm ${1%.*}"
  [cpp]="g++ % -o ${1%.*} && ./${1%.*} && rm ${1%.*}"
  [ruby]="ruby %"
  [go]="go run %"
  [rust]="rustc % -o ${1%.*} && ./${1%.*} && rm ${1%.*}"
)

# Argumanlari diziye ekleme
args=("$@")

# Eger arguman yoksa hata mesaji verme ve cikis yap
if [[ "${#args[@]}" -eq 0 ]]; then
  echo "Hata: Program dosyasi adi belirtilmedi!"
  exit 1
fi

# Tüm argümanları dolaş ve her biri için programlama diline uygun komutu çalıştır
for file in "${args[@]}"; do
  # Son arguman dosya adı ve uzantisini al
  filename=$(basename -- "$file")
  extension="${filename##*.}"

  # Desteklenen programlama dilleri arasinda olup olmadigini kontrol et
  if [[ -n "${lang_commands[$extension]}" ]]; then
    # calistirma komutunu olustur ve calistirma
    command="${lang_commands[$extension]}"
    command="${command//%/$filename}"
    echo "calistirma komutu: $command"
    eval "$command"
  else
    echo "Hata: '$extension' uzantili dosya, desteklenmeyen bir programlama dili icin yazilmis."
    exit 1
  fi
done


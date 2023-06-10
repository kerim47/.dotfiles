#!/bin/bash

# Gelen inputu ascii koduna çevirir
ord() {
  printf "%d" "'$1"
}

# ascii tablosunu ekrana yazdırır
ascii_255()
{
  for i in {0..255}; do
    printf "%-3d- %s\n" $i "$(printf "\\$(printf '%03o' $i)")"
  done
}

# Aranan kelimenin pozisyonuna göre 1, -1 veya 0 döndürür
# 1: Kelime cümlede başlıyor
# -1: Kelime cümlede bitiyor
# 0: Kelime cümlede yok
check_word_position() {
    local kelime=$1
    local cumle=$2
    local ignore_case=${3:-1}

    if [[ $ignore_case -eq 1 ]]; then
        kelime=$(echo $kelime | tr '[:upper:]' '[:lower:]')
        cumle=$(echo $cumle | tr '[:upper:]' '[:lower:]')
    fi

    if [[ "$cumle" == "$kelime"* ]]; then
        echo 1
    elif [[ "$cumle" == *"$kelime"* ]]; then
        echo -1
    else
        echo 0
    fi
}


my_regex(){
  arr=()
  while true; do
      read -r -N1 input
      
      ascii_value=$(ord "$input")

      if (( ascii_value >= 32 && ascii_value <= 126 )); then
        clear
        arr+="$input"
        
        readarray -t sonuclar < <(history | awk '{$1=""; print substr($0,2)}' | grep -i "$arr" )

        for (( i=0; i<${#sonuclar[@]}; i++ ));do
          if [[ $(check_word_position "$arr" "${sonuclar[$i]}") == 1 ]]; then
            echo  "1"
          elif [[ $(check_word_position "$arr" "${sonuclar[$i]}") == -1 ]]; then
            echo "-1"
          else
            echo "0"
          fi
        done
        # echo -n "$arr"
      fi
      # history | grep -i "^ *[0-9]* *.*$arr.*$"
  done
}


deneme(){
gy_regex()

# Filtreleme i┼şlemini ger├ğekle┼ştir ve sonu├ğlar─▒ bir diziye at
# Dizi elemanlar─▒n─▒ ekrana yazd─▒r
for (( i=0; i<${#sonuclar[@]}; i++ ));
do
    echo "$i: ${sonuclar[$i]}"
done


# Kelime ve cümle örnekleri
kelime="Merhaba"
cumle="dsjkdjskjd Merhaba, nasılsın?"

# Fonksiyonu çağırmak ve sonucu ekrana yazdırmak
sonuc=$(check_word_position "$kelime" "$cumle")
echo "Sonuç: $sonuc"
}

my_regex

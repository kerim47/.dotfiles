#!/bin/bash


# Betik dosyasının tam yolunu alın
SCRIPT_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/$(basename "${BASH_SOURCE[0]}")"


# Kullanıcıdan arguman olarak kelime sayısı al
count=${2:-25}

# Geçmişi ayıklama ve kelime sayımını hesaplama
history_words=$(history | awk '{for(i=2;i<=NF;++i)print $i}' | tail -n 10)
popular_words=$(history | awk '{for(i=2;i<=NF;++i)print $i}' | sort | uniq -c | sort -rn | head -n $count | awk '{print $2}')
words=$(echo "$history_words"$'\n'"$popular_words" | sort -u)

# Dosyayı oluşturma veya temizleme
if [ ! -f ~/.bash_popular_history ]; then
    touch ~/.bash_popular_history
fi

# Popüler kelimeleri ve son girilen kelimeyi dosyaya yazma
for word in $words
do
    if ! grep -Fxq "$word" ~/.bash_popular_history; then
        echo "$word" >> ~/.bash_popular_history
    fi
done

while true
do
  source $SCRIPT_PATH
  sleep 1
done &

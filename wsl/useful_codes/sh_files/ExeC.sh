#!/bin/bash

function search_arg_index() {
    local args=("$@")
    local target="-o"
    for ((i=0; i<${#args[@]}; i++)); do
        if [[ ${args[$i]} == ${target} ]]; then
            if [[ $i -gt 0 ]] && [[ $((i+1)) -lt ${#args[@]} ]]; then
                echo "${args[$((i+1))]}"
                return
            fi
        fi
    done
    echo "-1"
}
function count_args() {
    local args=("$@")
    local count=0
    for ((i=0; i<${#args[@]}; i++)); do
        if [[ ${args[$i]} == "-o" ]]; then
            ((i++)) # "-o" argümanından sonraki argümanı atla
        else
            ((count++))
        fi
    done
    echo "$count"
}

args=("$@")

if [ "${#args[@]}" -eq 0 ]; then
  echo "Lütfen bir argüman girin"
  exit 1
fi

# Mevcut dizini kaydet
current_dir=$(pwd)
dir_path=""
files=""
first_path=""
echo ${args[@]}
for arg in "${args[@]}"
do
    if [ -d "$arg" ]; then
        echo "Hata: $arg bir dizindir, dosya yolunu belirtin."
        exit 1
    elif [ -f "$arg" ]; then
        dir_path=$(realpath $arg)
        files+=("${dir_path} ")
        # Dosya adı ve uzantısını ayır
        file_name="${dir_path##*/}"
        extension="${file_name##*.}"

        # Dosya adından uzantıyı sil
        program="${file_name%.$extension}"
        echo -e "Dosya ismi: ${file_name[@]}\nDosya Yolu: $dir_path\n"
    elif [ "$arg" = "-o" ]; then
        output_path=$(search_arg_index "${args[@]}")
        echo "Çıktı konumu: $output_path"
    fi
done
count=$(count_args "${args[@]}")
if [[ $count -gt "0" ]]; then
  index=$(search_arg_index "${args[@]}")

  if [[ $index != "-1" ]]; then
    echo "Hedef kelime dizinin $((index+1)). sırasında ve sonrasındaki argüman: $index"
    path=$(dirname $1)
    output="$path/$index"
    gcc ${files[@]} -o $output
    bash $output #&& rm $index
    cd $current_dir
  else
    gcc ${files[@]} -o $program && ./$program #&& rm $program
  fi
fi


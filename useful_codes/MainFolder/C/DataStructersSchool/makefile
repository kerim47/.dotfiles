CC=gcc
EXE_NAME=$(basename $(wildcard *.c))

.PHONY: all clean

all:
    @if [ -z "$(EXE_NAME)" ]; then \
        echo "No C file found!"; \
    elif [ "$(words $(EXE_NAME))" -gt "1" ]; then \
        echo "Multiple C files found!"; \
    else \
        $(CC) $(EXE_NAME).c -o $(EXE_NAME); \
        ./$(EXE_NAME); \
        rm $(EXE_NAME); \
    fi

clean:
    rm -f $(EXE_NAME)

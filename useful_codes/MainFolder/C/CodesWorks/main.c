#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

void delete_char() {
  struct termios old_term, new_term;
  tcgetattr(STDIN_FILENO, &old_term);
  new_term = old_term;
  new_term.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_term);

  char c;
  read(STDIN_FILENO, &c, 1);
  if (c == '\b' || c == 127) { // Backspace veya Delete tuşuna basıldı
    printf("\b \b"); // Karakteri silmek için bir adım sola, bir boşluk yazıp
                     // tekrar sola atla
  }

  tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
}

int main() {

  printf("Type 'quit' to quit.\n");
  while (1) {
    printf(">> ");
    char input[100];
    fgets(input, 100, stdin);
    if (strcmp(input, "quit\n") == 0) {
      break;
    }
    delete_char(); // Backspace veya Delete tuşuna basıldıysa karakteri sil
  }

  return 0;
}

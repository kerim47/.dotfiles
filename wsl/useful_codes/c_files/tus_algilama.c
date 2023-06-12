#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
/* Global değişken */
char g_char = '\0';

/* Terminal ayarları yapılandırma */
void set_terminal_mode() {
  struct termios tattr;

  /* Terminal ayarlarını al */
  tcgetattr(STDIN_FILENO, &tattr);

  /* ECHO modunu kapat ve karakter karakter okuma yap */
  tattr.c_lflag &= ~(ICANON | ECHO);

  /* Terminal ayarlarını uygula */
  tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
}

/* Terminal ayarlarını eski haline getirme */
void reset_terminal_mode() {
  struct termios tattr;

  /* Terminal ayarlarını al */
  tcgetattr(STDIN_FILENO, &tattr);

  /* ECHO modunu aç */
  tattr.c_lflag |= (ICANON | ECHO);

  /* Terminal ayarlarını uygula */
  tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
}

/* Vim moduna geçiş yap */
void set_vim_mode() { printf("Okumadi: %x", g_char); }
/* Kullanıcı tarafından girilen karakteri oku */
void read_character() {
  char c;

  /* Karakter karakter okuma yap */
  while (read(STDIN_FILENO, &c, 1) != 1)
    ;

  /* Okunan karakteri global değişkene ata */
  g_char = c;
}

/* Sonsuz döngüde karakter okuma */
void infinite_loop() {
  while (1) {
    printf("->");
    read_character();
  }
}

// Sinyal kesme fonksiyonu
void signal_handler(int signum) {
  printf("\nSinyal kesme fonksiyonu çağrıldı!\n");
  exit(0);
}

// Sinyal durdurma fonksiyonu
// CTRL+Z tuşuna basıldığında çağrılır
void signal_stop(int signum) {
  printf("\nSinyal durdurma fonksiyonu çağrıldı!\n");
  exit(1);
}

int main() {
  // register signal handlers
  // signal(SIGINT, signal_handler);
  // signal(SIGTSTP, signal_stop);
  char command[MAX_COMMAND_LENGTH];
  char *args[MAX_COMMAND_LENGTH];
  int arg_count;

  /* Terminal ayarlarını değiştir */
  set_terminal_mode();

  /* Sonsuz döngüde karakter okuma */
  infinite_loop();
  pid_t pid = fork();
  if (pid == 0) {
    // execvp(args[0], args);
    printf("%c\n", g_char);
    fprintf(stderr, "Komut ├ğal─▒┼şt─▒r─▒lamad─▒\n");
    exit(1);
  }

  /* Terminal ayarlarını eski haline getir */
  reset_terminal_mode();

  return 0;
}

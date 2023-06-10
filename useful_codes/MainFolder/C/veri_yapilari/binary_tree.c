#include <stdio.h>
#include <stdlib.h>
#define SID struct IkiliAgacDugumu

SID {
  SID *sol;
  SID *sag;
  int veri;
};

SID *kok = NULL;

SID *dugum_olustur(int veri) {
  SID *dugum = NULL;

  dugum = malloc(sizeof(SID));
  dugum->veri = veri;
  dugum->sol = NULL;
  dugum->sag = NULL;
  return dugum;
}

int main(int argc, char *argv[]) {

  kok = malloc(sizeof(SID));
  kok->sol = dugum_olustur(21);
  kok->sag = dugum_olustur(32);

  kok->sol->sol = dugum_olustur(52);
  kok->sol->sag = dugum_olustur(71);

  kok->sag->sag = dugum_olustur(6);
  kok->sag->sol = dugum_olustur(1);

  return 1;
}

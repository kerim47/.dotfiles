#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <stdio.h>
struct node
{
  int data;
  struct node* next;
};



void Goster();
void BasaEkleme(int);
void BastanSilme();
void SondanSilme();
void KonumaEkleme(int, int);
void KonumdanSilme(int, int);


#endif // !FUNCTIONS_H_

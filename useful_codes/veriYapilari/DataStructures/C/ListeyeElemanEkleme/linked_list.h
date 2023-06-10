#ifndef linked_list_h
#define linked_list_h

// Hafızadan yer acma
#define new_place place()

// Dugum tanımlamaları

typedef struct NODE Node; 
struct NODE{

	int value;
	struct NODE* next;
};

// Fonksiyon prototipleri
void add(Node*, int);
void print(Node*);
Node* place();
#endif

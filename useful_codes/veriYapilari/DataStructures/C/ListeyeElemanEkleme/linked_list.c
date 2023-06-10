#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Dugumdeki degerlerin yazdirilmasi
void print(Node* node)
{
	while(node != NULL)
	{
		printf("%d ->  ",node->value);
		node = node->next;
	}
	printf("NULL\n");
}
// Dugume degerlerin eklenmesi
void add(Node* n, int val)
{
    while(n->next != NULL) n = n->next; // Dugumun bir sonraki kutucugu bos mu?
    n->next = new_place; // Bos kutucaga yer acma
    n->next->value = val;// Kutucuktaki value degerine gelen val degiskneinin atanmasi
    n->next->next = NULL; // Son kutucugun NULL verilmesi
}
/* Dugumler icin yer acma fonksiyonu
*  Yer tasarrufundan saglamak amacıyla olusturulmustur
*/
Node* place()
{
	Node* node = (Node*)malloc(sizeof(Node));
	return node;
}


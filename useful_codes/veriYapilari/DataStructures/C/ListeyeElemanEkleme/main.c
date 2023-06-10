#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
// Gerekli kutuphanelerin tanimlanmasi

int main()
{
	// Dugum nesnesinden yer ayrildi. 
	Node* node = new_place; 
	node->value = 0; // Dugum nesnesinin ilk degiskenine deger atandi.
	node->next = NULL; // Dugum nesnesinin sonraki dugumune NULL degeri atandi.
	// NULL degerinin eklenmesi dugumun sonuna geldigini temsil ettiginden dolayı kullanılması daha uygundur.
	// Dugum' e sayilar ekleme
	int i;
	for(i = 1; i< 10; i++)
	{
		add(node, i * 10);
	}

	// Dugumdeki degerlerin yazdirilmasi
	print(node);


	return 1;
}

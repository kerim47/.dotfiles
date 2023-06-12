#include <stdio.h>
#include <stdlib.h>

// Dairesel bağlantılı liste için düğüm yapısı tanımlaması
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Dairesel bağlantılı liste için başlangıç düğümü
struct node *start = NULL;

// Verilen pozisyona eleman ekleme fonksiyonu
void insertAtPosition(int data, int position) {
    struct node *newNode, *temp;
    int i;
    
    // Yeni düğüm oluşturulması ve verinin atanması
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    
    // Listenin boş olup olmadığının kontrol
    if (start == NULL) {
        start = newNode;
        start->prev = start;
        start->next = start;
    }
    // Listenin boş olmadığında pozisyonun baş veya son olma durumunun kontrolü
    else if (position == 1) {
        newNode->prev = start->prev;
        newNode->next = start;
        start->prev->next = newNode;
        start->prev = newNode;
        start = newNode;
    }
    else {
        // Gezici düğümün başlangıçtan başlatılması
        temp = start;
        
        // Verilen pozisyona kadar döngü ile gezinilmesi
        for (i = 1; i < position-1 && temp->next != start; i++) {
            temp = temp->next;
        }
        
        // Pozisyonun son eleman olup olmadığının kontrolü
        if (temp->next == start) {
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = start;
            start->prev = newNode;
        }
        else {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
}

// Verilen pozisyondaki elemanı silme fonksiyonu
void deleteAtPosition(int position) {
    struct node *temp;
    int i;
    
    // Listenin boş olup olmadığının kontrolü
    if (start == NULL) {
        printf("Liste bos!\n");
    }
    // Listenin boş olmadığında pozisyonun baş veya son olma durumunun kontrolü
    else if (position == 1) {
        // Tek eleman varsa düğümün serbest bırakılması
        if (start->next == start) {
            free(start);
            start = NULL;
        }
        else {
            start->prev->next = start->next;
            start->next->prev = start->prev;
            temp = start;
            start = start->next;
            free(temp);
        }
    }
    else {
        // Gezici düğümün başlangıçtan başlatılması
        temp = start;
        
        // Verilen pozisyona kadar döngü ile gezinilmesi
        for (i = 1; i < position && temp->next != start; i++) {
            temp = temp->next;
        }
        
        // Verilen pozisyonun son eleman olup olmadığının kontrolü
        if (temp->next == start) {
          temp->prev->next = start;
          start->prev = temp->prev;
          free(temp);
        }
        else {
          temp->prev->next = temp->next;
          temp->next->prev = temp->prev;
          free(temp);
        }
    }
}

// Listenin başına eleman ekleme fonksiyonu
void insertAtBeginning(int data){
  struct node *newNode; 
  // Yeni düğüm oluşturulması ve verinin atanması
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;

  // Listenin boş olup olmadığının kontrolü
  if (start == NULL) {
      start = newNode;
      start->prev = start;
      start->next = start;
  }
  else {
      newNode->prev = start->prev;
      newNode->next = start;
      start->prev->next = newNode;
      start->prev = newNode;
      start = newNode;
  }
}

// Listenin başındaki elemanı silme fonksiyonu
void deleteAtBeginning() {
  struct node *temp;
  // Listenin boş olup olmadığının kontrolü
  if (start == NULL) {
      printf("Liste bos!\n");
  }
  // Tek eleman varsa düğümün serbest bırakılması
  else if (start->next == start) {
      free(start);
      start = NULL;
  }
  else {
      start->prev->next = start->next;
      start->next->prev = start->prev;
      temp = start;
      start = start->next;
      free(temp);
  }
}
void printList() {
    if(start == NULL) {
        printf("List is empty.");
    }
    else {
        struct node *ptr = start;
        do {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while(ptr != start);
    }
}

int main(int argc, char *argv[])
{
  int choice, data, position;
  while (1) {
    // Kullanıcıya seçeneklerin sunulması
    printf("\nMENU:\n");
    printf("1. Eleman ekleme\n");
    printf("2. Eleman silme\n");
    printf("3. Liste elemanlarini yazdirma\n");
    printf("4. Cikis\n");
    printf("Seciminiz: ");
    scanf("%d", &choice);
    
    switch(choice) {
        // Eleman ekleme işleminin gerçekleştirilmesi
        case 1:
            printf("Eklemek istediginiz elemani girin: ");
            scanf("%d", &data);
            printf("Hangi pozisyona eklemek istiyorsunuz: ");
            scanf("%d", &position);
            if (position == 1) {
                insertAtBeginning(data);
            }
            else {
                insertAtPosition(data, position);
            }
            break;
        // Eleman silme işleminin gerçekleştirilmesi
        case 2:
            printf("Silmek istediginiz elemanin pozisyonunu girin: ");
            scanf("%d", &position);
            if (position == 1) {
                deleteAtBeginning();
            }
            else {
                deleteAtPosition(position);
            }
            break;
        // Liste elemanlarının yazdırılması işleminin gerçekleştirilmesi
        case 3:
            printList();
            break;
        // Programdan çıkış yapılması
        case 4:
            exit(0);
        // Geçersiz seçenek durumunda hata mesajının yazdırılması
        default:
            printf("Gecersiz secenek!\n");
    }
  }

  return 1;
}

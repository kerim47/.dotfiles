#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;

// Konuma eleman ekleme fonksiyonu
void insertAtPos(int pos, int val) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL && pos != 1) {
        printf("Liste bos, ilk eleman konumuna ekleme yapilamaz.\n");
        return;
    }
    else if (pos == 1) { // Başa ekleme
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    else { // Diğer konumlara ekleme
        int count = 1;
        struct node* temp = head;
        while (count < pos-1 && temp != NULL) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            printf("Girilen konum listede yok.\n");
            return;
        }
        if (temp == tail) { // Son elemana ekleme
            tail = newNode;
        }
        else {
            newNode->next = temp->next;
            temp->next->prev = newNode;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }
    printf("%d konumuna %d degeri eklendi.\n", pos, val);
}

// Konumdan eleman silme fonksiyonu
void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("Liste bos, silme islemi yapilamaz.\n");
        return;
    }
    else if (pos == 1) { // Başa silme
        if (head == tail) {
            free(head);
            head = NULL;
            tail = NULL;
        }
        else {
            struct node* temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
    }
    else { // Diğer konumlardan silme
        int count = 1;
        struct node* temp = head;
        while (count < pos && temp != NULL) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            printf("Girilen konum listede yok.\n");
            return;
        }
        if (temp == tail) { // Son elemanı silme
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
    printf("%d konumundaki eleman silindi.\n", pos);
}

// Liste elemanlarını yazdırma fonksiyonu
void printList() {
    struct node* temp = head;
    printf("Liste elemanlari: ");
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
}

// Liste elemanlarını tersten yazdırma fonksiyonu
void printListReverse() {
    struct node* temp = tail;
    printf("Liste elemanlari (tersten): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}


int main() {

  insertAtPos(1, 5);
  insertAtPos(2, 10);
  insertAtPos(3, 15);
  insertAtPos(4, 20);
  printList();

  deleteAtPos(2);
  printList();

  deleteAtPos(1);
  printList();

  deleteAtPos(3);
  printList();

  deleteAtPos(2);
  printList();

  printListReverse();

  return 0;
}

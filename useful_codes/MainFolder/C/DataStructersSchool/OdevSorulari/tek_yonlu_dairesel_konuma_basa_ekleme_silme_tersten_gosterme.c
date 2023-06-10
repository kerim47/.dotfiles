#include <stdio.h>
#include <stdlib.h>

// düğüm yapısı
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

// başlangıç düğümü
Node *head = NULL;

// son düğüm
Node *tail = NULL;

// listenin boyutu
int size = 0;

// listenin başına veri ekleme
void insertAtBeginning(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    size++;
    printf("%d verisi listenin başına eklendi.\n", data);
}

// konuma veri ekleme
void insertAtPosition(int data, int position) {
    if (position < 1 || position > size + 1) {
        printf("Geçersiz konum!\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    Node *temp = head;
    int i = 1;

    while (i < position - 1) {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == NULL) {
        tail = newNode;
    }

    size++;
    printf("%d verisi %d. konuma eklendi.\n", data, position);
}

// konumdan veri silme
void deleteFromPosition(int position) {
    if (position < 1 || position > size) {
        printf("Geçersiz konum!\n");
        return;
    }

    Node *temp = head;

    if (position == 1) {
        head = head->next;
        tail->next = head;
    } else {
        int i = 1;

        while (i < position - 1) {
            temp = temp->next;
            i++;
        }

        Node *toBeDeleted = temp->next;

        temp->next = toBeDeleted->next;

        if (toBeDeleted == tail) {
            tail = temp;
        }

        free(toBeDeleted);
    }

    size--;
    printf("%d. konumdaki veri silindi.\n", position);
}

// listenin başındaki veriyi silme
void deleteFromBeginning() {
    Node *temp;

    if (head == NULL) {
        printf("Liste boş!\n");
        return;
    }

    temp = head;
    head = head->next;
    tail->next = head;

    printf("%d verisi listeden silindi.\n", temp->data);

    free(temp);

    size--;
}


// listenin içeriğini yazdırma
void display() {
    Node *temp = head;

    if (head == NULL) {
        printf("Liste boş!\n");
        return;
    }

    printf("Listedeki veriler: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
  // başa veri ekleme
  insertAtBeginning(5);
  insertAtBeginning(10);
  insertAtBeginning(15);
  
  // listenin içeriğini yazdırma
  display();

  // konuma veri ekleme
  insertAtPosition(20, 2);

  // listenin içeriğini yazdırma
  display();

  // konumdan veri silme
  deleteFromPosition(3);

  // listenin içeriğini yazdırma
  display();

  // listenin başındaki veriyi silme
  deleteFromBeginning();

  // listenin içeriğini yazdırma
  display();

  return 1;
}

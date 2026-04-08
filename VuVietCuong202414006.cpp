#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USB_SIZE (32LL * 1024 * 1024 * 1024)

typedef struct {
    char name[100];
    char path[200];
    long size;
    long time;
} File;

typedef struct Node {
    File data;
    struct Node* next;
} Node;

// Tao node
Node* createNode(File f) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = f;
    node->next = NULL;
    return node;
}

// Chen theo thoi gian
void insertSorted(Node** head, File f) {
    Node* newNode = createNode(f);

    if(*head==NULL || f.time<(*head)->data.time){
        newNode->next=*head;
        *head=newNode;
        return;
    }

    Node* temp = *head;
    while(temp->next && temp->next->data.time < f.time){
        temp = temp->next;
    }

    newNode->next=temp->next;
    temp->next=newNode;
}

// Tong dung luong
long long totalSize(Node* head) {
    long long sum=0;
    while(head){
        sum+=head->data.size;
        head=head->next;
    }
    return sum;
}

// File nho nhat
long minFileSize(Node* head) {
    if (!head) return 0;

    long min = head->data.size;
    while (head) {
        if (head->data.size < min)
            min = head->data.size;
        head = head->next;
    }
    return min;
}

// Kiem tra USB
void checkUSB(Node* head) {
    long long total = totalSize(head);

    if (total <= USB_SIZE) {
        printf("Co the copy toan bo file vao USB\n");
    } else {
        long min = minFileSize(head);
        if (min <= USB_SIZE) {
            printf("Chi co the copy tung file nho\n");
        } else {
            printf("Khong the copy file nao\n");
        }
    }
}

// In danh sách
void printList(Node* head) {
    while (head) {
        printf("%s - %ld bytes - time %ld\n",
               head->data.name,
               head->data.size,
               head->data.time);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    File f1 = {"file1.txt", "D:/", 1000, 3};
    File f2 = {"file2.txt", "D:/", 2000, 1};
    File f3 = {"file3.txt", "D:/", 500, 2};

    insertSorted(&head, f1);
    insertSorted(&head, f2);
    insertSorted(&head, f3);

    printList(head);

    checkUSB(head);

    return 0;
}

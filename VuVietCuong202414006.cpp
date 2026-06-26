#include <iostream>
#include <cstring>

using namespace std;

#define USB 34359738368LL   // 32GB

struct File {
    char name[100];
    char path[200];
    long size;
    long time;
};

struct Node {
    File data;
    Node *next;
};

// Tao node moi
Node* createNode(File x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}



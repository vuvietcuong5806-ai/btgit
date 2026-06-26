#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

Node* createCircle(int N) {
    Node *head = createNode(1);
    Node *p = head;

    for (int i = 2; i <= N; i++) {
        p->next = createNode(i);
        p = p->next;
    }

    p->next = head; 
    return head;
}


int josephus(int N,int M) {
    if (N==1) return 1;

    Node* p = createCircle(N);
    Node* prev = NULL;

    while (p->next != p) { 
        for (int i = 0; i < M; i++) {
            prev = p;
            p = p->next;
        }

        // loai ng b  
        cout << "Loai: " << p->data << endl;

        prev->next = p->next;
        delete p;

        p = prev->next; 
    }

    int nguoithang = p->data;
    delete p;
    return nguoithang;
}


int main() {
    int N, M;
    cout << "Nhap N: ";
    cin >> N;
    cout << "Nhap M: ";
    cin >> M;

    int winner = josephus(N, M);
    cout << "Nguoi chien thang: " << nguoithang << endl;

    return 0;
}

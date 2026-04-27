#include <iostream>
using namespace std;

// ===== NODE =====
struct Node {
    int data;
    Node* next;
};

// ===== TAO NODE =====
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// ===== TAO DSLK VONG =====
Node* createCircle(int N) {
    Node *head = createNode(1);
    Node *p = head;

    for (int i = 2; i <= N; i++) {
        p->next = createNode(i);
        p = p->next;
    }

    p->next = head; // n?i vòng
    return head;
}

// ===== JOSEPHUS =====
int josephus(int N, int M) {
    if (N == 1) return 1;

    Node* p = createCircle(N);
    Node* prev = NULL;

    while (p->next != p) { // còn hon 1 ngu?i
        // di chuy?n M bu?c
        for (int i = 0; i < M; i++) {
            prev = p;
            p = p->next;
        }

        // loai nguoi p
        cout << "Loai: " << p->data << endl;

        prev->next = p->next;
        delete p;

        p = prev->next; // sang ngu?i ti?p theo
    }

    int winner = p->data;
    delete p;
    return winner;
}

// ===== MAIN =====
int main() {
    int N, M;
    cout << "Nhap N: ";
    cin >> N;
    cout << "Nhap M: ";
    cin >> M;

    int winner = josephus(N, M);
    cout << "Nguoi chien thang: " << winner << endl;

    return 0;
}

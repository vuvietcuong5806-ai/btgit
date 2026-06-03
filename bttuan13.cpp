#include <iostream>
using namespace std;

struct Node {
    int date;
    Node* trai;
    Node* phai;
    Node(int ns) : date(ns), trai(nullptr), phai(nullptr) {}
};

Node* insert(Node* goc, int date) {
    if (goc == nullptr)
        return new Node(date);
    if (date < goc->date)
        goc->trai = insert(goc->trai, date);
    else if (date > goc->date)
        goc->phai = insert(goc->phai, date);
    return goc;
}

Node* search(Node* goc, int date){
	if(goc== nullptr|| goc->date == date) return goc;
	if( date < goc->date) return search(goc->trai, date);
	else
	return search(goc->phai, date);
} 

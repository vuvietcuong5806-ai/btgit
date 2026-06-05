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

int main(){
	int data[]={2001, 2002, 2006, 2007,2003, 2004,2005, 2001, 1999, 2004};
	int n=sizeof(data) / sizeof(data[0]);
	int datecantim;
	cin>>datecantim;
	Node* goc=nullptr;
	for(int i=0; i<n; i++) goc=insert(goc, data[i]);
	Node* Kq= search(goc, datecantim);
	if(Kq) cout<<"Da tim thay sinh vien co nam sinh: "<<Kq->date;
	else cout<<"Khong tim thay"<<endl;
	return 0;
} 

#include <iostream>
#include <string>
using namespace std;

// ===== STRUCT =====
struct Ngay {
    int ngay,thang,nam;
};

struct SinhVien {
    string maSV;
    string hoTen;
    int gioiTinh;
    Ngay ngaySinh;
    string diaChi;
    string lop;
    string khoa;
};

struct Node {
    SinhVien data;
    Node* next;
};

struct List {
    Node* first;
    Node* last;
};

// ===== KHOI TAO =====
void initList(List &l){
    l.first=l.last = NULL;
}

// ===== TAO NODE =====
Node* createNode(SinhVien sv){
    Node*p=new Node;
    p->data=sv;
    p->next=NULL;
    return p;
}

// ===== THEM CO SAP XEP =====
void insertSorted(List &l, SinhVien sv){
    Node*p=createNode(sv);

    if (l.first==NULL) {
        l.first=l.last=p;
        return;
    }

    if (sv.maSV<l.first->data.maSV){
        p->next=l.first;
        l.first=p;
        return;
    }

    Node* q=l.first;
    while(q->next != NULL && q->next->data.maSV < sv.maSV) {
        q=q->next;
    }

    p->next=q->next;
    q->next=p;

    if(p->next==NULL)l.last=p;
}

// ===== NHAP SV =====
void nhapSV(SinhVien&sv) {
    cout<<"Ma SV: ";
    cin>>sv.maSV;

    cin.ignore();
    cout<<"Ho ten: ";
    getline(cin, sv.hoTen);

    cout<< "Gioi tinh (0-Nu, 1-Nam): ";
    cin>> sv.gioiTinh;

    cout<< "Ngay sinh (d m y): ";
    cin>> sv.ngaySinh.ngay >> sv.ngaySinh.thang >> sv.ngaySinh.nam;

    cin.ignore();
    cout<< "Dia chi: ";
    getline(cin, sv.diaChi);

    cout<< "Lop: ";
    cin>> sv.lop;

    cout<< "Khoa: ";
    cin>> sv.khoa;
}

// ===== IN DS =====
void printList(List l) {
    Node* p = l.first;
    cout << "\n=== DANH SACH SINH VIEN ===\n";
    while (p != NULL) {
        cout << p->data.maSV << " | "
             << p->data.hoTen << " | "
             << p->data.ngaySinh.ngay << "/"
             << p->data.ngaySinh.thang << "/"
             << p->data.ngaySinh.nam << endl;
        p = p->next;
    }
}

// ===== SO SANH NGAY =====
bool sameDate(Ngay a, Ngay b) {
    return (a.ngay == b.ngay && a.thang == b.thang && a.nam == b.nam);
}

// ===== TIM SV TRUNG NGAY SINH =====
void findSameBirthday(List l) {
    bool found = false;

    for (Node* p = l.first; p != NULL; p = p->next) {
        for (Node* q = p->next; q != NULL; q = q->next) {
            if (sameDate(p->data.ngaySinh, q->data.ngaySinh)) {
                cout << "Trung ngay sinh: "
                     << p->data.hoTen << " va "
                     << q->data.hoTen << endl;
                found = true;
            }
        }
    }

    if (!found)
        cout << "Khong tim thay sinh vien cung ngay sinh\n";
}

// ===== XOA SV TRUNG NGAY SINH =====
void removeSameBirthday(List &l) {
    Node *p = l.first, *prev = NULL;

    while (p != NULL) {
        bool duplicate = false;

        for (Node* q = l.first; q != NULL; q = q->next) {
            if (q != p && sameDate(p->data.ngaySinh, q->data.ngaySinh)) {
                duplicate = true;
                break;
            }
        }

        if (duplicate) {
            Node* temp = p;

            if (prev == NULL) {
                l.first = p->next;
                p = l.first;
            } else {
                prev->next = p->next;
                p = p->next;
            }

            delete temp;
        } else {
            prev = p;
            p = p->next;
        }
    }
}

// ===== MAIN =====
int main() {
    List l;
    initList(l);

    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nNhap SV thu " << i + 1 << ":\n";
        SinhVien sv;
        nhapSV(sv);
        insertSorted(l, sv);
    }

    printList(l);

    cout << "\n--- Tim SV trung ngay sinh ---\n";
    findSameBirthday(l);

    cout << "\n--- Xoa SV trung ngay sinh ---\n";
    removeSameBirthday(l);

    printList(l);

    return 0;
}

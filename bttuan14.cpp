#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data=value;
        left=nullptr;
        right=nullptr;
    }
};

struct Tree {
    Node* root;

    Tree(){
        root=nullptr;
    }
};

void Insert_Recursive(Node*& current_node, int data) {
    if (current_node==nullptr) {
        current_node=new Node(data);
        return;
    }

    if (data<current_node->data) {
        if (current_node->left==nullptr) {
            current_node->left=new Node(data);
            return;
        }
        else{
            Insert_Recursive(current_node->left, data);
        }
    }
    else{
        if(current_node->right==nullptr) {
            current_node->right=new Node(data);
            return;
        }
        else{
            Insert_Recursive(current_node->right, data);
        }
    }
}

void Insert(Tree& t,int data) {
    Insert_Recursive(t.root,data);
}

int Get_Height(Node* current_node) {
    if (current_node== nullptr)
        return 0;

    int left_height=Get_Height(current_node->left);
    int right_height=Get_Height(current_node->right);

    return 1 + max(left_height, right_height);
}

int Calculate_Balance_Factor(Node* t) {
    int count_left = Get_Height(t->left);
    int count_right = Get_Height(t->right);

    return count_left - count_right;
}

Node* Right_Rotate(Node* y) {
    Node* x = y->left;
    Node* n = x->right;

    x->right = y;
    y->left = n;

    return x;
}

Node* Left_Rotate(Node* y) {
    Node* x = y->right;
    Node* n = x->left;

    x->left = y;
    y->right = n;

    return x;
}

Node* Balance_Tree(Node*& current_node) {
    int balance = Calculate_Balance_Factor(current_node);

    if (abs(balance) <= 1) {
        return current_node;
    }
    else if (balance < -1) {
        int right_balance =
            Calculate_Balance_Factor(current_node->right);

        if (right_balance <= 0) {
            return Left_Rotate(current_node);
        }
        else {
            current_node->right =
                Right_Rotate(current_node->right);
            return Left_Rotate(current_node);
        }
    }
    else {
        int left_balance =
            Calculate_Balance_Factor(current_node->left);

        if (left_balance > 0) {
            return Right_Rotate(current_node);
        }
        else {
            current_node->left =
                Left_Rotate(current_node->left);
            return Right_Rotate(current_node);
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Tree t;

    int a[]={32, 51, 27, 83, 96, 11, 45, 75, 66};

    for(int i = 0;i < 9; i++) {
        Insert(t,a[i]);
    }

    int check=Calculate_Balance_Factor(t.root);
    cout <<"He so can bang truoc khi xoay: "
         << check << endl;

    Tree new_t;
    new_t.root=Balance_Tree(t.root);

    int check_after=
        Calculate_Balance_Factor(new_t.root);

    cout << "He so can bang sau khi xoay: "
         << check_after << endl;

    return 0;
}

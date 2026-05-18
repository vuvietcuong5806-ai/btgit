#include <iostream>
using namespace std;

// ================= NODE =================

struct Node {
    int data;
    Node* left;
    Node* right;
};

// ================= CREATE NODE =================

Node* createNode(int x) {

    Node* p = new Node;

    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

// ================= CÂY Ð?Y Ð? =================

Node* fullTree() {

    /*
              1
            /   \
           2     3
          / \   / \
         4  5  6  7
    */

    Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    return root;
}

// ================= CÂY L?CH TRÁI =================

Node* leftSkewedTree() {

    /*
            1
           /
          2
         /
        3
    */

    Node* root = createNode(1);

    root->left = createNode(2);
    root->left->left = createNode(3);

    return root;
}

// ================= CÂY L?CH PH?I =================

Node* rightSkewedTree() {

    /*
        1
         \
          2
           \
            3
    */

    Node* root = createNode(1);

    root->right = createNode(2);
    root->right->right = createNode(3);

    return root;
}

// ================= CÂY ZIGZAG =================

Node* zigzagTree() {

    /*
            1
           /
          2
           \
            3
           /
          4
    */

    Node* root = createNode(1);

    root->left = createNode(2);

    root->left->right = createNode(3);

    root->left->right->left = createNode(4);

    return root;
}

// ================= PREORDER =================
// Root -> Left -> Right

void preorder(Node* root) {

    if (root == NULL)
        return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

// ================= INORDER =================
// Left -> Root -> Right

void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// ================= POSTORDER =================
// Left -> Right -> Root

void postorder(Node* root) {

    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}

// ================= HÀM TEST =================

void testTree(Node* root) {

    cout << "Preorder: ";
    preorder(root);

    cout << endl;

    cout << "Inorder: ";
    inorder(root);

    cout << endl;

    cout << "Postorder: ";
    postorder(root);

    cout << endl;
}

// ================= MAIN =================

int main() {

    cout << "===== FULL TREE =====" << endl;

    Node* full = fullTree();

    testTree(full);

    cout << endl;

    cout << "===== LEFT SKEWED TREE =====" << endl;

    Node* leftTree = leftSkewedTree();

    testTree(leftTree);

    cout << endl;

    cout << "===== RIGHT SKEWED TREE =====" << endl;

    Node* rightTree = rightSkewedTree();

    testTree(rightTree);

    cout << endl;

    cout << "===== ZIGZAG TREE =====" << endl;

    Node* zigzag = zigzagTree();

    testTree(zigzag);

    return 0;
}

#include <iostream>
using namespace std;

// ======================================================
//                  PHAN 1: CAY MOC NOI
// ======================================================

struct Node {

    int data;

    Node* left;
    Node* right;
};

// ================= TAO NODE =================

Node* createNode(int x) {

    Node* p = new Node;

    p->data = x;

    p->left = NULL;
    p->right = NULL;

    return p;
}

// ================= CAY DAY DU =================

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

// ================= CAY LECH TRAI =================

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

// ================= CAY LECH PHAI =================

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

// ================= CAY ZIGZAG =================

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

// ======================================================
//                     DUYET CAY
// ======================================================

// ================= PREORDER =================
// Root -> Left -> Right

void preorder(Node* root) {

    if(root == NULL)
        return;

    cout << root->data << " ";

    preorder(root->left);

    preorder(root->right);
}

// ================= INORDER =================
// Left -> Root -> Right

void inorder(Node* root) {

    if(root == NULL)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// ================= POSTORDER =================
// Left -> Right -> Root

void postorder(Node* root) {

    if(root == NULL)
        return;

    postorder(root->left);

    postorder(root->right);

    cout << root->data << " ";
}

// ================= TEST CAY =================

void testTraversal(Node* root) {

    cout << "Preorder : ";
    preorder(root);

    cout << endl;

    cout << "Inorder  : ";
    inorder(root);

    cout << endl;

    cout << "Postorder: ";
    postorder(root);

    cout << endl;
}

// ======================================================
//            PHAN 2: CAY LUU TRU TUAN TU
// ======================================================

class ArrayTree {

private:

    int tree[100];

public:

    ArrayTree() {

        for(int i = 0; i < 100; i++) {

            tree[i] = -1;
        }
    }

    // ================= CAY DAY DU =================

    void createFullTree() {

        tree[0] = 1;

        tree[1] = 2;
        tree[2] = 3;

        tree[3] = 4;
        tree[4] = 5;
        tree[5] = 6;
        tree[6] = 7;
    }

    // ================= CAY LECH TRAI =================

    void createLeftSkewedTree() {

        tree[0] = 1;

        tree[1] = 2;

        tree[3] = 3;
    }

    // ================= CAY LECH PHAI =================

    void createRightSkewedTree() {

        tree[0] = 1;

        tree[2] = 2;

        tree[6] = 3;
    }

    // ================= CAY ZIGZAG =================

    void createZigzagTree() {

        tree[0] = 1;

        tree[1] = 2;

        tree[4] = 3;

        tree[9] = 4;
    }

    // ================= HIEN THI =================

    void display() {

        for(int i = 0; i < 15; i++) {

            if(tree[i] != -1) {

                cout << "Index "
                     << i
                     << " : "
                     << tree[i]
                     << endl;
            }
        }
    }
};

// ======================================================
//                 PHAN 3: CAY BIEU THUC
// ======================================================

struct ExpNode {

    char data;

    ExpNode* left;
    ExpNode* right;
};

// ================= TAO NODE =================

ExpNode* createExpNode(char x) {

    ExpNode* p = new ExpNode;

    p->data = x;

    p->left = NULL;
    p->right = NULL;

    return p;
}

// ================= TAO CAY BIEU THUC =================

ExpNode* expressionTree() {

    /*
                *
              /   \
             +     -
            / \   / \
           a  b  c  d

        (a+b)*(c-d)
    */

    ExpNode* root = createExpNode('*');

    root->left = createExpNode('+');
    root->right = createExpNode('-');

    root->left->left = createExpNode('a');
    root->left->right = createExpNode('b');

    root->right->left = createExpNode('c');
    root->right->right = createExpNode('d');

    return root;
}

// ================= PREFIX =================

void prefix(ExpNode* root) {

    if(root == NULL)
        return;

    cout << root->data << " ";

    prefix(root->left);

    prefix(root->right);
}

// ================= INFIX =================

void infix(ExpNode* root) {

    if(root == NULL)
        return;

    if(root->left != NULL)
        cout << "(";

    infix(root->left);

    cout << root->data;

    infix(root->right);

    if(root->right != NULL)
        cout << ")";
}

// ================= POSTFIX =================

void postfix(ExpNode* root) {

    if(root == NULL)
        return;

    postfix(root->left);

    postfix(root->right);

    cout << root->data << " ";
}

// ======================================================
//                         MAIN
// ======================================================

int main() {

    // ==================================================
    //                 CAY MOC NOI
    // ==================================================

    cout << "========== LINKED FULL TREE ==========" << endl;

    Node* full = fullTree();

    testTraversal(full);

    cout << endl;

    cout << "====== LINKED LEFT SKEWED TREE ======" << endl;

    Node* left = leftSkewedTree();

    testTraversal(left);

    cout << endl;

    cout << "===== LINKED RIGHT SKEWED TREE ======" << endl;

    Node* right = rightSkewedTree();

    testTraversal(right);

    cout << endl;

    cout << "========== LINKED ZIGZAG TREE =======" << endl;

    Node* zigzag = zigzagTree();

    testTraversal(zigzag);

    cout << endl;

    // ==================================================
    //                 CAY TUAN TU
    // ==================================================

    cout << "========== ARRAY FULL TREE ==========" << endl;

    ArrayTree arrFull;

    arrFull.createFullTree();

    arrFull.display();

    cout << endl;

    cout << "====== ARRAY LEFT SKEWED TREE ======" << endl;

    ArrayTree arrLeft;

    arrLeft.createLeftSkewedTree();

    arrLeft.display();

    cout << endl;

    cout << "===== ARRAY RIGHT SKEWED TREE ======" << endl;

    ArrayTree arrRight;

    arrRight.createRightSkewedTree();

    arrRight.display();

    cout << endl;

    cout << "========== ARRAY ZIGZAG TREE =======" << endl;

    ArrayTree arrZigzag;

    arrZigzag.createZigzagTree();

    arrZigzag.display();

    cout << endl;

    // ==================================================
    //                 CAY BIEU THUC
    // ==================================================

    cout << "========== EXPRESSION TREE ==========" << endl;

    ExpNode* expRoot = expressionTree();

    cout << "Prefix : ";
    prefix(expRoot);

    cout << endl;

    cout << "Infix  : ";
    infix(expRoot);

    cout << endl;

    cout << endl;

    cout << "Postfix: ";
    postfix(expRoot);

    cout << endl;

    return 0;
}

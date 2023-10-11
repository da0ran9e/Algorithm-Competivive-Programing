#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* leftChild;
    Node* rightChild;

    Node(int v) : val(v), leftChild(nullptr), rightChild(nullptr) {}
};

Node* root = nullptr;

Node* insert(Node* p, int v) {
    if (p == nullptr) {
        return new Node(v);
    }
    if (v > p->val) {
        p->rightChild = insert(p->rightChild, v);
    } else if (v < p->val) {
        p->leftChild = insert(p->leftChild, v);
    }
    return p;
}
void preOrder(Node* r) {
    if (r == nullptr) {
        return;
    }
    cout << r->val << ' ';
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}
int main() {
    string line;
    do {
        cin >> line;
        if (line == "insert") {
            int u;
            cin >> u;
            root = insert(root, u);
        }
    } while (line != "#");
    preOrder(root);
}
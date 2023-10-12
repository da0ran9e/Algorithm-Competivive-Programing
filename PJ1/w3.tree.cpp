#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* leftMostChild;
    TreeNode* rightSibling;

    TreeNode(int v) : val(v), leftMostChild(nullptr), rightSibling(nullptr) {}
};

TreeNode* root;

TreeNode* makeNode(int v) {
    TreeNode* p = new TreeNode(v);
    return p;
}

TreeNode* find(TreeNode* r, int a) {
    if (r == nullptr) return nullptr;
    if (r->val == a) return r;  // reached the root
    TreeNode* p = r->leftMostChild;
    while (p != nullptr) {
        TreeNode* q = find(p, a);
        if (q != nullptr) return q;
        p = p->rightSibling;
    }
    return nullptr;
}

void insert(int u, int v) {
    TreeNode* p = find(root, u);
    if (p != nullptr) return;
    TreeNode* q = find(root, v);
    if (q == nullptr) return;
    p = makeNode(u);
    if (q->leftMostChild == nullptr) {
        q->leftMostChild = p;
        return;
    }
    TreeNode* last = q->leftMostChild;
    while (last->rightSibling != nullptr) last = last->rightSibling;
    last->rightSibling = p;
}

void preOrder(TreeNode* p) {
    if (p == nullptr) return;
    cout << p->val << ' ';
    for (TreeNode* tmp = p->leftMostChild; tmp != nullptr; tmp = tmp->rightSibling)
        preOrder(tmp);
}

void inOrder(TreeNode* r) {
    if (r == nullptr) return;
    TreeNode* p = r->leftMostChild;
    inOrder(p);  
    cout << r->val << ' '; 
    if (p == nullptr) return;
    p = p->rightSibling;
    while (p != nullptr) {
        inOrder(p);
        p = p->rightSibling;
    }
}

void postOrder(TreeNode* r) {
    if (r == nullptr) return;
    for (TreeNode* tmp = r->leftMostChild; tmp != nullptr; tmp = tmp->rightSibling)
        postOrder(tmp);
    cout << r->val << ' ';
}

int main() {
    string line;
    root = nullptr;
    while (true) {
        cin >> line;
        if (line == "*") break;
        else if (line == "MakeRoot") {
            int u;
            cin >> u;
            root = makeNode(u);
        }
        else if (line == "Insert") {
            int u, v;
            cin >> u >> v;
            insert(u, v);
        }
        else if (line == "PreOrder") {
            preOrder(root);
            cout << endl;
        }
        else if (line == "InOrder") {
            inOrder(root);
            cout << endl;
        }
        else if (line == "PostOrder") {
            postOrder(root);
            cout << endl;
        }
    }
}

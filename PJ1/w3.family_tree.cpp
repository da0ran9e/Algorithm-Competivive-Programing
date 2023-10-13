#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    string val;
    TreeNode* leftMostChild;
    TreeNode* rightSibling;

    TreeNode(const string& v) : val(v), leftMostChild(nullptr), rightSibling(nullptr) {}
};

TreeNode* root;

TreeNode* makeNode(const string& v) {
    TreeNode* p = new TreeNode(v);
    return p;
}

TreeNode* find(TreeNode* r, const string& a) {
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
int depthTreeNode(TreeNode* r, string v, int d) {
        if (r == nullptr) return -1;
        if (r->val == v) return d;
        for (TreeNode* p = r->leftMostChild; p != nullptr; p = p->rightSibling) {
            if (p->val == v) return d + 1;
            int d1 = depthTreeNode(p, v, d + 1);
            if (d1 != -1) return d1;
        }
        return -1;
    }
int depth(string v) {
        int res = depthTreeNode(root, v, 1);
        return res;
    }

void insert(const string& u, const string& v) {
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


int main() {
    list<auto> trees;

    string child;
    string parent;
    string query;
    string name;

    root = nullptr;
    while (true) {
        cin >> child;
        if (line == "***") break;  
    }
    while (true) {
        cin >> query >> name;
        if (line == "***") break;  
    }
}
/*
              Newman 
                | 
        ------------------------------------
        |             |                     |
     Peter          Mark                   David
                    |                        |
            -----------------             ------------
            |       |       |             |          |
          Paul    Stephan  Thomas       John        Bill
                            |
                        -----------
                        |         |
                    Michael      Pierre  
*/
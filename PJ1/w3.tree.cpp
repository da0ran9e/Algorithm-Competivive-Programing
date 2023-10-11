#include <iostream>
#include <string>

class TreeNode {
public:
    int val;
    TreeNode* leftMostChild;
    TreeNode* rightSibling;

    TreeNode(int v) : val(v), leftMostChild(nullptr), rightSibling(nullptr) {}

    void insertChild(int v) {
        TreeNode* newNode = new TreeNode(v);
        if (leftMostChild == nullptr) {
            leftMostChild = newNode;
        } else {
            TreeNode* last = leftMostChild;
            while (last->rightSibling != nullptr) {
                last = last->rightSibling;
            }
            last->rightSibling = newNode;
        }
    }
};

class Tree {
public:
    TreeNode* root;

    Tree() : root(nullptr) {}

    TreeNode* find(int a, TreeNode* node = nullptr) {
        if (node == nullptr) {
            node = root;
        }
        if (node == nullptr) return nullptr;
        if (node->val == a) return node;
        TreeNode* p = node->leftMostChild;
        while (p != nullptr) {
            TreeNode* q = find(a, p);
            if (q != nullptr) return q;
            p = p->rightSibling;
        }
        return nullptr;
    }

    void makeRoot(int u) {
        root = new TreeNode(u);
    }

    void insert(int u, int v) {
        TreeNode* p = find(u);
        if (p != nullptr) return;
        TreeNode* q = find(v);
        if (q == nullptr) return;
        q->insertChild(u);
    }

    void preOrder(TreeNode* node = nullptr) {
        if (node == nullptr) {
            node = root;
        }
        if (node == nullptr) return;

        std::cout << node->val << ' ';
        TreeNode* tmp = node->leftMostChild;
        while (tmp != nullptr) {
            preOrder(tmp);
            tmp = tmp->rightSibling;
        }
    }

    void inOrder(TreeNode* node = nullptr) {
        if (node == nullptr) {
            node = root;
        }
        if (node == nullptr) return;

        inOrder(node->leftMostChild);
        std::cout << node->val << ' ';
        TreeNode* tmp = node->leftMostChild;
        while (tmp != nullptr) {
            inOrder(tmp);
            tmp = tmp->rightSibling;
        }
    }

    void postOrder(TreeNode* node = nullptr) {
        if (node == nullptr) {
            node = root;
        }
        if (node == nullptr) return;

        TreeNode* tmp = node->leftMostChild;
        while (tmp != nullptr) {
            postOrder(tmp);
            tmp = tmp->rightSibling;
        }
        std::cout << node->val << ' ';
    }

    int height(int v) {
        TreeNode* p = find(v);
        return heightTreeNode(p);
    }

    int depth(int v) {
        int res = depthTreeNode(root, v, 1);
        return res;
    }

private:
    int heightTreeNode(TreeNode* r) {
        if (r == nullptr) return 0;
        int maxh = 0;
        for (TreeNode* tmp = r->leftMostChild; tmp != nullptr; tmp = tmp->rightSibling) {
            int h = heightTreeNode(tmp);
            if (h > maxh) maxh = h;
        }
        return maxh + 1;
    }

    int depthTreeNode(TreeNode* r, int v, int d) {
        if (r == nullptr) return -1;
        if (r->val == v) return d;
        for (TreeNode* p = r->leftMostChild; p != nullptr; p = p->rightSibling) {
            if (p->val == v) return d + 1;
            int d1 = depthTreeNode(p, v, d + 1);
            if (d1 != -1) return d1;
        }
        return -1;
    }
};

int main() {
    Tree tree;
    std::string line;
    while (true) {
        std::cin >> line;
        if (line == "*") break;
        else if (line == "MakeRoot") {
            int u;
            std::cin >> u;
            tree.makeRoot(u);
        }
        else if (line == "Insert") {
            int u, v;
            std::cin >> u >> v;
            tree.insert(u, v);
        }
        else if (line == "PreOrder") {
            tree.preOrder();
            std::cout << std::endl;
        }
        else if (line == "InOrder") {
            tree.inOrder();
            std::cout << std::endl;
        }
        else if (line == "PostOrder") {
            tree.postOrder();
            std::cout << std::endl;
        }
        else if (line == "Height") {
            int v;
            std::cin >> v;
            std::cout << tree.height(v) << std::endl;
        }
        else if (line == "Depth") {
            int v;
            std::cin >> v;
            std::cout << tree.depth(v) << std::endl;
        }
    }
    return 0;
}

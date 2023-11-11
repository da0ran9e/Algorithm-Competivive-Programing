#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int totalTransactions = 0, totalMoney = 0;
int accountCount = 0;

struct node {
    char from_account[21];
    char to_account[21];
    int money;
    char time_point[9];
    char atm[11];
    node* leftChild;
    node* rightChild;
};

node* root;
char bankAccounts[MAX][21];

node* makeNode(char* from_account, char* to_account, int money, char* time_point, char* atm) {
    node* newNode = new node;
    strcpy(newNode->from_account, from_account);
    strcpy(newNode->to_account, to_account);
    newNode->money = money;
    strcpy(newNode->time_point, time_point);
    strcpy(newNode->atm, atm);
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    return newNode;
}

node* insert(node* root, char* from_account, char* to_account, int money, char* time_point, char* atm) {
    if (root == nullptr) return makeNode(from_account, to_account, money, time_point, atm);

    int c = strcmp(root->from_account, from_account);
    if (c == 0) {
        // Check the to_account when from_account is the same
        c = strcmp(root->to_account, to_account);
        if (c == 0) {
            // If both from_account and to_account are the same, update the money
            root->money += money;
            return root;
        }
    }

    if (c < 0) root->rightChild = insert(root->rightChild, from_account, to_account, money, time_point, atm);
    else root->leftChild = insert(root->leftChild, from_account, to_account, money, time_point, atm);
    return root;
}

node* find(node* root, char* number) {
    if (root == nullptr) return nullptr;

    int c = strcmp(root->from_account, number);
    if (c == 0) return root;
    else if (c < 0) return find(root->rightChild, number);
    else return find(root->leftChild, number);
}

void inorderTraversal(node* root, char* prevAccount) {
    if (root != nullptr) {
        inorderTraversal(root->leftChild, prevAccount);
        if (strcmp(root->from_account, prevAccount) != 0 && strcmp(bankAccounts[accountCount - 1], root->from_account)) {
            strcpy(bankAccounts[accountCount], root->from_account);
            accountCount++;
        }
        inorderTraversal(root->rightChild, root->from_account);
    }
}

void input() {
    char from_account[21], to_account[21], time_point[9], atm[11];
    int money;

    while (true) {
        int result = scanf("%s", from_account);
        if (result == EOF || strcmp(from_account, "#") == 0) {
            break;
        } else {
            scanf("%s %d %s %s", to_account, &money, time_point, atm);

            root = insert(root, from_account, to_account, money, time_point, atm);

            totalTransactions++;
            totalMoney += money;
        }
    }

    inorderTraversal(root, ""); // Pass an empty string as the initial previous account
}

int totalMoneyFrom(node* root, char* from_account) {
    if (root == nullptr) return 0;

    int sum = 0;

    int c = strcmp(root->from_account, from_account);
    if (c == 0) {
        sum += root->money;
    }

    if (c <= 0) {
        sum += totalMoneyFrom(root->rightChild, from_account);
    }

    if (c >= 0) {
        sum += totalMoneyFrom(root->leftChild, from_account);
    }

    return sum;
}

int hasCycle(node* current, char* start, int k, int count, int* visited) {
    if (count > k + 1) return 0; // cycle length exceeded k
    //atoi: convert string to integer
    visited[atoi(current->from_account)] = 1; // Mark the current account as visited

    if (strcmp(current->from_account, start) == 0 && count == k) {
        return 1; // cycle of length k found
    }

    if (current->rightChild != nullptr && !visited[atoi(current->rightChild->from_account)] &&
        hasCycle(current->rightChild, start, k, count + 1, visited)) {
        return 1; // cycle found in the right subtree
    }

    if (current->leftChild != nullptr && !visited[atoi(current->leftChild->from_account)] &&
        hasCycle(current->leftChild, start, k, count + 1, visited)) {
        return 1; // cycle found in the left subtree
    }

    visited[atoi(current->from_account)] = 0; // Unmark the current account as visited (backtrack)

    return 0; // no cycle found
}

void queries() {
    char cmd[100];
    char from_account[21];
    int k;

    while (true) {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) break;
        else if (strcmp(cmd, "?number_transactions") == 0) {
            printf("%d\n", totalTransactions);
        } else if (strcmp(cmd, "?total_money_transaction") == 0) {
            printf("%d\n", totalMoney);
        } else if (strcmp(cmd, "?list_sorted_accounts") == 0) {
            for (int i = 0; i < accountCount; i++) {
                printf("%s ", bankAccounts[i]);
            }
        } else if (strcmp(cmd, "?total_money_transaction_from") == 0) {
            scanf("%s", from_account);
            int totalMoneyFromAccount = totalMoneyFrom(root, from_account);
            printf("%d\n", totalMoneyFromAccount);
        } else if (strcmp(cmd, "?inspect_cycle") == 0) {
            scanf("%s %d", from_account, &k);
            node* p = find(root, from_account);
            if (p != nullptr) {
                int visited[MAX] = {0};
                int hasCycleResult = hasCycle(p, from_account, k, 1, visited);
                printf("%d\n", hasCycleResult);
            } else {
                printf("0\n"); // account not found, no cycle
            }
        }
    }
}

int main() {
    input();
    queries();
    return 0;
}

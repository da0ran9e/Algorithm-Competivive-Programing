#include <bits/stdc++.h>
using namespace std;

#define M 100000
#define N 86401

int total_orders = 0;
int total_price = 0;

struct Node {
    char shop_id[11];
    Node* leftChild;
    Node* rightChild;
    int rev;
};

struct cusShop {
    char shop_id[11];
    char cus_id[11];
    cusShop* leftChild;
    cusShop* rightChild;
    int rev;
};

cusShop* rev_cus_shop[M];
int o[N], t[N];

int hashShop(char* s) {
    int h = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        h = (h * 256 + s[i]) % M;
    return h;
}

int hashCusShop(char* c, char* s) {
    int h = 0;
    int n1 = strlen(c);
    int n2 = strlen(s);
    for (int i = 0; i < n1; i++)
        h = (h * 256 + c[i]) % M;
    for (int i = 0; i < n2; i++)
        h = (h * 256 + s[i]) % M;
    return h;
}

int hashTime(char* t) {
    int second = 0;
    second = ((t[0] - '0') * 10 + (t[1] - '0')) * 3600 + ((t[3] - '0') * 10 + (t[4] - '0')) * 60 + ((t[6] - '0') * 10 + (t[7] - '0'));
    return second;
}

cusShop* makenodeCusShop(char* s, char* c, int price) {
    cusShop* tmp = (cusShop*)malloc(sizeof(cusShop));
    strcpy(tmp->cus_id, c);
    strcpy(tmp->shop_id, s);
    tmp->rev = price;
    tmp->leftChild = nullptr;
    tmp->rightChild = nullptr;
    return tmp;
}

int compareCusShop(char* s, char* c, char* shop_id, char* cus_id) {
    int cmp1 = strcmp(shop_id, s);
    int cmp2 = strcmp(cus_id, c);
    if (cmp1 == 0) {
        return cmp2;
    } else return cmp1;
}

cusShop* findCusShop(cusShop* r, char* s, char* c) {
    if (r == nullptr) return nullptr;
    int cmp = compareCusShop(s, c, r->shop_id, r->cus_id);
    if (cmp == 0) return r;
    else if (cmp < 0) {
        return findCusShop(r->leftChild, s, c);
    } else return findCusShop(r->rightChild, s, c);
}

cusShop* insertBSTCS(cusShop* r, char* s, char* c, int price) {
    if (r == nullptr) return makenodeCusShop(s, c, price);
    int cmp = compareCusShop(s, c, r->shop_id, r->cus_id);
    if (cmp == 0) return r;
    else if (cmp < 0) {
        r->leftChild = insertBSTCS(r->leftChild, s, c, price);
        return r;
    } else {
        r->rightChild = insertBSTCS(r->rightChild, s, c, price);
        return r;
    }
}

void insertCS(char* s, char* c, int price) {
    int index = hashCusShop(c, s);
    cusShop* p = findCusShop(rev_cus_shop[index], s, c);
    if (p == nullptr) {
        rev_cus_shop[index] = insertBSTCS(rev_cus_shop[index], s, c, price);
    } else {
        p->rev += price;
    }
}

Node* rev_shop[M];

Node* makenode(char* name, int p) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    strcpy(tmp->shop_id, name);
    tmp->leftChild = nullptr;
    tmp->rightChild = nullptr;
    tmp->rev = p;
    return tmp;
}

Node* insertBST(Node* r, char* name, int price) {
    if (r == nullptr) return makenode(name, price);
    int c = strcmp(r->shop_id, name);
    if (c == 0) return r;
    else if (c < 0) {
        r->leftChild = insertBST(r->leftChild, name, price);
        return r;
    } else {
        r->rightChild = insertBST(r->rightChild, name, price);
        return r;
    }
}

Node* findBST(Node* r, char* name) {
    if (r == nullptr) return nullptr;
    int cmp = strcmp(r->shop_id, name);
    if (cmp == 0) return r;
    if (cmp < 0) return findBST(r->leftChild, name);
    else return findBST(r->rightChild, name);
}

void insert(char* name, int price) {
    int index = hashShop(name);
    Node* p = findBST(rev_shop[index], name);
    if (p == nullptr) {
        rev_shop[index] = insertBST(rev_shop[index], name, price);
    } else {
        p->rev += price;
    }
}

void init() {
    for (int i = 0; i <= M; i++)
        rev_shop[i] = nullptr;
    for (int i = 0; i <= M; i++)
        rev_cus_shop[i] = nullptr;
    for (int i = 0; i <= N; i++) {
        t[i] = 0;
        o[i] = 0;
    }
}

void run() {
    init();
    char cus_id[11];
    char pro_id[11];
    int price;
    char shop_id[11];
    char time[9];
    while (1) {
        cin >> cus_id;
        if (!strcmp(cus_id, "#")) break;
        else {
            cin >> pro_id >> price >> shop_id >> time;
            int index_t = hashTime(time);
            o[index_t] += price;
            total_orders++;
            total_price += price;
            insert(shop_id, price);
            insertCS(shop_id, cus_id, price);
        }
    }
    for (int i = 0; i <= N; i++)
        t[i] = t[i - 1] + o[i];
    char cmd[200];
    while (1) {
        cin >> cmd;
        if (!strcmp(cmd, "#")) break;
        else if (!strcmp(cmd, "?total_number_orders")) {
            cout << total_orders << endl;
        } else if (!strcmp(cmd, "?total_revenue")) {
            cout << total_price << endl;
        } else if (!strcmp(cmd, "?revenue_of_shop")) {
            char shop[11];
            cin >> shop;
            int index = hashShop(shop);
            Node* p = findBST(rev_shop[index], shop);
            if (p == nullptr) cout << "0" << endl;
            else cout << p->rev << endl;
        } else if (!strcmp(cmd, "?total_consume_of_customer_shop")) {
            char shop[11];
            char cus[11];
            cin >> cus >> shop;
            int index = hashCusShop(cus, shop);
            cusShop* p = findCusShop(rev_cus_shop[index], shop, cus);
            if (p == nullptr) cout << "0" << endl;
            else cout << p->rev << endl;
        } else if (!strcmp(cmd, "?total_revenue_in_period")) {
            char time1[11];
            char time2[11];
            cin >> time1 >> time2;
            int t1 = hashTime(time1);
            int t2 = hashTime(time2);
            cout << t[t2] - t[t1 - 1] << endl;
        }
    }
}

int main() {
    run();
    return 0;
}

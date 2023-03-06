/*
    Data Structure and Algorithm.
    Created by CLion
    Author: Depressant
    Date: 2023.3.6
    Time: 上午 9:39
*/
#include "bits/stdc++.h"

typedef long long ll;
int N, L;

void init() {

}

void read() {

}

struct BST {
    int val;
    BST *l, *r;

    BST(int val) : val(val) {
        l = r = nullptr;
    }

    void insert(int key) {
        if (key < val) {
            if (l)l->insert(key);
            else l = new BST(key);
        } else {
            if (r)r->insert(key);
            else r = new BST(key);
        }
    }

    ~BST() {
        delete l;
        delete r;
//        delete this;
    }
};

void insert(BST *&root, int key) {
    if (root)root->insert(key);
    else root = new BST(key);
}

std::vector<int> dfs(std::vector<int> &ret, BST *cur) {
    if (!cur)return ret;
    ret.push_back(cur->val);
    dfs(ret, cur->l);
    dfs(ret, cur->r);
    return ret;
}

void solve() {
    BST *root = nullptr;
    for (int i = 0; i < N; ++i) {
        int key;
        scanf("%d", &key);
        insert(root, key);
    }
    std::vector<int> root_seq;
    dfs(root_seq, root);
    for (int i = 0; i < L; ++i) {
        BST *v = nullptr;
        for (int j = 0; j < N; ++j) {
            int key;
            scanf("%d", &key);
            insert(v, key);
        }
        std::vector<int> v_seq;
        dfs(v_seq, v);
        if (v_seq == root_seq)puts("Yes");
        else puts("No");
        delete v;
    }
}

int main() {
//    freopen("Depressant.txt", "r", stdin);
    init();
    read();
    while (true) {
        scanf("%d%d", &N, &L);
        if (!N)break;
        solve();
    }
    return 0;
}
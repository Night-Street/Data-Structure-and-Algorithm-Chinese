/*
    Data Structure and Algorithm.
    Created by CLion
    Author: Depressant
    Date: 2023.3.6
    Time: 上午 10:47
*/
#include "bits/stdc++.h"

typedef long long ll;
int N, M;

void init() {

}


int name2idx(std::string name) {
    static std::unordered_map<std::string, int> _name2idx;
    static std::unordered_map<int, std::string> _idx2name;
    if (_name2idx.find(name) != _name2idx.end())return _name2idx[name];
    else {
        int idx = _name2idx.size();
        _name2idx[name] = idx;
        _idx2name[idx] = name;
        return idx;
    }
}

#define maxn 105
int children[maxn][maxn];
int parent[maxn];

void add_child(int p, int c) {
    children[p][++children[p][0]] = c;
}

void add_parent(int p, int c) {
    parent[c] = p;
}

void read() {
    std::cin >> N >> M;
    getchar();
    std::vector<int> path;
    for (int i = 0; i < N; ++i) {
        char carr[75];
        scanf("%[ a-zA-Z]%*c", carr);
        std::string s = carr;
        int pos = s.find_first_not_of(' ', 0);
        int size = path.size();
        for (int j = pos / 2; j < size; ++j) {
            path.pop_back();
        }
        int cur_idx = name2idx(s.substr(pos, s.length() - pos));
        path.push_back(cur_idx);
        if (pos / 2 - 1 >= 0) {
            add_child(path[pos / 2 - 1], cur_idx);
            add_parent(path[pos / 2 - 1], cur_idx);
        } else {
            add_parent(-1, cur_idx);
        }
    }
}

void output(bool f) {
    if (f)puts("True");
    else puts("False");
}

void solve() {
    for (int i = 0; i < M; ++i) {
        char name1[100], name2[100], relationship[100];
        scanf("%[a-zA-Z] is %*[a-z] %[a-zA-Z] of %[a-zA-Z]%*c", name1, relationship, name2);
        switch (relationship[0]) {
            case 'c': {
                output(parent[name2idx(name1)] == name2idx(name2));
                break;
            }
            case 'p': {
                output(parent[name2idx(name2)] == name2idx(name1));
                break;
            }
            case 's': {
                output(parent[name2idx(name1)] == parent[name2idx(name2)]);
                break;
            }
            case 'd': {
                int p = parent[name2idx(name1)];
                while (true) {
                    if (p == name2idx(name2) || p == -1)break;
                    p = parent[p];
                }
                output(p == name2idx(name2));
                break;
            }
            case 'a':{
                int p = parent[name2idx(name2)];
                while (true) {
                    if (p == name2idx(name1) || p == -1)break;
                    p = parent[p];
                }
                output(p == name2idx(name1));
                break;
            }
        }
    }
}

int main() {
//    freopen("Depressant.txt", "r", stdin);
    init();
    read();
    solve();
    return 0;
}
/*
    Data Structure and Algorithm.
    Created by CLion
    Author: Depressant
    Date: 2023.3.9
    Time: 下午 4:10
*/
#include "bits/stdc++.h"

typedef long long ll;
#define inf INT_MAX
#define maxn 105
struct Node {
    int v;
    int l;
};
std::vector<std::vector<Node> > vgraph;
int N, M;

int getLength(int a, int b) {
    if (a == b)return 0;
    auto pos = std::find_if(vgraph[a].begin(), vgraph[a].end(), [&](Node &node) {
        return node.v == b;
    });
    if (pos == vgraph[a].end())return inf;
    else return pos->l;
}

void init() {

}

void read() {
    std::cin >> N >> M;
    vgraph.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        vgraph[a].push_back(Node{b, l});
        vgraph[b].push_back(Node{a, l});
    }
}

bool dfs(int cur) {
//    static int idx = 0;
//    std::cout << "num:" << idx << std::endl;
    static bool vis[maxn] = {false};
    if (vis[cur])return true;
    vis[cur] = true;
    for (Node n: vgraph[cur])dfs(n.v);
    if (*std::min_element(vis + 1, vis + N + 1) == 0)return false;
    else return true;
}

void solve() {
    if (!dfs(1)) {
        std::cout << 0;
        return;
    }
    int d[maxn][maxn];

    for (auto &i: d) std::fill(std::begin(i), std::end(i), inf);
//    for (int i = 1; i <= N; ++i) d[i][i] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            d[i][j] = getLength(i, j);
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
//                int lji = getLength(j, i);
//                int lik = getLength(i, k);
                if (d[j][k] - d[j][i] > d[i][k]) {
                    d[j][k] = d[j][i] + d[i][k];
                }
            }
        }
    }
    int v = 0, l = inf;
    for (int i = 1; i <= N; ++i) {
        int _l = *std::max_element(d[i] + 1, d[i] + N + 1);
        if (_l < l) {
            v = i;
            l = _l;
        }
    }
    printf("%d %d", v, l);
}

int main() {
//    freopen("Depressant.txt", "r", stdin);
    init();
    read();
    solve();
    return 0;
}
/*
    Data Structure and Algorithm.
    Created by CLion
    Author: Depressant
    Date: 2023.3.9
    Time: 下午 3:37
*/
#include "bits/stdc++.h"

#define maxn 505
#define inf INT_MAX
typedef long long ll;
int N, M, S, D;
struct Node {
    int vertex;
    int length;
    int cost;
};
std::vector<std::vector<Node> > vgraph;

void init() {

}

int getLength(int s, int d) {
    auto pos = std::find_if(vgraph[s].begin(), vgraph[s].end(), [&](Node &node) {
        return node.vertex == d;
    });
    if (pos == vgraph[s].end())return inf;
    else return pos->length;
}

int getCost(int s, int d) {
    auto pos = std::find_if(vgraph[s].begin(), vgraph[s].end(), [&](Node &node) {
        return node.vertex == d;
    });
    if (pos == vgraph[s].end())return inf;
    else return pos->cost;
}

void read() {
    std::cin >> N >> M >> S >> D;
    vgraph.resize(N);
    for (int i = 0; i < M; ++i) {
        int x, y, l, c;
        scanf("%d%d%d%d", &x, &y, &l, &c);
        vgraph[x].push_back(Node{y, l, c});
        vgraph[y].push_back(Node{x, l, c});
    }
}

void solve() {
    int d[maxn];
    int c[maxn];
    bool done[maxn] = {false};
    std::fill(std::begin(d), std::end(d), inf);
    std::fill(std::begin(c), std::end(c), inf);

    d[S] = 0;
    c[S] = 0;

    for (int i = 0; i < N; ++i) {
        int v, d_min = inf;
        for (int j = 0; j < N; ++j) {
            if (done[j])continue;
            if (d[j] < d_min) {
                v = j;
                d_min = d[j];
            }
        }
        done[v] = true;
//        select v
        for (Node n: vgraph[v]) {
            if (done[n.vertex])continue;
            int _l = getLength(v, n.vertex);
            int _c = getCost(v, n.vertex);
            if (d[n.vertex] - d[v] > _l) {
                d[n.vertex] = d[v] + _l;
                c[n.vertex] = c[v] + _c;
            } else if (d[n.vertex] - d[v] == _l && c[n.vertex] - c[v] > _c) {
                c[n.vertex] = c[v] + _c;
            }
        }
    }
    printf("%d %d", d[D], c[D]);
}

int main() {
//    freopen("Depressant.txt", "r", stdin);
    init();
    read();
    solve();
    return 0;
}
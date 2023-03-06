/*
    Data Structure and Algorithm.
    Created by CLion
    Author: Depressant
    Date: 2023.3.6
    Time: 上午 9:03
*/
#include "bits/stdc++.h"

typedef long long ll;

struct Msg {
    int level;
    std::string name;

    bool operator<(const Msg &rhs) const {
        return level < rhs.level;
    }

    bool operator>(const Msg &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Msg &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Msg &rhs) const {
        return !(*this < rhs);
    }

    Msg(int level, const std::string &name) : level(level), name(name) {}
};

std::priority_queue<Msg, std::vector<Msg>, std::greater<> > pq;
int N;

void init() {
//    std::priority_queue<int,std::vector<int> >pq;
//    pq.push(2);
//    pq.push(1);
//    std::cout<<pq.top();
//    exit(0);
}

void read() {
    std::cin >> N;
    getchar();
    for (int i = 0; i < N; ++i) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd[0] == 'P') {
            std::string msgName;
            int priorityLevel;
            std::cin >> msgName >> priorityLevel;
            pq.push(*new Msg(priorityLevel, msgName));
        } else {
            if (!pq.empty()) {
                auto T = pq.top();
                pq.pop();
                std::cout << T.name << std::endl;
            } else {
                puts("EMPTY QUEUE!");
            }
        }
    }
}

void solve() {

}

int main() {
//    freopen("Depressant.txt", "r", stdin);
    init();
    read();
    solve();
    return 0;
}
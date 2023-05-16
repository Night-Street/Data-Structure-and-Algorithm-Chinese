/*
    Data Structure and Algorithm.
    Created by CLion
    Author: Depressant
    Date: 2023.5.16
    Time: 下午 1:03
*/
#include "bits/stdc++.h"

typedef long long ll;
int n;

void init() {

}

void move(char source, char target) {
    printf("%c -> %c\n", source, target);
}

void move(char source, char target, std::stack<int> &breakpoints) {
    printf("%c -> %c\n", source, target);
    if (breakpoints.empty())return;
    int t = breakpoints.top();
    breakpoints.pop();
    breakpoints.push(t + 1);
}

void hanoi_recursive(int n, char source, char proxy, char target) {
    if (n == 1) {
        move(source, target);
        return;
    }
    hanoi_recursive(n - 1, source, target, proxy);
    move(source, target);
    hanoi_recursive(n - 1, proxy, source, target);
}

struct Frame {
    int level;
    char source;
    char proxy;
    char target;
};

void hanoi_nonrecursive(int n, char source, char proxy, char target) {
    std::stack<Frame> frame_stack;
    std::stack<int> breakpoints;


    frame_stack.push(Frame{n, source, proxy, target});
    breakpoints.push(1);
    while (!frame_stack.empty()) {
        auto T = frame_stack.top();
        if (breakpoints.top() == 1) {
            if (T.level == 1) {
                frame_stack.pop();
                breakpoints.pop();
                move(T.source, T.target, breakpoints);
            } else {
                frame_stack.push(Frame{T.level - 1, T.source, T.target, T.proxy});
                breakpoints.push(1);
            }
            continue;
        }
        if (breakpoints.top() == 2) {
            move(T.source, T.target, breakpoints);
        }
        if (breakpoints.top() == 3) {
            if (T.level == 1) {
                frame_stack.pop();
                breakpoints.pop();
                move(T.source, T.target, breakpoints);
            } else {
                frame_stack.push(Frame{T.level - 1, T.proxy, T.source, T.target});
                breakpoints.push(1);
            }
            continue;
        }
        if (breakpoints.top() == 4) {
            frame_stack.pop();
            breakpoints.pop();
            if (!breakpoints.empty()) {
                int t = breakpoints.top();
                breakpoints.pop();
                breakpoints.push(t + 1);
            }

        }
    }
}

void read() {
    std::cin >> n;
}

void solve() {
    hanoi_nonrecursive(n, 'a', 'b', 'c');
}

int main() {
//    freopen("Depressant.txt", "r", stdin);
    init();
    read();
    solve();
    return 0;
}
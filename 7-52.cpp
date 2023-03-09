/*
    Data Structure and Algorithm.
    Created by CLion
    Author: Depressant
    Date: 2023.3.9
    Time: 下午 3:31
*/
#include "bits/stdc++.h"

typedef long long ll;

void init() {

}

std::vector<int> v1, v2;

void read() {
    while (true) {
        int x;
        std::cin >> x;
        if (x != -1)v1.push_back(x);
        else break;
    }
    while (true) {
        int x;
        std::cin >> x;
        if (x != -1)v2.push_back(x);
        else break;
    }
}

void solve() {
    int p1 = 0, p2 = 0;
    bool f = false;
    while (p1 != v1.size() && p2 != v2.size()) {
        if (v1[p1] < v2[p2]) {
//            printf("%d", v1[p1]);
            p1++;
        } else if (v1[p1] > v2[p2]) {
//            printf("%d", v2[p2]);
            p2++;
        } else {
            printf("%s%d", f ? " " : "", v1[p1]);
            f = true;
            p1++;
            p2++;
        }
    }
    if (!f)std::cout << "NULL";
//    else {
//        if (p1 == v1.size())
//            for (int i = p2; i < v2.size(); i++) {
//                printf("%s%d", f ? " " : "", v2[i]);
//                f = true;
//            }
//        else
//            for (int i = p1; i < v1.size(); i++) {
//                printf("%s%d", f ? " " : "", v1[i]);
//                f = true;
//            }
//    }
}

int main() {
//    freopen("Depressant.txt", "r", stdin);
    init();
    read();
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main () {
    int A, B, c;
    while (scanf("%d %d", &A, &B), (A != 0 || B != 0)) {
        unordered_set<int> a, b;
        int count = 0;
        while (A--) {
            scanf("%d", &c);
            a.insert(c);
        }
        while (B--) {
            scanf("%d", &c);
            b.insert(c);
        }

        if (a.size() < b.size()) {
            for (auto i : a) {
                if (auto search = b.find(i); search == b.end()) {
                    count++;
                }
            }
        } else {
            for (auto el : b) {
                if (auto search = a.find(el); search == a.end()) {
                    count++;
                }
            }
        }
        printf("%d\n" , count);
    }
    return 0;
}
/*
 ~ Author    : @tridib_2003
 ~ Title     : CANDY - Candy I
 ~ Link      : https://www.spoj.com/problems/CANDY/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {

    FIO;

    int n;
    cin >> n;

    while (n != -1) {

        vector<int> c(n);
        int total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
            total += c[i];
        }

        if ((total % n) == 0) {
            int d = total / n, moves = 0;
            for (int i = 0; i < n; ++i) {
                if (c[i] > d)
                    moves += (c[i] - d);
            }
            cout << moves << '\n';
        }
        else {
            cout << -1 << '\n';
        }

        cin >> n;

    }

    return 0;
}